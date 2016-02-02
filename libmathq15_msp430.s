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
	
	.global q15_add
	
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
	
	
	
	
	
	.end
	