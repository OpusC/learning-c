main:
	push   rbp
	mov    rbp,rsp
	mov    edi,0x401550
	call   0x400370 <puts@plt>
	mov    edi,0x401578
	call   0x400370 <puts@plt>
	mov    edi,0x4015d0
	call   0x400370 <puts@plt>
	mov    edi,0x401630
	call   0x400370 <puts@plt>
	mov    edi,0x401648
	call   0x400370 <puts@plt>
	mov    edi,0x4016b0
	call   0x400370 <puts@plt>
	mov    edi,0x401708
	call   0x400370 <puts@plt>
	mov    edi,0x401758
	call   0x400370 <puts@plt>
	mov    eax,0x0
	call   0x4004dc <vulnerable_function>
	mov    edi,0x4017b0
	call   0x400370 <puts@plt>
	mov    eax,0x0
	pop    rbp
	ret