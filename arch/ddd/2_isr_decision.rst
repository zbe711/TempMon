Direct ISR Processing
~~~~~~~~~~~~~~~~~~~~~

**Decision:** Process temperature samples directly within the ISR without using a volatile flag or main loop processing.

**Rationale:**

- **Assumptions:**

  - CPU clock frequency: 400 MHz or 500 MHz
  - Sampling frequency: 10 kHz (100 μs period)
  - ISR execution time: < 1% of ISR period

- **CPU Cycle Budget:**

  - At 400 MHz: 100 μs period = 40,000 CPU cycles available
  - At 500 MHz: 100 μs period = 50,000 CPU cycles available
  - ISR uses < 400 cycles in best case scenario.

- **Guarantees:**

  - ISR completes well before the next interrupt occurs
  - No risk of interrupt overlap or missed samples
  - Eliminates need for critical sections and volatile flags
  - Reduces code complexity and memory overhead

- **ISR Operations:**

  - ADC raw value read (~50 cycles)
  - Threshold comparison (~100 cycles)
  - LED GPIO updates (~150 cycles)
  - Total: < 400 cycles

**Alternatives Considered:**

- **Volatile flag with main loop processing:** Implemented in V1.0, please checkout the release tag.
