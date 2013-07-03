CPU 686
BITS 32

%define	   DATA_REG 0x60
%define    EOI 0x20
%define    PIC1_CMD 0x20
%define    PIC2_CMD 0xA0
             
global     _scancode
global     _kbd_isr  			 
global     _b1
global     _b2
global     _b3
global     _indice          
global     _mouse_isr            

section    .data  
  _scancode  db 0              
  _b1   db 		0
  _b2	db      0
  _b3   db      0
  _indice	dw  1
     
section    .text               
_mouse_isr:                     
           push  eax           
           push  ebx                
           
		   mov bx,[_indice]
		   movzx ebx, bx
		   
		   in al,DATA_REG
		  
		  cmp ebx, 1
		  je b1
		  cmp ebx, 2
		  je b2
		  cmp ebx, 3
		  je b3
		  
	
	b1:   mov byte[_b1], al
		  jmp salta
		  
    b2:   mov byte[_b2], al
	      jmp salta
		  
	b3:   mov byte[_b3], al
		  jmp salta
		  
   salta:		
		   
		   inc   ebx	
		   cmp   ebx, 4
		   jne   fim
           mov ebx, 1
		   
		   
	fim:	mov [_indice],  ebx
			mov   al, EOI      
            out   PIC1_CMD, al
		    out   PIC2_CMD, al
	        pop   ebx
			pop   eax 
			
           iretd
END     
_kbd_isr:                      ; deve ser global para ser acedida em módulos escritos em C
           push EAX	           ; todos os registos utilizados na rotina
		   xor EAX, EAX
		   in al, DATA_REG
		   mov [_scancode], al
           mov   al, EOI       ; sinaliza EOI para o PIC-1
           out   PIC1_CMD, al
           pop   EAX            ; todos os registos guardados
           iretd
END                      