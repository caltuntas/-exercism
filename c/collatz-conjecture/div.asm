steps>:
1000078d0: 55                          	push	rbp
1000078d1: 48 89 e5                    	mov	rbp, rsp
1000078d4: 89 7d f8                    	mov	dword ptr [rbp - 8], edi
1000078d7: 83 7d f8 00                 	cmp	dword ptr [rbp - 8], 0
1000078db: 0f 8f 0c 00 00 00           	jg	0x1000078ed <_steps+0x1d>
1000078e1: c7 45 fc ff ff ff ff        	mov	dword ptr [rbp - 4], 4294967295
1000078e8: e9 5c 00 00 00              	jmp	0x100007949 <_steps+0x79>
1000078ed: c7 45 f4 00 00 00 00        	mov	dword ptr [rbp - 12], 0
1000078f4: 8b 45 f8                    	mov	eax, dword ptr [rbp - 8]
1000078f7: 89 45 f0                    	mov	dword ptr [rbp - 16], eax
1000078fa: 83 7d f0 01                 	cmp	dword ptr [rbp - 16], 1
1000078fe: 0f 84 3f 00 00 00           	je	0x100007943 <_steps+0x73>
100007904: 8b 45 f0                    	mov	eax, dword ptr [rbp - 16]
100007907: b9 02 00 00 00              	mov	ecx, 2
10000790c: 99                          	cdq
10000790d: f7 f9                       	idiv	ecx
10000790f: 83 fa 00                    	cmp	edx, 0
100007912: 0f 85 13 00 00 00           	jne	0x10000792b <_steps+0x5b>
100007918: 8b 45 f0                    	mov	eax, dword ptr [rbp - 16]
10000791b: b9 02 00 00 00              	mov	ecx, 2
100007920: 99                          	cdq
100007921: f7 f9                       	idiv	ecx
100007923: 89 45 f0                    	mov	dword ptr [rbp - 16], eax
100007926: e9 0a 00 00 00              	jmp	0x100007935 <_steps+0x65>
10000792b: 6b 45 f0 03                 	imul	eax, dword ptr [rbp - 16], 3
10000792f: 83 c0 01                    	add	eax, 1
100007932: 89 45 f0                    	mov	dword ptr [rbp - 16], eax
100007935: 8b 45 f4                    	mov	eax, dword ptr [rbp - 12]
100007938: 83 c0 01                    	add	eax, 1
10000793b: 89 45 f4                    	mov	dword ptr [rbp - 12], eax
10000793e: e9 b7 ff ff ff              	jmp	0x1000078fa <_steps+0x2a>
100007943: 8b 45 f4                    	mov	eax, dword ptr [rbp - 12]
100007946: 89 45 fc                    	mov	dword ptr [rbp - 4], eax
100007949: 8b 45 fc                    	mov	eax, dword ptr [rbp - 4]
10000794c: 5d                          	pop	rbp
10000794d: c3                          	ret
10000794e: 90                          	nop
10000794f: 90                          	nop
