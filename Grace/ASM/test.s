global _main;This is my second quine in ASM
extern _dprintf
extern _open
extern _close
section .text
%macro main 0
_main:
push rbx
call open_file
mov rdi, rax
call write_file
mov eax, 0
pop rbx
ret
%endmacro
open_file:
push rbx
lea rdi, [rel filename]
mov rsi, 0x601
mov rdx, 0x1a4
call _open
pop rbx
ret
write_file:
push rbx
lea rsi, [rel code]
mov rcx, 10
mov r8, 34
lea rdx, [rel code]
call _dprintf
pop rbx
ret
main
section .data
filename db "Grace_kid.s", 0
code db "2c = %2$c 1s= |%1$s| 3c = %3$c"
