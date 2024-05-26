steps>:
1000078d0: 55                          	push	rbp
1000078d1: 48 89 e5                    	mov	rbp, rsp
1000078d4: 89 7d f8                    	mov	dword ptr [rbp - 8], edi
1000078d7: 83 7d f8 00                 	cmp	dword ptr [rbp - 8], 0
1000078db: 0f 8f 0c 00 00 00           	jg	0x1000078ed <_steps+0x1d>
1000078e1: c7 45 fc ff ff ff ff        	mov	dword ptr [rbp - 4], 4294967295
1000078e8: e9 52 00 00 00              	jmp	0x10000793f <_steps+0x6f>
1000078ed: c7 45 f4 00 00 00 00        	mov	dword ptr [rbp - 12], 0
1000078f4: 8b 45 f8                    	mov	eax, dword ptr [rbp - 8]
1000078f7: 89 45 f0                    	mov	dword ptr [rbp - 16], eax
1000078fa: 83 7d f0 01                 	cmp	dword ptr [rbp - 16], 1
1000078fe: 0f 84 35 00 00 00           	je	0x100007939 <_steps+0x69>
100007904: 8b 45 f0                    	mov	eax, dword ptr [rbp - 16]
100007907: 83 e0 01                    	and	eax, 1
10000790a: 83 f8 00                    	cmp	eax, 0
10000790d: 0f 85 0e 00 00 00           	jne	0x100007921 <_steps+0x51>
100007913: 8b 45 f0                    	mov	eax, dword ptr [rbp - 16]
100007916: c1 f8 01                    	sar	eax, 1
100007919: 89 45 f0                    	mov	dword ptr [rbp - 16], eax
10000791c: e9 0a 00 00 00              	jmp	0x10000792b <_steps+0x5b>
100007921: 6b 45 f0 03                 	imul	eax, dword ptr [rbp - 16], 3
100007925: 83 c0 01                    	add	eax, 1
100007928: 89 45 f0                    	mov	dword ptr [rbp - 16], eax
10000792b: 8b 45 f4                    	mov	eax, dword ptr [rbp - 12]
10000792e: 83 c0 01                    	add	eax, 1
100007931: 89 45 f4                    	mov	dword ptr [rbp - 12], eax
100007934: e9 c1 ff ff ff              	jmp	0x1000078fa <_steps+0x2a>
100007939: 8b 45 f4                    	mov	eax, dword ptr [rbp - 12]
10000793c: 89 45 fc                    	mov	dword ptr [rbp - 4], eax
10000793f: 8b 45 fc                    	mov	eax, dword ptr [rbp - 4]
100007942: 5d                          	pop	rbp
100007943: c3                          	ret
100007944: 90                          	nop
100007945: 90                          	nop
100007946: 90                          	nop
100007947: 90                          	nop
100007948: 90                          	nop
100007949: 90                          	nop
10000794a: 90                          	nop
10000794b: 90                          	nop
10000794c: 90                          	nop
10000794d: 90                          	nop
10000794e: 90                          	nop
10000794f: 90                          	nop
