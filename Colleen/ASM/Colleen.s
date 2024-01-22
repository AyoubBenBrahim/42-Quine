global _main
extern _printf
extern _exit

; outside comment

section .data
code db "global _main%1$cextern _printf%1$cextern _exit%1$c%1$c; outside comment%1$c%1$csection .data%1$ccode db %2$c%3$s%2$c%1$c%1$csection .text%1$c%1$c_main:%1$c	push rbp%1$c	; inside comment%1$c	lea rdi, [rel code]%1$c	mov rsi, 10%1$c	mov rdx, 34%1$c	mov rcx, rdi%1$c	call _printf%1$c	mov rdi, 0%1$c	call _exit%1$c	pop rbp%1$c"

section .text

_main:
	push rbp
	; inside comment
	lea rdi, [rel code]
	mov rsi, 10
	mov rdx, 34
	mov rcx, rdi
	call _printf
	mov rdi, 0
	call _exit
	pop rbp
