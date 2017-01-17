enter_pmode:

bits 16

xchg bx, bx

cli						; Disable interrupts

lgdt [GDT]				; Load the GDT

mov eax, cr0			; Enable bit 0 of cr0 and enter protected mode
or eax, 00000001b
mov cr0, eax

jmp 0x08:.pmode

.pmode:					; Now in 32-bit protected mode

bits 32

mov ax, 0x10			; Descriptor 2 (kernel data)
mov ds, ax
mov es, ax
mov fs, ax
mov gs, ax
mov ss, ax

xchg bx, bx

ret

bits 16