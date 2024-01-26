global _main

section .data
    filename db "Grace_kid.s", 0
    source_code db "2c =  %2$c aaa 1c= %1$s dd 3c = %3$c gg 4c %4$c aa", 0
    MODE equ 0x0601 ; O_WRONLY | O_CREAT | O_TRUNC = 0x0601 and PERM = 0644 = 0x1A4
	PERM equ 0x1A4
 
extern _dprintf, _open, _close, _exit

section .text

%macro main_func 0

_main:
	push rbx
    ; Open the file for writing
    lea rdi, [rel filename] 
	mov rsi, MODE
	mov rdx, PERM
    call _open

    mov r8, rax
    mov rdi, r8
    lea rsi, [rel source_code]
	mov r9, 10
	mov rcx, 34
    lea rdx, [rel source_code]
    call _dprintf

    mov rdi, r8
    call _close

    mov eax, 0         
    call _exit

%endmacro

main_func

