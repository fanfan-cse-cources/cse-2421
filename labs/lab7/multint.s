#
# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
# TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
# THIS ASSIGNMENT.
#

.file "multint.s"
# Assembler directives to allocate storage for static array
.section .rodata
.data
.globl multint
    .type multint, @function
.text

# logic here
# for (m = x; m >= -x ; m--)
# {
#     for(n = y; n >= -y ; n--)
#     {
#         (values)->z = o;
#         (values)->x = m;
#         o = 9 * m * m + 7 * m * m * n * n + 3 * n * n;
#         (values)->y = n;
#         values++;
#     }
# }

multint:
    push %rbp           # save caller's %rbp
    movq %rsp, %rbp     # copy %rsp to %rbp so our stack frame is ready to use

                # %rdi contains high x value
                # %rsi contains high y value
                    # use %rdx for z variable
    pushq %r12
    pushq %r13
    # Calculate z = 9x^2+7x^2y^2+3y^2 over all values x/y
    # between 0 and high values passed
    movl %edi, %r10d     # move x to %r10d
    negl %r10d           # -x
    movl %esi, %r9d      # move y to %r9d
    movl %esi, %r8d      # move y to %r8d
    negl %r8d            # -y

    incl %edi            # going to decq first so inc here so we calculate w/x = high value
Calc_loop_x:
    decl %edi            # decrement x
    cmpl %r10d, %edi     # compare current x and -x
    jl Calc_exit
    movl %edi, %r11d     # make a copy of x
    imull %r11d, %r11d   # x^2 for 4-byte
    movl %r9d, %esi      # set %esi back to high y value
Calc_loop_y:
    movl %edi, 4(%rdx)   # put x into structure
    movl %esi, 8(%rdx)   # put y into structure
    pushq %rdx           # push %rdx to stack

    xorl %ecx, %ecx      # clean %ecx up
    addl %r11d, %ecx     # x^2 into result
    movl %esi, %r12d     # make a copy of y
    imull %r12d, %r12d   # y^2 for 4-byte
    movl %r12d, %r13d    # make a copy of y^2

    movl %r11d, %eax     # x^2 is ready to multply
    imull %eax, %r12d    # %r12d = x^2y^2

    # Calculate z = 9x^2+7x^2y^2+3y^2 over all values x/y
    leal (%ecx, %ecx, 8), %ecx              # %ecx = 9x^2
    leal (%r13d, %r13d, 2), %r13d           # %r13d = 3y^2
    addl %r13d, %ecx                        # %ecx = 9x^2+3y^2
    addl %r12d, %ecx                        # %ecx = 9x^2+3y^2+x^2y^2
    leal (%r12d, %r12d, 1), %r12d           # %r12d = 2x^2y^2
    addl %r12d, %ecx                        # %ecx = 9x^2+3y^2+3x^2y^2
    leal (%r12d, %r12d, 1), %r12d           # %r12d = 4x^2y^2
    addl %r12d, %ecx                        # %ecx = 9x^2+3y^2+7x^2y^2

    popq %rdx            # get %rdx from stack
    movl %ecx, (%rdx)    # put z into structure

    addq $12, %rdx       # jump to next structure memory space

    decl %esi
    cmpl %r8d, %esi
    jl Calc_loop_x
    jmp Calc_loop_y
Calc_exit:
    popq %r13
    popq %r12
    popq %rbp
    ret
.size multint, .-multint
