section .text
	global	main
	extern	printf
main:
	mov	edi, msg
	mov	edx, 0
	call	printf

section	.data
	msg db 'Hello, Holberton\n', 0xa, 0
