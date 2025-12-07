#ifndef MOCK_H
#define MOCK_H

#if defined(__x86_64__)
static inline void __disable_irq(void)
{
    // do nothing
}
static inline void __enable_irq(void)
{
    // do nothing
}
#else
static inline void __disable_irq(void)
{
    // Change Processor State, Interrupt Disable (IRQ)
    __asm__ volatile("cpsid i" ::: "memory");
}
static inline void __enable_irq(void)
{
    // Change Processor State, Interrupt Enable (IRQ)
    __asm__ volatile("cpsie i" ::: "memory");
}
#endif

#endif

