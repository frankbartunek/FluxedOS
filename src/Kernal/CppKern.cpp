#include "CppKern.h"
#include "Kernal.h"
#include "BUILD.h"
#include "../lib/Vector/vector.h"
#include "../lib/VGA/VGA.h"
#include "../lib/VirtualConsole/VirtualConsole.h"
#include "../cpu/cpu.h"

class KernelEntry {
public:
    
    KernelEntry() {
        asm volatile("sti");
        VGA::INIT_DISPLAY();

        VGA::SET_COLOR(VGA::COLORS::GREEN, VGA::COLORS::BLACK);
        VGA::kprintf("Fluxed OS ====== BUILD %d\n", BUILD);
    }

    ~KernelEntry() {
        VGA::SET_COLOR(VGA::COLORS::RED, VGA::COLORS::BLACK);

        VGA::PRINT_STR("\nKernel Exitting...");
    }
   

    void Test() {
        VGA::SET_COLOR(VGA::COLORS::MAGENTA, VGA::COLORS::BLACK);
        VGA::kprintf("Testing VGA commands\nAll statments should be true!\n%s = %d\nYou should not see \'-\' in \'T-\eE-\eS-\eT\'\nShould be broken %t %s %d\nDONE!", "ten", 10);

        // test tripping the isr
        
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

    
    
    print_string("System stopped for: ", YELLOW, BLACK);
        
    int i = 1;
    while(1){
        i++;

        asm volatile("nop");
        
        print_hold_int( ( (i / 5000)) );
    };

    

   
    


    while(1);

}
