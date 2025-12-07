Main Loop with Volatile Flag
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Decision:** Use a volatile flag set by the ISR and processed in the main while loop for temperature monitoring.

**Rationale:**

- ISR only sets a volatile flag when DMA transfer completes, minimizing ISR execution time
- Main loop continuously checks the flag and processes temperature conversion, range evaluation, and LED updates
- Allows for future expansion of main loop functionality
- Reduces ISR complexity and execution time
- Volatile keyword ensures proper memory visibility between ISR and main loop

**Alternatives Considered:**

- **ISR-based processing:** Rejected to allow for main loop expansion and reduce ISR complexity
- **Polling without flag:** Rejected due to unnecessary CPU load when no new samples are available
