;/* The MIT License (MIT)
; * Copyright (c) 2016 The Open-Source Community
; *
; * Permission is hereby granted, free of charge, to any person obtaining
; * a copy of this software and associated documentation files (the
; * "Software"), to deal in the Software without restriction, including
; * without limitation the rights to use, copy, modify, merge, publish,
; * distribute, sublicense, and/or sell copies of the Software, and to
; * permit persons to whom the Software is furnished to do so, subject
; * to the following conditions:
; *
; * The above copyright notice and this permission notice shall be included
; * in all copies or substantial portions of the Software.
; * 
; * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
; * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
; * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
; * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
; * DEALINGS IN THE SOFTWARE.
; */

	.cdecls C, list, "msp430.h"	; this allows us to use C headers
	
	.text						; locates code in 'text' section
	
	.global q15_mul
	.global q15_add
	.global q15_abs
	
q15_mul:
	; save r9, r10, r11
	push.w	r9
	push.w	r10
	push.w	r11
	
	clr		r9

q15_mul_check_r12:
	; check sign of r12
	bit.w	#8000h, r12
	jnc		q15_mul_check_r13
	
q15_mul_negate_r12:
	inv.w	r12
	inc.w	r12
	mov.w	#1, r9
	
	; if r12 == -32768, r12++
	mov.w	#8000h, r10
	cmp.w	r10, r12
	jne		q15_mul_check_r13
	dec.w	r12

q15_mul_check_r13:
	; check sign of r13
	bit.w	#8000h, r13
	jnc		q15_mul_positive_multiply

q15_mul_negate_r13:
	inv.w	r13
	inc.w	r13
	mov.w	#1, r10
	xor.w	r10, r9
	
	; if r13 == -32768, r13++
	mov.w	#8000h, r10
	cmp.w	r10, r13
	jne		q15_mul_positive_multiply
	dec.w	r13

q15_mul_positive_multiply:	
	; r12 -> r14
	mov.w	r12, r14
	
	; 0 -> r10, r11
	clr		r10
	clr		r11
	clr		r12
	clr		r15
	
q15_mul_b0_check:
	; if (r13 & 1h) { r14 -> r11 }
	bit.w	#0001h, r13
	jnc		q15_mul_b0_shift
	mov		r14, r11
	
q15_mul_b0_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_b1_check:
	; if (r13 & 2h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#0002h, r13
	jnc		q15_mul_b1_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_b1_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15

q15_mul_b2_check:
	; if (r13 & 4h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#0004h, r13
	jnc		q15_mul_b2_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_b2_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_b3_check:
	; if (r13 & 8h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#0008h, r13
	jnc		q15_mul_b3_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_b3_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_b4_check:
	; if (r13 & 10h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#0010h, r13
	jnc		q15_mul_b4_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_b4_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_b5_check:
	; if (r13 & 20h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#0020h, r13
	jnc		q15_mul_b5_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_b5_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_b6_check:
	; if (r13 & 40h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#0040h, r13
	jnc		q15_mul_b6_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_b6_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_b7_check:
	; if (r13 & 80h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#0080h, r13
	jnc		q15_mul_b7_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_b7_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_b8_check:
	; if (r13 & 100h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#0100h, r13
	jnc		q15_mul_b8_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_b8_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_b9_check:
	; if (r13 & 200h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#0200h, r13
	jnc		q15_mul_b9_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_b9_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_ba_check:
	; if (r13 & 400h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#0400h, r13
	jnc		q15_mul_ba_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_ba_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_bb_check:
	; if (r13 & 800h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#0800h, r13
	jnc		q15_mul_bb_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_bb_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_bc_check:
	; if (r13 & 1000h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#1000h, r13
	jnc		q15_mul_bc_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_bc_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_bd_check:
	; if (r13 & 2000h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#2000h, r13
	jnc		q15_mul_bd_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_bd_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15	
	
q15_mul_be_check:
	; if (r13 & 4000h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#4000h, r13
	jnc		q15_mul_be_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_be_shift:
	; r15:r14 << 1
	rla.w	r14
	rlc		r15
	
q15_mul_bf_check:
	; if (r13 & 8000h)
	; 	{ 
	;		r11 + r14 -> r11 
	;		r12 + r15 + c -> r12
	;	}
	bit.w	#8000h, r13
	jnc		q15_mul_bf_shift
	add.w	r14, r11
	addc.w	r15, r12

q15_mul_bf_shift:
	; r12:r11 << 1
	rla.w	r11
	rlc		r12
	
q15_mul_check_sign:
	bit.w	#1, r9
	jnc		q15_mul_end
	inv.w	r12
	inc.w	r12
	
q15_mul_end:
	; restore r10, r11
	pop.w	r11
	pop.w	r10
	pop.w	r9
	
	ret
	
	
	
q15_add:
	; if bit 15 is set, then jump to add_neg
	bit.w	#32768, r12
	jc		q15_add_neg
	
q15_add_pos:
	bit.w	#32768, r13
	jc		q15_add_pos_neg
	
q15_add_pos_pos:
	add.w	r13, r12
	jn		q15_add_pos_pos_sat
	ret

q15_add_neg:
	bit.w	#32768, r13
	jc		q15_add_neg_neg
	
q15_add_pos_neg:
	add.w	r13, r12
	ret
	
q15_add_pos_pos_sat:
	mov		#32767, r12
	ret
	
q15_add_neg_neg:
	add.w	r13, r12	
	
	; result should be negative
	bit.w	#32768, r12
	jnc		q15_add_neg_neg_sat
	ret
	
q15_add_neg_neg_sat:
	mov		#32768, r12
	ret
	
	
q15_abs:
	bit.w	#32768, r12
	jc		q15_abs_negate
	ret
	
q15_abs_negate:
	inv.w	r12
	inc.w	r12
	ret
	
	.end
	