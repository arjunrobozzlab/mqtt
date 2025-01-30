/* Linker script for N32G430 microcontroller */

/* Define memory regions based on the N32G430 datasheet */
MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K  /* Adjust length as per your chip */
  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 32K   /* Adjust length as per your chip */
}

/* Entry point of the program */
ENTRY(Reset_Handler)

/* Sections */
SECTIONS
{
  /* Place the vector table at the beginning of FLASH */
  .isr_vector :
  {
    KEEP(*(.isr_vector))
  } > FLASH

  /* Place read-only data in FLASH */
  .text :
  {
    *(.text*)
    *(.rodata*)
    KEEP(*(.init))
    KEEP(*(.fini))
  } > FLASH

  /* Place the ARM exception handling sections in FLASH */
  .ARM.extab :
  {
    *(.ARM.extab* .gnu.linkonce.armextab.*)
  } > FLASH

  .ARM :
  {
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
  } > FLASH

  /* Initialized data sections */
  .data :
  {
    _sdata = .;
    *(.data*)
    _edata = .;
  } > RAM AT > FLASH

  /* Uninitialized data (bss) */
  .bss :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > RAM

  /* Stack section */
  .stack :
  {
    . = ALIGN(8);
    _stack_top = .;
    . += 4K; /* Adjust stack size if needed */
    _stack_bottom = .;
  } > RAM

  /* Heap section */
  .heap :
  {
    . = ALIGN(8);
    _heap_start = .;
    . += 4K; /* Adjust heap size if needed */
    _heap_end = .;
  } > RAM

  /* End of the program */
  _end = .;
}

/* Provide symbols for startup assembly */
PROVIDE(_sdata = _sdata);
PROVIDE(_edata = _edata);
PROVIDE(_sbss = _sbss);
PROVIDE(_ebss = _ebss);
PROVIDE(_stack_top = _stack_top);
PROVIDE(_stack_bottom = _stack_bottom);
PROVIDE(_heap_start = _heap_start);
PROVIDE(_heap_end = _heap_end);