# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
# TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
# THIS ASSIGNMENT.

.file "encode.s"
.section .rodata
printf_line:
.string "Enter 4-bit key: "
.data
.align 8
.text
.globl encode
    .type encode, @function
encode:
    pushq %rbp
    movq %rsp, %rbp

    pushq %rbx
    pushq %r12                 # prepare for (param1) - cleartext_in
    pushq %r13                 # prepare for (param2) - ciphertext
    pushq %r14                 # prepare for (param3) - count
    pushq %r15                 # prepare for (temp)

    movq %rdi, %r12            # move %rdi (param1) to %r12
    movq %rsi, %r13            # move %rsi (param2) to %r13
    movq %rdx, %r14            # move %rdx (param3) to %r14
    # xor will be used for wipe the reg
    xorq %rcx, %rcx
    xorq %rbx, %rbx
    
    movq $printf_line, %rdi    # promote print_line
    xorq %rax, %rax            # required value in %rax says Linux System V ABI
    call printf                # call printf

loop1:                         # loop to convert 4-bit to 8-bit
    xorq %rax, %rax
    call getchar
    subq $48, %rax             # 0 -> 48, 1 -> 49
    je loop2
    orq $0x88, %rbx
loop2:                         # loop to convert 4-bit to 8-bit
    xorq %rax, %rax
    call getchar
    subq $48, %rax             # 0 -> 48, 1 -> 49
    je loop3
    orq $0x44, %rbx
loop3:                         # loop to convert 4-bit to 8-bit
    xorq %rax, %rax
    call getchar
    subq $48, %rax             # 0 -> 48, 1 -> 49
    je loop4
    orq $0x22, %rbx
loop4:                         # loop to convert 4-bit to 8-bit
    xorq %rax, %rax
    call getchar
    subq $48, %rax             # 0 -> 48, 1 -> 49
    je pre_enc
    orq $0x11, %rbx

pre_enc:
    movq %r12, %rdi            # restore the (param1) - cleartext_in from %r12
    movq %r13, %rsi            # restore the (param2) - ciphertext from %r13
    xorq %r12, %r12            # address counter
enc:
    decq %r14                  # (param3) - count
    js exit
    # x(a, b, c) -> a + b * c + x
    movq (%rdi, %r12, 1), %r13
    xorb %bl, %r13b
    movb %r13b, (%rsi, %r12, 1)
    incb %r12b
    jmp enc

exit:
    popq %r15                  # restore for (temp)
    popq %r14                  # restore for (param3)
    popq %r13                  # restore for (param2)
    popq %r12                  # restore for (param1)
    popq %rbx                  # restore for %rbx

    leave
    ret
.size encode, .-encode
