DMA for ADC Data Transfer
~~~~~~~~~~~~~~~~~~~~~~~~~~

**Decision:** Use DMA to transfer ADC conversion results from the ADC result register to memory.

**Alternatives Considered:**

- **Polling:** Rejected due to 100% CPU load blocking all other operations
- **ADC with CPU reads:** Causes 100,000 interruptions per second with context switching overhead (stack/unstack registers)
- **ADC with DMA:** Selected for zero CPU load during transfer and minimal jitter

**Comparison:**

.. list-table:: ADC Data Transfer Methods
   :header-rows: 1
   :widths: 20 20 20 20 20

   * - Method
     - CPU Load
     - Jitter
     - Complexity
     - Best For
   * - Polling
     - High (100% blocked)
     - Low
     - Very Low
     - Startup checks
   * - Interrupt (CPU read)
     - Medium (per sample)
     - Medium (depends on other IRQs)
     - Low
     - Low-speed sensors (<10kHz)
   * - DMA
     - Very Low
     - Zero
     - High
     - High-speed data (>100kHz)
