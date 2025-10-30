execute_whoami:
	push   rbp
	mov    rbp,rsp
	mov    edi,0x401258
	call   0x400370 <puts@plt>
	mov    edi,0x401275
	call   0x400370 <puts@plt>
	mov    edi,0x40128f
	call   0x400380 <system@plt>
	mov    edi,0x401296
	call   0x400370 <puts@plt>
	mov    edi,0x0
	call   0x4003b0 <exit@plt>