CPU 686
BITS 32

%define    EOI 20h             ; define EOI como valendo 0x20
%define    PIC1_CMD 20h
%define    DATA_REG 60h
global     _scancode
global     _kbd_isr  

section    .data               ; .data � a zona de dados inicializados
_scancode  db 0                ; declara vari�vel nome_var com 4 bytes (dd) e inicializa-a com 0

section    .text               ; .text � a zona de c�digo
_kbd_isr:                      ; deve ser global para ser acedida em m�dulos escritos em C
           push EAX	           ; todos os registos utilizados na rotina
		   xor EAX, EAX
		   in al, DATA_REG
		   mov [_scancode], al
           mov   al, EOI       ; sinaliza EOI para o PIC-1
           out   PIC1_CMD, al
           pop   EAX            ; todos os registos guardados
           iretd
END                            ; fim de c�digo fonte assembly
