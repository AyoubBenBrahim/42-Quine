global _main

section .data
	filename db "Grace_kid.s", 0
	source_code db "global _main%4$c%4$csection .data%4$c	filename db %2$cGrace_kid.s%2$c, 0%4$c	source_code db %2$c%1$s%2$c, 0%4$c	MODE equ 0x0601 ; O_WRONLY | O_CREAT | O_TRUNC = 0x0601 and PERM = 0644 = 0x1A4%4$c	PERM equ 0x1A4%4$c%4$cextern _dprintf, _open, _close, _exit%4$c%4$csection .text%4$c%4$c%%macro main_func 0%4$c%4$c_main:%4$c	push rbx%4$c	; Open the file for writing%4$c	lea rdi, [rel filename]%4$c	mov rsi, MODE%4$c	mov rdx, PERM%4$c	call _open%4$c	mov r8, rax%4$c%4$c	mov rdi, r8%4$c	lea rsi, [rel source_code]%4$c	mov r9, 10%4$c	mov rcx, 34%4$c	lea rdx, [rel source_code]%4$c	call _dprintf%4$c%4$c	mov rdi, r8%4$c	call _close%4$c%4$c	mov eax, 0%4$c	call _exit%4$c%4$c%%endmacro%4$c%4$cmain_func%4$c", 0
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
