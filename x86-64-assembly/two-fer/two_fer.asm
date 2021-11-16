default rel
section .data
    string1 db "One for ", 0
    string2 db ", one for me.", 0
    string3 db "you", 0

section .bss
    output: resb 50

section .text
    global two_fer

_strcat:
    xor rcx,rcx

    mov rdx,rdi
    call _strlen
    lea rdi,[rdi + rax]
    mov rdx,rsi
    call _strlen
    mov rcx, rax
    rep movsb
    mov byte[rdi], 0

    mov rax, rdi
    ret

_strlen:
    xor rbx,rbx
_loop:
    cmp byte[rdx], 0
    jz _end
    inc rbx
    inc rdx
    jmp _loop
_end:
    mov rax,rbx
    ret
_you:
    lea rdi, [string3]
two_fer:
    xor rdx,rdx
    xor rax,rax
    xor rbx,rbx
    xor rcx,rcx

    mov byte[rsi], 0
    
    cmp rdi, 0
    jz _you

    mov r8, rdi
    mov r9, rsi

    xor rsi,rsi
    xor rdi,rdi

    lea rsi,[string1]
    mov rdi, r9
    call _strcat

    mov rsi,r8
    mov rdi, r9
    call _strcat

    lea rsi,[string2]
    mov rdi, r9
    call _strcat
     
    ret
