.global reset @to be seen by the linker

reset:
    ldr sp, =stack_top @load stack pointer at ths address
    bl main

stop: 
    b stop