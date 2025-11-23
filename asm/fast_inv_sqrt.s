section .text
global fast_inverse_sqrt_asm

; Calculates 1/sqrt(x) using bit-level hacking
; Input: xmm0 (float)
; Output: xmm0 (float result)

fast_inverse_sqrt_asm:
    movd eax, xmm0          ; Move float bits to integer register
    mov edx, 0x5f3759df     ; The "Magic Number" constant
    shr eax, 1              ; Bitwise shift right
    sub edx, eax            ; Subtract from magic number
    movd xmm1, edx          ; Move back to float register
    
    ; One iteration of Newton's method for precision
    mulss xmm0, xmm1        ; x * y
    mulss xmm0, xmm1        ; x * y * y
    movss xmm2, [threehalfs]; Load 1.5
    subss xmm2, xmm0        ; 1.5 - (x * y * y)
    mulss xmm1, xmm2        ; y * (1.5 - (x * y * y))
    
    movaps xmm0, xmm1       ; Return result
    ret

section .data
threehalfs: dd 1.5
