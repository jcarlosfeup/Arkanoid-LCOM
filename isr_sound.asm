CPU 686
BITS 32

%define    PIC1_CMD 20h
%define    EOI 20h             ; define EOI como valendo 0x20
global     _millis              ; declara nome_var como acess�vel a m�dulos escritos em C
global     _t0_isr             ; o handler tamb�m deve ser global, para ser instalado

section    .data               ; .data � a zona de dados inicializados
_millis  dd 0                   ; declara vari�vel nome_var com 4 bytes (dd) e inicializa-a com 0

section    .text               ; .text � a zona de c�digo
_t0_isr:                       ; deve ser global para ser acedida em m�dulos escritos em C
           push  eax           ; todos os registos utilizados na rotina
           inc dword[_millis]   ; instru��es da rotina
           mov   al, EOI       ; sinaliza EOI para o PIC-1
           out   PIC1_CMD, al
           pop   eax           ; todos os registos guardados
           iretd
END                            ; fim de c�digo fonte assembly