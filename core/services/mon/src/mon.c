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

#define HW_REV_B_RESOLUTION_FACTOR 10

#define GPIO_PIN_LED_GREEN  0
#define GPIO_PIN_LED_YELLOW 1
#define GPIO_PIN_LED_RED    2

typedef enum
{
    MON_LED_GREEN = 0,
    MON_LED_YELLOW = 1,
    MON_LED_RED = 2
} mon_led_color_t;

static uint16_t g_threshold_warning = DEFAULT_THRESHOLD_WARNING;
static uint16_t g_threshold_critical_high = DEFAULT_THRESHOLD_CRITICAL_HIGH;
static uint16_t g_threshold_critical_low = DEFAULT_THRESHOLD_CRITICAL_LOW;

static void normalize_thresholds(hw_revision_t hw_revision)
{
    if (hw_revision == HW_REV_B)
    {
        g_threshold_warning *= HW_REV_B_RESOLUTION_FACTOR;
        g_threshold_critical_high *= HW_REV_B_RESOLUTION_FACTOR;
        g_threshold_critical_low *= HW_REV_B_RESOLUTION_FACTOR;
    }
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
            normalize_thresholds(hw_revision);
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
    uint16_t adc_raw = adc_read_raw(ADC_CHANNEL_TEMP);
    mon_led_color_t led_color = MON_LED_GREEN;
    
    if (adc_raw < g_threshold_critical_low || adc_raw >= g_threshold_critical_high)
    {
        led_color = MON_LED_RED;
    }
    else if (adc_raw >= g_threshold_warning)
    {
        led_color = MON_LED_YELLOW;
    }
    else
    {
        led_color = MON_LED_GREEN;
    }

    printf("ADC raw: %d, LED color: %d\n", adc_raw, led_color);
    
    mon_update_leds(led_color);
}
