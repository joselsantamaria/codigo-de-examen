    .intel_syntax noprefix

    .section .rodata
fmt_in:     .string "%ld"
fmt_sum:    .string "Sum: %ld\n"
fmt_max:    .string "Max: %ld (index %ld)\n"
msg_empty:  .string "Empty array\n"

    .bss
    .align 8
n:      .skip 8             # number of elements
vec:    .skip 8000          # 1000 64-bit integers

    .text
    .globl main
main:
    push rbp                # rsp is now 16-byte aligned
    mov rbp, rsp
    push rbx                # 4 pushes of 8 bytes = 32 bytes:
    push r12                # 16-byte alignment is preserved
    push r13
    push r14

    # scanf("%ld", &n)
    lea rdi, [rip + fmt_in]
    lea rsi, [rip + n]
    xor eax, eax
    call scanf
    cmp eax, 1
    jne empty_vec
    mov rbx, [rip + n]      # rbx = n
    test rbx, rbx
    jle empty_vec

    # Read loop: for (i = 0; i < n; i++) scanf("%ld", &vec[i])
    xor r12d, r12d          # r12 = i = 0
read_loop:
    cmp r12, rbx
    jge end_read
    lea rdi, [rip + fmt_in]
    lea rax, [rip + vec]
    lea rsi, [rax + r12*8]  # rsi = &vec[i]
    xor eax, eax
    call scanf
    inc r12
    jmp read_loop
end_read:

    # Scan loop: sum and maximum
    lea r14, [rip + vec]    # r14 = &vec[0]
    mov r12, [r14]          # sum = vec[0]
    mov r13, r12            # max = vec[0]
    xor edx, edx            # maxidx = 0
    mov ecx, 1              # i = 1
scan_loop:
    cmp rcx, rbx
    jge end_scan
    mov rax, [r14 + rcx*8]  # rax = vec[i]
    add r12, rax            # sum += vec[i]
    cmp rax, r13
    jle no_max              # signed; strict: keeps first occurrence
    mov r13, rax            # max = vec[i]
    mov rdx, rcx            # maxidx = i
no_max:
    inc rcx
    jmp scan_loop
end_scan:
    mov r14, rdx            # maxidx into a register that survives printf

    # printf("Sum: %ld\n", sum)
    lea rdi, [rip + fmt_sum]
    mov rsi, r12
    xor eax, eax
    call printf

    # printf("Max: %ld (index %ld)\n", max, maxidx)
    lea rdi, [rip + fmt_max]
    mov rsi, r13
    mov rdx, r14
    xor eax, eax
    call printf
    jmp done

empty_vec:
    lea rdi, [rip + msg_empty]
    xor eax, eax
    call printf

done:
    xor eax, eax            # return 0
    pop r14
    pop r13
    pop r12
    pop rbx
    pop rbp
    ret

    .section .note.GNU-stack,"",@progbits
