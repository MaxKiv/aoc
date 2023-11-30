	.text
	.file	"1.c"
	.file	0 "/home/max/git/aoc/2022/1" "1.c" md5 0xbd8fb72064943d98c94c61fc3ca2317a
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
.Lfunc_begin0:
	.file	1 "1.c"
	.loc	1 5 0                           # 1.c:5:0
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$304, %rsp                      # imm = 0x130
	movl	$0, -4(%rbp)
.Ltmp0:
	.loc	1 6 8 prologue_end              # 1.c:6:8
	movq	$0, -16(%rbp)
	.loc	1 7 8                           # 1.c:7:8
	movq	$0, -24(%rbp)
	.loc	1 10 15                         # 1.c:10:15
	leaq	.L.str(%rip), %rax
	movq	%rax, -32(%rbp)
	.loc	1 11 21                         # 1.c:11:21
	movq	-32(%rbp), %rdi
	.loc	1 11 15 is_stmt 0               # 1.c:11:15
	leaq	.L.str.1(%rip), %rsi
	callq	fopen@PLT
	.loc	1 11 9                          # 1.c:11:9
	movq	%rax, -40(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	.loc	1 13 16 is_stmt 1               # 1.c:13:16
	leaq	-304(%rbp), %rdi
	.loc	1 13 27 is_stmt 0               # 1.c:13:27
	movq	-40(%rbp), %rdx
	.loc	1 13 10                         # 1.c:13:10
	movl	$255, %esi
	callq	fgets@PLT
	.loc	1 13 32                         # 1.c:13:32
	cmpq	$0, %rax
	.loc	1 13 3                          # 1.c:13:3
	je	.LBB0_8
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
.Ltmp1:
	.loc	1 15 16 is_stmt 1               # 1.c:15:16
	leaq	-304(%rbp), %rdi
	.loc	1 15 9 is_stmt 0                # 1.c:15:9
	leaq	.L.str.2(%rip), %rsi
	callq	strcmp@PLT
	.loc	1 15 28                         # 1.c:15:28
	cmpl	$0, %eax
.Ltmp2:
	.loc	1 15 9                          # 1.c:15:9
	jne	.LBB0_4
# %bb.3:                                #   in Loop: Header=BB0_1 Depth=1
.Ltmp3:
	.loc	1 17 24 is_stmt 1               # 1.c:17:24
	movq	$0, -24(%rbp)
	.loc	1 18 5                          # 1.c:18:5
	jmp	.LBB0_7
.Ltmp4:
.LBB0_4:                                #   in Loop: Header=BB0_1 Depth=1
	.loc	1 19 34                         # 1.c:19:34
	leaq	-304(%rbp), %rdi
	.loc	1 19 27 is_stmt 0               # 1.c:19:27
	xorl	%eax, %eax
	movl	%eax, %esi
	movl	$10, %edx
	callq	strtol@PLT
	.loc	1 19 24                         # 1.c:19:24
	addq	-24(%rbp), %rax
	movq	%rax, -24(%rbp)
.Ltmp5:
	.loc	1 20 11 is_stmt 1               # 1.c:20:11
	movq	-24(%rbp), %rax
	.loc	1 20 28 is_stmt 0               # 1.c:20:28
	cmpq	-16(%rbp), %rax
.Ltmp6:
	.loc	1 20 11                         # 1.c:20:11
	jle	.LBB0_6
# %bb.5:                                #   in Loop: Header=BB0_1 Depth=1
.Ltmp7:
	.loc	1 21 24 is_stmt 1               # 1.c:21:24
	movq	-24(%rbp), %rax
	.loc	1 21 22 is_stmt 0               # 1.c:21:22
	movq	%rax, -16(%rbp)
.Ltmp8:
.LBB0_6:                                #   in Loop: Header=BB0_1 Depth=1
	.loc	1 0 22                          # 1.c:0:22
	jmp	.LBB0_7
.LBB0_7:                                #   in Loop: Header=BB0_1 Depth=1
	.loc	1 13 3 is_stmt 1                # 1.c:13:3
	jmp	.LBB0_1
.LBB0_8:
	.loc	1 26 3                          # 1.c:26:3
	leaq	.L.str.3(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	.loc	1 27 17                         # 1.c:27:17
	movq	-16(%rbp), %rsi
	.loc	1 27 3 is_stmt 0                # 1.c:27:3
	leaq	.L.str.4(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	.loc	1 28 1 is_stmt 1                # 1.c:28:1
	movl	-4(%rbp), %eax
	addq	$304, %rsp                      # imm = 0x130
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Ltmp9:
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"input"
	.size	.L.str, 6

	.type	.L.str.1,@object                # @.str.1
.L.str.1:
	.asciz	"r"
	.size	.L.str.1, 2

	.type	.L.str.2,@object                # @.str.2
.L.str.2:
	.asciz	"\n"
	.size	.L.str.2, 2

	.type	.L.str.3,@object                # @.str.3
.L.str.3:
	.asciz	"\n***************** A *****************\n"
	.size	.L.str.3, 40

	.type	.L.str.4,@object                # @.str.4
.L.str.4:
	.asciz	"%ld"
	.size	.L.str.4, 4

	.file	2 "/usr/include/x86_64-linux-gnu/bits/types" "struct_FILE.h"
	.file	3 "/usr/include/x86_64-linux-gnu/bits" "types.h"
	.file	4 "/usr/lib/llvm-14/lib/clang/14.0.0/include" "stddef.h"
	.file	5 "/usr/include/x86_64-linux-gnu/bits/types" "FILE.h"
	.section	.debug_abbrev,"",@progbits
	.byte	1                               # Abbreviation Code
	.byte	17                              # DW_TAG_compile_unit
	.byte	1                               # DW_CHILDREN_yes
	.byte	37                              # DW_AT_producer
	.byte	37                              # DW_FORM_strx1
	.byte	19                              # DW_AT_language
	.byte	5                               # DW_FORM_data2
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	114                             # DW_AT_str_offsets_base
	.byte	23                              # DW_FORM_sec_offset
	.byte	16                              # DW_AT_stmt_list
	.byte	23                              # DW_FORM_sec_offset
	.byte	27                              # DW_AT_comp_dir
	.byte	37                              # DW_FORM_strx1
	.byte	17                              # DW_AT_low_pc
	.byte	27                              # DW_FORM_addrx
	.byte	18                              # DW_AT_high_pc
	.byte	6                               # DW_FORM_data4
	.byte	115                             # DW_AT_addr_base
	.byte	23                              # DW_FORM_sec_offset
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	2                               # Abbreviation Code
	.byte	15                              # DW_TAG_pointer_type
	.byte	0                               # DW_CHILDREN_no
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	3                               # Abbreviation Code
	.byte	46                              # DW_TAG_subprogram
	.byte	1                               # DW_CHILDREN_yes
	.byte	17                              # DW_AT_low_pc
	.byte	27                              # DW_FORM_addrx
	.byte	18                              # DW_AT_high_pc
	.byte	6                               # DW_FORM_data4
	.byte	64                              # DW_AT_frame_base
	.byte	24                              # DW_FORM_exprloc
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	63                              # DW_AT_external
	.byte	25                              # DW_FORM_flag_present
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	4                               # Abbreviation Code
	.byte	52                              # DW_TAG_variable
	.byte	0                               # DW_CHILDREN_no
	.byte	2                               # DW_AT_location
	.byte	24                              # DW_FORM_exprloc
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	5                               # Abbreviation Code
	.byte	36                              # DW_TAG_base_type
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	62                              # DW_AT_encoding
	.byte	11                              # DW_FORM_data1
	.byte	11                              # DW_AT_byte_size
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	6                               # Abbreviation Code
	.byte	15                              # DW_TAG_pointer_type
	.byte	0                               # DW_CHILDREN_no
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	7                               # Abbreviation Code
	.byte	38                              # DW_TAG_const_type
	.byte	0                               # DW_CHILDREN_no
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	8                               # Abbreviation Code
	.byte	22                              # DW_TAG_typedef
	.byte	0                               # DW_CHILDREN_no
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	9                               # Abbreviation Code
	.byte	19                              # DW_TAG_structure_type
	.byte	1                               # DW_CHILDREN_yes
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	11                              # DW_AT_byte_size
	.byte	11                              # DW_FORM_data1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	10                              # Abbreviation Code
	.byte	13                              # DW_TAG_member
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	56                              # DW_AT_data_member_location
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	11                              # Abbreviation Code
	.byte	19                              # DW_TAG_structure_type
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	60                              # DW_AT_declaration
	.byte	25                              # DW_FORM_flag_present
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	12                              # Abbreviation Code
	.byte	1                               # DW_TAG_array_type
	.byte	1                               # DW_CHILDREN_yes
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	13                              # Abbreviation Code
	.byte	33                              # DW_TAG_subrange_type
	.byte	0                               # DW_CHILDREN_no
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	55                              # DW_AT_count
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	14                              # Abbreviation Code
	.byte	36                              # DW_TAG_base_type
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	11                              # DW_AT_byte_size
	.byte	11                              # DW_FORM_data1
	.byte	62                              # DW_AT_encoding
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	15                              # Abbreviation Code
	.byte	22                              # DW_TAG_typedef
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	0                               # EOM(3)
	.section	.debug_info,"",@progbits
.Lcu_begin0:
	.long	.Ldebug_info_end0-.Ldebug_info_start0 # Length of Unit
.Ldebug_info_start0:
	.short	5                               # DWARF version number
	.byte	1                               # DWARF Unit Type
	.byte	8                               # Address Size (in bytes)
	.long	.debug_abbrev                   # Offset Into Abbrev. Section
	.byte	1                               # Abbrev [1] 0xc:0x203 DW_TAG_compile_unit
	.byte	0                               # DW_AT_producer
	.short	12                              # DW_AT_language
	.byte	1                               # DW_AT_name
	.long	.Lstr_offsets_base0             # DW_AT_str_offsets_base
	.long	.Lline_table_start0             # DW_AT_stmt_list
	.byte	2                               # DW_AT_comp_dir
	.byte	0                               # DW_AT_low_pc
	.long	.Lfunc_end0-.Lfunc_begin0       # DW_AT_high_pc
	.long	.Laddr_table_base0              # DW_AT_addr_base
	.byte	2                               # Abbrev [2] 0x23:0x1 DW_TAG_pointer_type
	.byte	3                               # Abbrev [3] 0x24:0x48 DW_TAG_subprogram
	.byte	0                               # DW_AT_low_pc
	.long	.Lfunc_end0-.Lfunc_begin0       # DW_AT_high_pc
	.byte	1                               # DW_AT_frame_base
	.byte	86
	.byte	3                               # DW_AT_name
	.byte	1                               # DW_AT_decl_file
	.byte	5                               # DW_AT_decl_line
	.long	108                             # DW_AT_type
                                        # DW_AT_external
	.byte	4                               # Abbrev [4] 0x33:0xb DW_TAG_variable
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	112
	.byte	5                               # DW_AT_name
	.byte	1                               # DW_AT_decl_file
	.byte	6                               # DW_AT_decl_line
	.long	112                             # DW_AT_type
	.byte	4                               # Abbrev [4] 0x3e:0xb DW_TAG_variable
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	104
	.byte	7                               # DW_AT_name
	.byte	1                               # DW_AT_decl_file
	.byte	7                               # DW_AT_decl_line
	.long	112                             # DW_AT_type
	.byte	4                               # Abbrev [4] 0x49:0xb DW_TAG_variable
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	96
	.byte	8                               # DW_AT_name
	.byte	1                               # DW_AT_decl_file
	.byte	10                              # DW_AT_decl_line
	.long	116                             # DW_AT_type
	.byte	4                               # Abbrev [4] 0x54:0xb DW_TAG_variable
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	88
	.byte	10                              # DW_AT_name
	.byte	1                               # DW_AT_decl_file
	.byte	11                              # DW_AT_decl_line
	.long	130                             # DW_AT_type
	.byte	4                               # Abbrev [4] 0x5f:0xc DW_TAG_variable
	.byte	3                               # DW_AT_location
	.byte	145
	.ascii	"\320}"
	.byte	53                              # DW_AT_name
	.byte	1                               # DW_AT_decl_file
	.byte	12                              # DW_AT_decl_line
	.long	514                             # DW_AT_type
	.byte	0                               # End Of Children Mark
	.byte	5                               # Abbrev [5] 0x6c:0x4 DW_TAG_base_type
	.byte	4                               # DW_AT_name
	.byte	5                               # DW_AT_encoding
	.byte	4                               # DW_AT_byte_size
	.byte	5                               # Abbrev [5] 0x70:0x4 DW_TAG_base_type
	.byte	6                               # DW_AT_name
	.byte	5                               # DW_AT_encoding
	.byte	8                               # DW_AT_byte_size
	.byte	6                               # Abbrev [6] 0x74:0x5 DW_TAG_pointer_type
	.long	121                             # DW_AT_type
	.byte	7                               # Abbrev [7] 0x79:0x5 DW_TAG_const_type
	.long	126                             # DW_AT_type
	.byte	5                               # Abbrev [5] 0x7e:0x4 DW_TAG_base_type
	.byte	9                               # DW_AT_name
	.byte	6                               # DW_AT_encoding
	.byte	1                               # DW_AT_byte_size
	.byte	6                               # Abbrev [6] 0x82:0x5 DW_TAG_pointer_type
	.long	135                             # DW_AT_type
	.byte	8                               # Abbrev [8] 0x87:0x8 DW_TAG_typedef
	.long	143                             # DW_AT_type
	.byte	52                              # DW_AT_name
	.byte	5                               # DW_AT_decl_file
	.byte	7                               # DW_AT_decl_line
	.byte	9                               # Abbrev [9] 0x8f:0x10b DW_TAG_structure_type
	.byte	51                              # DW_AT_name
	.byte	216                             # DW_AT_byte_size
	.byte	2                               # DW_AT_decl_file
	.byte	49                              # DW_AT_decl_line
	.byte	10                              # Abbrev [10] 0x94:0x9 DW_TAG_member
	.byte	11                              # DW_AT_name
	.long	108                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	51                              # DW_AT_decl_line
	.byte	0                               # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x9d:0x9 DW_TAG_member
	.byte	12                              # DW_AT_name
	.long	410                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	54                              # DW_AT_decl_line
	.byte	8                               # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0xa6:0x9 DW_TAG_member
	.byte	13                              # DW_AT_name
	.long	410                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	55                              # DW_AT_decl_line
	.byte	16                              # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0xaf:0x9 DW_TAG_member
	.byte	14                              # DW_AT_name
	.long	410                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	56                              # DW_AT_decl_line
	.byte	24                              # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0xb8:0x9 DW_TAG_member
	.byte	15                              # DW_AT_name
	.long	410                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	57                              # DW_AT_decl_line
	.byte	32                              # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0xc1:0x9 DW_TAG_member
	.byte	16                              # DW_AT_name
	.long	410                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	58                              # DW_AT_decl_line
	.byte	40                              # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0xca:0x9 DW_TAG_member
	.byte	17                              # DW_AT_name
	.long	410                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	59                              # DW_AT_decl_line
	.byte	48                              # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0xd3:0x9 DW_TAG_member
	.byte	18                              # DW_AT_name
	.long	410                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	60                              # DW_AT_decl_line
	.byte	56                              # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0xdc:0x9 DW_TAG_member
	.byte	19                              # DW_AT_name
	.long	410                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	61                              # DW_AT_decl_line
	.byte	64                              # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0xe5:0x9 DW_TAG_member
	.byte	20                              # DW_AT_name
	.long	410                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	64                              # DW_AT_decl_line
	.byte	72                              # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0xee:0x9 DW_TAG_member
	.byte	21                              # DW_AT_name
	.long	410                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	65                              # DW_AT_decl_line
	.byte	80                              # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0xf7:0x9 DW_TAG_member
	.byte	22                              # DW_AT_name
	.long	410                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	66                              # DW_AT_decl_line
	.byte	88                              # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x100:0x9 DW_TAG_member
	.byte	23                              # DW_AT_name
	.long	415                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	68                              # DW_AT_decl_line
	.byte	96                              # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x109:0x9 DW_TAG_member
	.byte	25                              # DW_AT_name
	.long	422                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	70                              # DW_AT_decl_line
	.byte	104                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x112:0x9 DW_TAG_member
	.byte	26                              # DW_AT_name
	.long	108                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	72                              # DW_AT_decl_line
	.byte	112                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x11b:0x9 DW_TAG_member
	.byte	27                              # DW_AT_name
	.long	108                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	73                              # DW_AT_decl_line
	.byte	116                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x124:0x9 DW_TAG_member
	.byte	28                              # DW_AT_name
	.long	427                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	74                              # DW_AT_decl_line
	.byte	120                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x12d:0x9 DW_TAG_member
	.byte	30                              # DW_AT_name
	.long	435                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	77                              # DW_AT_decl_line
	.byte	128                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x136:0x9 DW_TAG_member
	.byte	32                              # DW_AT_name
	.long	439                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	78                              # DW_AT_decl_line
	.byte	130                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x13f:0x9 DW_TAG_member
	.byte	34                              # DW_AT_name
	.long	443                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	79                              # DW_AT_decl_line
	.byte	131                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x148:0x9 DW_TAG_member
	.byte	36                              # DW_AT_name
	.long	459                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	81                              # DW_AT_decl_line
	.byte	136                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x151:0x9 DW_TAG_member
	.byte	38                              # DW_AT_name
	.long	468                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	89                              # DW_AT_decl_line
	.byte	144                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x15a:0x9 DW_TAG_member
	.byte	40                              # DW_AT_name
	.long	476                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	91                              # DW_AT_decl_line
	.byte	152                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x163:0x9 DW_TAG_member
	.byte	42                              # DW_AT_name
	.long	483                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	92                              # DW_AT_decl_line
	.byte	160                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x16c:0x9 DW_TAG_member
	.byte	44                              # DW_AT_name
	.long	422                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	93                              # DW_AT_decl_line
	.byte	168                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x175:0x9 DW_TAG_member
	.byte	45                              # DW_AT_name
	.long	35                              # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	94                              # DW_AT_decl_line
	.byte	176                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x17e:0x9 DW_TAG_member
	.byte	46                              # DW_AT_name
	.long	490                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	95                              # DW_AT_decl_line
	.byte	184                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x187:0x9 DW_TAG_member
	.byte	49                              # DW_AT_name
	.long	108                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	96                              # DW_AT_decl_line
	.byte	192                             # DW_AT_data_member_location
	.byte	10                              # Abbrev [10] 0x190:0x9 DW_TAG_member
	.byte	50                              # DW_AT_name
	.long	502                             # DW_AT_type
	.byte	2                               # DW_AT_decl_file
	.byte	98                              # DW_AT_decl_line
	.byte	196                             # DW_AT_data_member_location
	.byte	0                               # End Of Children Mark
	.byte	6                               # Abbrev [6] 0x19a:0x5 DW_TAG_pointer_type
	.long	126                             # DW_AT_type
	.byte	6                               # Abbrev [6] 0x19f:0x5 DW_TAG_pointer_type
	.long	420                             # DW_AT_type
	.byte	11                              # Abbrev [11] 0x1a4:0x2 DW_TAG_structure_type
	.byte	24                              # DW_AT_name
                                        # DW_AT_declaration
	.byte	6                               # Abbrev [6] 0x1a6:0x5 DW_TAG_pointer_type
	.long	143                             # DW_AT_type
	.byte	8                               # Abbrev [8] 0x1ab:0x8 DW_TAG_typedef
	.long	112                             # DW_AT_type
	.byte	29                              # DW_AT_name
	.byte	3                               # DW_AT_decl_file
	.byte	152                             # DW_AT_decl_line
	.byte	5                               # Abbrev [5] 0x1b3:0x4 DW_TAG_base_type
	.byte	31                              # DW_AT_name
	.byte	7                               # DW_AT_encoding
	.byte	2                               # DW_AT_byte_size
	.byte	5                               # Abbrev [5] 0x1b7:0x4 DW_TAG_base_type
	.byte	33                              # DW_AT_name
	.byte	6                               # DW_AT_encoding
	.byte	1                               # DW_AT_byte_size
	.byte	12                              # Abbrev [12] 0x1bb:0xc DW_TAG_array_type
	.long	126                             # DW_AT_type
	.byte	13                              # Abbrev [13] 0x1c0:0x6 DW_TAG_subrange_type
	.long	455                             # DW_AT_type
	.byte	1                               # DW_AT_count
	.byte	0                               # End Of Children Mark
	.byte	14                              # Abbrev [14] 0x1c7:0x4 DW_TAG_base_type
	.byte	35                              # DW_AT_name
	.byte	8                               # DW_AT_byte_size
	.byte	7                               # DW_AT_encoding
	.byte	6                               # Abbrev [6] 0x1cb:0x5 DW_TAG_pointer_type
	.long	464                             # DW_AT_type
	.byte	15                              # Abbrev [15] 0x1d0:0x4 DW_TAG_typedef
	.byte	37                              # DW_AT_name
	.byte	2                               # DW_AT_decl_file
	.byte	43                              # DW_AT_decl_line
	.byte	8                               # Abbrev [8] 0x1d4:0x8 DW_TAG_typedef
	.long	112                             # DW_AT_type
	.byte	39                              # DW_AT_name
	.byte	3                               # DW_AT_decl_file
	.byte	153                             # DW_AT_decl_line
	.byte	6                               # Abbrev [6] 0x1dc:0x5 DW_TAG_pointer_type
	.long	481                             # DW_AT_type
	.byte	11                              # Abbrev [11] 0x1e1:0x2 DW_TAG_structure_type
	.byte	41                              # DW_AT_name
                                        # DW_AT_declaration
	.byte	6                               # Abbrev [6] 0x1e3:0x5 DW_TAG_pointer_type
	.long	488                             # DW_AT_type
	.byte	11                              # Abbrev [11] 0x1e8:0x2 DW_TAG_structure_type
	.byte	43                              # DW_AT_name
                                        # DW_AT_declaration
	.byte	8                               # Abbrev [8] 0x1ea:0x8 DW_TAG_typedef
	.long	498                             # DW_AT_type
	.byte	48                              # DW_AT_name
	.byte	4                               # DW_AT_decl_file
	.byte	46                              # DW_AT_decl_line
	.byte	5                               # Abbrev [5] 0x1f2:0x4 DW_TAG_base_type
	.byte	47                              # DW_AT_name
	.byte	7                               # DW_AT_encoding
	.byte	8                               # DW_AT_byte_size
	.byte	12                              # Abbrev [12] 0x1f6:0xc DW_TAG_array_type
	.long	126                             # DW_AT_type
	.byte	13                              # Abbrev [13] 0x1fb:0x6 DW_TAG_subrange_type
	.long	455                             # DW_AT_type
	.byte	20                              # DW_AT_count
	.byte	0                               # End Of Children Mark
	.byte	12                              # Abbrev [12] 0x202:0xc DW_TAG_array_type
	.long	126                             # DW_AT_type
	.byte	13                              # Abbrev [13] 0x207:0x6 DW_TAG_subrange_type
	.long	455                             # DW_AT_type
	.byte	255                             # DW_AT_count
	.byte	0                               # End Of Children Mark
	.byte	0                               # End Of Children Mark
.Ldebug_info_end0:
	.section	.debug_str_offsets,"",@progbits
	.long	220                             # Length of String Offsets Set
	.short	5
	.short	0
.Lstr_offsets_base0:
	.section	.debug_str,"MS",@progbits,1
.Linfo_string0:
	.asciz	"Ubuntu clang version 14.0.0-1ubuntu1" # string offset=0
.Linfo_string1:
	.asciz	"1.c"                           # string offset=37
.Linfo_string2:
	.asciz	"/home/max/git/aoc/2022/1"      # string offset=41
.Linfo_string3:
	.asciz	"main"                          # string offset=66
.Linfo_string4:
	.asciz	"int"                           # string offset=71
.Linfo_string5:
	.asciz	"calories_max"                  # string offset=75
.Linfo_string6:
	.asciz	"long"                          # string offset=88
.Linfo_string7:
	.asciz	"current_calories"              # string offset=93
.Linfo_string8:
	.asciz	"input_path"                    # string offset=110
.Linfo_string9:
	.asciz	"char"                          # string offset=121
.Linfo_string10:
	.asciz	"fin"                           # string offset=126
.Linfo_string11:
	.asciz	"_flags"                        # string offset=130
.Linfo_string12:
	.asciz	"_IO_read_ptr"                  # string offset=137
.Linfo_string13:
	.asciz	"_IO_read_end"                  # string offset=150
.Linfo_string14:
	.asciz	"_IO_read_base"                 # string offset=163
.Linfo_string15:
	.asciz	"_IO_write_base"                # string offset=177
.Linfo_string16:
	.asciz	"_IO_write_ptr"                 # string offset=192
.Linfo_string17:
	.asciz	"_IO_write_end"                 # string offset=206
.Linfo_string18:
	.asciz	"_IO_buf_base"                  # string offset=220
.Linfo_string19:
	.asciz	"_IO_buf_end"                   # string offset=233
.Linfo_string20:
	.asciz	"_IO_save_base"                 # string offset=245
.Linfo_string21:
	.asciz	"_IO_backup_base"               # string offset=259
.Linfo_string22:
	.asciz	"_IO_save_end"                  # string offset=275
.Linfo_string23:
	.asciz	"_markers"                      # string offset=288
.Linfo_string24:
	.asciz	"_IO_marker"                    # string offset=297
.Linfo_string25:
	.asciz	"_chain"                        # string offset=308
.Linfo_string26:
	.asciz	"_fileno"                       # string offset=315
.Linfo_string27:
	.asciz	"_flags2"                       # string offset=323
.Linfo_string28:
	.asciz	"_old_offset"                   # string offset=331
.Linfo_string29:
	.asciz	"__off_t"                       # string offset=343
.Linfo_string30:
	.asciz	"_cur_column"                   # string offset=351
.Linfo_string31:
	.asciz	"unsigned short"                # string offset=363
.Linfo_string32:
	.asciz	"_vtable_offset"                # string offset=378
.Linfo_string33:
	.asciz	"signed char"                   # string offset=393
.Linfo_string34:
	.asciz	"_shortbuf"                     # string offset=405
.Linfo_string35:
	.asciz	"__ARRAY_SIZE_TYPE__"           # string offset=415
.Linfo_string36:
	.asciz	"_lock"                         # string offset=435
.Linfo_string37:
	.asciz	"_IO_lock_t"                    # string offset=441
.Linfo_string38:
	.asciz	"_offset"                       # string offset=452
.Linfo_string39:
	.asciz	"__off64_t"                     # string offset=460
.Linfo_string40:
	.asciz	"_codecvt"                      # string offset=470
.Linfo_string41:
	.asciz	"_IO_codecvt"                   # string offset=479
.Linfo_string42:
	.asciz	"_wide_data"                    # string offset=491
.Linfo_string43:
	.asciz	"_IO_wide_data"                 # string offset=502
.Linfo_string44:
	.asciz	"_freeres_list"                 # string offset=516
.Linfo_string45:
	.asciz	"_freeres_buf"                  # string offset=530
.Linfo_string46:
	.asciz	"__pad5"                        # string offset=543
.Linfo_string47:
	.asciz	"unsigned long"                 # string offset=550
.Linfo_string48:
	.asciz	"size_t"                        # string offset=564
.Linfo_string49:
	.asciz	"_mode"                         # string offset=571
.Linfo_string50:
	.asciz	"_unused2"                      # string offset=577
.Linfo_string51:
	.asciz	"_IO_FILE"                      # string offset=586
.Linfo_string52:
	.asciz	"FILE"                          # string offset=595
.Linfo_string53:
	.asciz	"buff"                          # string offset=600
	.section	.debug_str_offsets,"",@progbits
	.long	.Linfo_string0
	.long	.Linfo_string1
	.long	.Linfo_string2
	.long	.Linfo_string3
	.long	.Linfo_string4
	.long	.Linfo_string5
	.long	.Linfo_string6
	.long	.Linfo_string7
	.long	.Linfo_string8
	.long	.Linfo_string9
	.long	.Linfo_string10
	.long	.Linfo_string11
	.long	.Linfo_string12
	.long	.Linfo_string13
	.long	.Linfo_string14
	.long	.Linfo_string15
	.long	.Linfo_string16
	.long	.Linfo_string17
	.long	.Linfo_string18
	.long	.Linfo_string19
	.long	.Linfo_string20
	.long	.Linfo_string21
	.long	.Linfo_string22
	.long	.Linfo_string23
	.long	.Linfo_string24
	.long	.Linfo_string25
	.long	.Linfo_string26
	.long	.Linfo_string27
	.long	.Linfo_string28
	.long	.Linfo_string29
	.long	.Linfo_string30
	.long	.Linfo_string31
	.long	.Linfo_string32
	.long	.Linfo_string33
	.long	.Linfo_string34
	.long	.Linfo_string35
	.long	.Linfo_string36
	.long	.Linfo_string37
	.long	.Linfo_string38
	.long	.Linfo_string39
	.long	.Linfo_string40
	.long	.Linfo_string41
	.long	.Linfo_string42
	.long	.Linfo_string43
	.long	.Linfo_string44
	.long	.Linfo_string45
	.long	.Linfo_string46
	.long	.Linfo_string47
	.long	.Linfo_string48
	.long	.Linfo_string49
	.long	.Linfo_string50
	.long	.Linfo_string51
	.long	.Linfo_string52
	.long	.Linfo_string53
	.section	.debug_addr,"",@progbits
	.long	.Ldebug_addr_end0-.Ldebug_addr_start0 # Length of contribution
.Ldebug_addr_start0:
	.short	5                               # DWARF version number
	.byte	8                               # Address size
	.byte	0                               # Segment selector size
.Laddr_table_base0:
	.quad	.Lfunc_begin0
.Ldebug_addr_end0:
	.ident	"Ubuntu clang version 14.0.0-1ubuntu1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym fopen
	.addrsig_sym fgets
	.addrsig_sym strcmp
	.addrsig_sym strtol
	.addrsig_sym printf
	.section	.debug_line,"",@progbits
.Lline_table_start0:
