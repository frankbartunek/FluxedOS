#include "../lib/Term/Term.h"
#include "idt.h"


//define a structure for the IDT entry
struct idt_entry
{
    unsigned short base_lo;
    unsigned short sel; 
    unsigned char always0; 
    unsigned char flags; 
    unsigned short base_hi;
} __attribute__((packed));


struct idt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));


struct idt_entry idt[256];

struct idt_ptr idtp;

//we call the following function in boot.asm
extern void load_idt();

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags){

    idt[num].base_lo = (base & 0xFFFF);
    idt[num].base_hi = (base >> 16) & 0xFFFF;


    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
}


void idt_install(){
    print_string("IDT -->", WHITE, BLACK);

    idtp.limit = (sizeof(struct idt_entry)*256)-1;
    idtp.base = (unsigned int)&idt; 

    
    load_idt();
    print_string("OK", GREEN, BLACK);
    print_new_line();

}
