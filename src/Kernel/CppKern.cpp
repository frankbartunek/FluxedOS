#include "CppKern.h"
#include "Kernel.h"
#include "BUILD.h"
#include "../lib/Vector/vector.h"
#include "../lib/VirtualConsole/VirtualConsole.h"
#include "../cpu/cpu.h"
#include "../lib/mem/mem.h"
#include "../lib/core/core.h"
#include "../lib/IO/ide.h"
#include "../cpu/pic.h"
#include "../lib/hal/hal.h"
#include "../lib/VGA/VGA.h"

class KernelEntry {
public:
    
    KernelEntry() {
        asm volatile("sti");
        VGA::INIT_DISPLAY();

        VGA::SET_COLOR(VGA::COLORS::WHITE, VGA::COLORS::BLACK);

        gdt_install();
        idt_install();
        isr_install();
        irq_install();
        pic_init();

        VGA::SET_COLOR(VGA::COLORS::GREEN, VGA::COLORS::BLACK);


        VGA::kprintf("Fluxed OS ====== BUILD %d", BUILD);
        VGA::PRINT_STR("Memory : ");
        VGA::PRINT_INT(Getmemory());
        VGA::PRINT_STR("\n");
        
        //enable the interrupts
        Vasm("sti");
       //pic_send(10);
    }

    ~KernelEntry() {
        VGA::SET_COLOR(VGA::COLORS::RED, VGA::COLORS::BLACK);

        VGA::PRINT_STR("\nKernel Exitting...");
    }
   

    void Test() {
        VGA::SET_COLOR(VGA::COLORS::MAGENTA, VGA::COLORS::BLACK);
        VGA::kprintf("Testing VGA commands\nAll statments should be true!\n%s = %d\nYou should not see \'-\' in \'T-\eE-\eS-\eT\'\nShould be broken %t %s %d\nDONE!", "ten", 10);

        // test tripping the isr
        //asm volatile ("int $0x01");
        
    }

    void kern() {
        VGA::SET_COLOR(VGA::COLORS::WHITE, VGA::COLORS::BLACK);
        VirtualConsole console;

        console.Handle();
        
        
        //VGA::PRINT_STR(">\n\n\n\n\n\n>\n>\nline\n>test\n>wut\nthis is a lot of printing on this line oh yea");

        

    }
};

int KernStart() {
    {
        KernelEntry krnl;

        krnl.Test();
        krnl.kern();
    }

    panic("Kernel should not quit!");
}
