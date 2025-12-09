#include "mon.h"
#include "adc.h"
#include "gpio.h"
#include "nvm.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define DEFAULT_THRESHOLD_WARNING 85
#define DEFAULT_THRESHOLD_CRITICAL_HIGH 105
#define DEFAULT_THRESHOLD_CRITICAL_LOW 5

#define HW_REV_A_RESOLUTION_FACTOR 1
#define HW_REV_B_RESOLUTION_FACTOR 10

#define HW_REV_A_TEMPERATURE_CELSIUS_MIN -40
#define HW_REV_A_TEMPERATURE_CELSIUS_MAX 140

#define HW_REV_B_TEMPERATURE_CELSIUS_MIN -50
#define HW_REV_B_TEMPERATURE_CELSIUS_MAX 150

#define GPIO_PIN_LED_GREEN  0
#define GPIO_PIN_LED_YELLOW 1
#define GPIO_PIN_LED_RED    2

typedef enum
{
    MON_LED_GREEN = 0,
    MON_LED_YELLOW = 1,
    MON_LED_RED = 2
} mon_led_color_t;

static int32_t g_threshold_warning = DEFAULT_THRESHOLD_WARNING;
static int32_t g_threshold_critical_high = DEFAULT_THRESHOLD_CRITICAL_HIGH;
static int32_t g_threshold_critical_low = DEFAULT_THRESHOLD_CRITICAL_LOW;

static void set_thresholds(hw_revision_t hw_revision)
{
    int32_t factor = 0;
    int32_t temp_min = 0;

    if (hw_revision == HW_REV_B)
    {
        factor   = HW_REV_B_RESOLUTION_FACTOR;
        temp_min = HW_REV_B_TEMPERATURE_CELSIUS_MIN;
    }
    else
    {
        factor   = HW_REV_A_RESOLUTION_FACTOR;
        temp_min = HW_REV_A_TEMPERATURE_CELSIUS_MIN;
    }

    const int32_t adc_offset = (-temp_min) * factor;

    g_threshold_warning       = g_threshold_warning       * factor + adc_offset;
    g_threshold_critical_high = g_threshold_critical_high * factor + adc_offset;
    g_threshold_critical_low  = g_threshold_critical_low  * factor + adc_offset;
}



void mon_init(void)
{
    gpio_init();
    
    hw_config_block_t config;
    bool retval = nvm_read(NVM_BLOCK_HW_CONFIG, (void*)&config, sizeof(hw_config_block_t));

    if (false != retval)
    {
        hw_revision_t hw_revision = config.cfg.revision;
        
        if (hw_revision == HW_REV_A || hw_revision == HW_REV_B)
        {
            set_thresholds(hw_revision);
        }
    }
    else
    {
        // Handle error: NVM read failed
        // TODO: Clarify requirements - should we fail-safe to HW_REV_A or HW_REV_B?
    }
}

static inline void mon_update_leds(mon_led_color_t color)
{
    gpio_set(GPIO_PIN_LED_GREEN, (color == MON_LED_GREEN));
    gpio_set(GPIO_PIN_LED_YELLOW, (color == MON_LED_YELLOW));
    gpio_set(GPIO_PIN_LED_RED, (color == MON_LED_RED));
}

void mon_process_sample(void)
{
    int32_t adc_raw = adc_read_raw(ADC_CHANNEL_TEMP);

    mon_led_color_t led_color = MON_LED_GREEN;

    if (adc_raw < g_threshold_critical_low || adc_raw >= g_threshold_critical_high)
    {
        led_color = MON_LED_RED;
    }
    else if (adc_raw >= g_threshold_warning)
    {
        led_color = MON_LED_YELLOW;
    }

    printf("ADC raw: %ld, LED color: %d\n", (long)adc_raw, led_color);

    mon_update_leds(led_color);
}
