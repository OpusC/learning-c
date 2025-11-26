vulnerable_function:
	push   rbp
	mov    rbp,rsp
	sub    rsp,0x50
	mov    rax,QWORD PTR [rbp+0x8]
	mov    QWORD PTR [rbp-0x8],rax
	mov    edi,0x4012ad
	mov    eax,0x0
	call   0x400390 <printf@plt>
	mov    edi,0x4012b8
	call   0x400370 <puts@plt>
	lea    rax,[rbp-0x50]
	mov    rsi,rax
	mov    edi,0x401350
	mov    eax,0x0
	call   0x400390 <printf@plt>
	mov    esi,0x4004dc
	mov    edi,0x401380
	mov    eax,0x0
	call   0x400390 <printf@plt>
	mov    esi,0x4004a6
	mov    edi,0x4013b8
	mov    eax,0x0
	call   0x400390 <printf@plt>
	mov    rax,QWORD PTR [rbp-0x8]
	mov    rsi,rax
	mov    edi,0x4013f0
	mov    eax,0x0
	call   0x400390 <printf@plt>
	mov    edi,0x401428
	call   0x400370 <puts@plt>
	mov    edi,0x4014bf
	mov    eax,0x0
	call   0x400390 <printf@plt>
	mov    edi,0x4014c8
	call   0x400370 <puts@plt>
	lea    rax,[rbp-0x50]
	mov    rdi,rax
	call   0x4003a0 <gets@plt>
	lea    rax,[rbp-0x50]
	mov    rsi,rax
	mov    edi,0x401501
	mov    eax,0x0
	call   0x400390 <printf@plt>
	mov    edi,0x401518
	call   0x400370 <puts@plt>
	nop
	leave
	ret