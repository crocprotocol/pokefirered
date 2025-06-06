    .include "MPlayDef.s"

	.equ	se_lisa_grp, voicegroup191
	.equ	se_lisa_pri, 5
	.equ	se_lisa_rev, 0
	.equ	se_lisa_mvl, 127
	.equ	se_lisa_key, 0
	.equ	se_lisa_tbs, 1
	.equ	se_lisa_exg, 0
	.equ	se_lisa_cmp, 1

	.section .rodata
	.global	se_lisa
	.align	2

@********************** Track  1 **********************@

se_lisa_1:
	.byte	KEYSH , se_lisa_key+0
	.byte	TEMPO , 100*se_lisa_tbs/2
	.byte		VOICE , 3
	.byte		VOL   , 90*se_lisa_mvl/mxv
	.byte		TIE   , Cn3 , v064
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		EOT
	.byte	FINE

@******************************************************@
	.align	2

se_lisa:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_lisa_pri	@ Priority
	.byte	se_lisa_rev	@ Reverb.

	.word	se_lisa_grp

	.word	se_lisa_1

	.end