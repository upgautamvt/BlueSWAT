# Lines added by author
    DEBUG_LOG("\nDecode:\n");
        DEBUG_LOG("%02x", state->jit_code[i]);
    DEBUG_LOG("\n");
        DEBUG_LOG("Invalide imm value. Line:%d Val:%d\n", __LINE__, val);
        DEBUG_LOG("Unsupport op: %x pc: %d\n", code, pc);
        DEBUG_LOG("TODO op: %x pc: %d\n", code, pc);
            DEBUG_LOG("ERROR: %d\n", ret);
typedef uint64_t (*f_ebpf)(void*);
static void first_jit_func();
void jit_run_test() {



// ebpf Memory Instuctions 
#define ARM_LDR_I  0x6800 // A7-246
enum {
  ARM_R0 =	0,
  ARM_R1 =	1,
  ARM_R2 =	2,
  ARM_R3 =	3,
  ARM_R4 =	4,
  ARM_R5 =	5,
  ARM_R6 =	6,
  ARM_R7 =	7,
  ARM_R8 =	8,
  ARM_R9 =	9,
  ARM_R10 =	10,
  ARM_FP =	11,	/* Frame Pointer */
  ARM_IP =	12,	/* Intra-procedure scratch register */
  ARM_SP =	13,	/* Stack pointer: as load/store base reg */
  ARM_LR =	14,	/* Link Register */
  ARM_PC =	15,	/* Program counter */
enum {
	/* Stack layout - these are offsets from (top of stack - 4) */
	BPF_R2_HI = 0,
	BPF_R2_LO,
	BPF_R3_HI,
	BPF_R3_LO,
	BPF_R4_HI,
	BPF_R4_LO,
	BPF_R5_HI,
	BPF_R5_LO,
	BPF_R7_HI,
	BPF_R7_LO,
	BPF_R8_HI,
	BPF_R8_LO,
	BPF_R9_HI,
	BPF_R9_LO,
	BPF_FP_HI,
	BPF_FP_LO,
	BPF_TC_HI,
	BPF_TC_LO,
	BPF_AX_HI,
	BPF_AX_LO,
	/* Stack space for BPF_REG_2, BPF_REG_3, BPF_REG_4,
	 * BPF_REG_5, BPF_REG_7, BPF_REG_8, BPF_REG_9,
	 * BPF_REG_FP and Tail call counts.
	 */
	BPF_JIT_SCRATCH_REGS,
#define STACK_OFFSET(k)	(-4 - (k) * 4)
#define SCRATCH_SIZE	(BPF_JIT_SCRATCH_REGS * 4)
#define TMP_REG_1	(MAX_BPF_JIT_REG + 0)	/* TEMP Register 1 */
#define TMP_REG_2	(MAX_BPF_JIT_REG + 1)	/* TEMP Register 2 */
#define TCALL_CNT	(MAX_BPF_JIT_REG + 2)	/* Tail Call Count */
#define EBPF_SCRATCH_TO_ARM_FP(x) ((x) - 4 * 7 - 4)
 * 
	/* return value from in-kernel function, and exit value from eBPF */
	[BPF_REG_0] = {ARM_R1, ARM_R0},
	/* arguments from eBPF program to in-kernel function */
	[BPF_REG_1] = {ARM_R3, ARM_R2},
	/* Stored on stack scratch space */
	[BPF_REG_2] = {STACK_OFFSET(BPF_R2_HI), STACK_OFFSET(BPF_R2_LO)},
	[BPF_REG_3] = {STACK_OFFSET(BPF_R3_HI), STACK_OFFSET(BPF_R3_LO)},
	[BPF_REG_4] = {STACK_OFFSET(BPF_R4_HI), STACK_OFFSET(BPF_R4_LO)},
	[BPF_REG_5] = {STACK_OFFSET(BPF_R5_HI), STACK_OFFSET(BPF_R5_LO)},
	/* callee saved registers that in-kernel function will preserve */
	[BPF_REG_6] = {ARM_R5, ARM_R4},
	/* Stored on stack scratch space */
	[BPF_REG_7] = {STACK_OFFSET(BPF_R7_HI), STACK_OFFSET(BPF_R7_LO)},
	[BPF_REG_8] = {STACK_OFFSET(BPF_R8_HI), STACK_OFFSET(BPF_R8_LO)},
	[BPF_REG_9] = {STACK_OFFSET(BPF_R9_HI), STACK_OFFSET(BPF_R9_LO)},
	/* Read only Frame Pointer to access Stack */
	[BPF_REG_FP] = {STACK_OFFSET(BPF_FP_HI), STACK_OFFSET(BPF_FP_LO)},
	/* Temporary Register for internal BPF JIT, can be used
	 * for constant blindings and others.
	 */
	[TMP_REG_1] = {ARM_R7, ARM_R6},
	[TMP_REG_2] = {ARM_R9, ARM_R8},
	/* Tail call count. Stored on stack scratch space. */
	[TCALL_CNT] = {STACK_OFFSET(BPF_TC_HI), STACK_OFFSET(BPF_TC_LO)},
	/* temporary register for blinding constants.
	 * Stored on stack scratch space.
	 */
	[BPF_REG_AX] = {STACK_OFFSET(BPF_AX_HI), STACK_OFFSET(BPF_AX_LO)},
#define	dst_lo	dst[1]
#define dst_hi	dst[0]
#define src_lo	src[1]
#define src_hi	src[0]
static bool is_stacked(int8_t reg) {
	return reg < 0;
static int8_t arm_bpf_get_reg32(jit_state *state, s8 reg, s8 tmp) {
	if (is_stacked(reg)) {
		//emit(ARM_LDR_I(tmp, ARM_FP, EBPF_SCRATCH_TO_ARM_FP(reg)), ctx);
        // rt rn off
		reg = tmp;
	}
	return reg;
static void arm_bpf_put_reg32(jit_state *state, s8 reg, s8 src) {
	if (is_stacked(reg)) {
		// emit(ARM_STR_I(src, ARM_FP, EBPF_SCRATCH_TO_ARM_FP(reg)), ctx);
	} else if (reg != src) {
static const s8 *arm_bpf_get_reg64(jit_state *state, const s8 *reg, const s8 *tmp) {
    if (is_stacked(reg[1])) {
         s16 off = EBPF_SCRATCH_TO_ARM_FP(reg[1]);
static void arm_bpf_put_reg64(jit_state *state, const s8 *reg, const s8 *src) {
	if (is_stacked(reg[1])) {
	} else {
		if (reg[1] != src[1]) {
            
        if (reg[0] != src[0]) {
static bool is_ldst_imm(s16 off, const u8 size) {
	s16 off_max = 0;
	switch (size) {
	case EBPF_SIZE_B:
	case EBPF_SIZE_W:
		off_max = 0xfff;
		break;
	case EBPF_SIZE_H:
		off_max = 0xff;
		break;
	case EBPF_SIZE_DW:
		/* Need to make sure off+4 does not overflow. */
		off_max = 0xfff - 4;
		break;
	}
	return -off_max <= off && off <= off_max;
void jit_dump_inst(jit_state *state) {
    for (int i = 0; i < state->idx; i++) {
static void _emit_ldr_i(jit_state *state, const s8 Rt, const s8 Rn, s16 off) {
    // } else if (off <= imm8 && off >= 0 && Rt < 8 && Rn < 8) { // 
    // } 
    if (off == 0) { // imm12
    } else {
static void _emit_ldrb_i(jit_state *state, const s8 Rt, const s8 Rn, s16 off) {
    if (off <= imm5 && off >= -imm5) {
        if (Rt < 8 && Rn < 8) {
    } 
    if (off <= imm8 && off >= -imm8) {
    } else if (off <= imm12 && off >= -imm12) {
static void _emit_ldrh_i(jit_state *state, const s8 Rt, const s8 Rn, s16 off) {
    if (off <= imm5 && off >= -imm5) {
    } else if (off <= imm8 && off >= -imm8) {
    } else if (off <= imm12 && off >= -imm12) {
static void _emit_ldrd_i(jit_state *state, const s8 Rt[], const s8 Rn, s16 off) {
static void test_ldr(jit_state *state) {
static void _emit_str_i(jit_state *state, const s8 RnSrc, const s8 Rt,  s16 off) {
    u32 inst = (THUMB2_STR_IMM)  | (RnSrc << 16) | (Rt << 12) | (flag << 8) | (imm8);
static void _emit_strd_i(jit_state *state, const s8 RnSrc[], const s8 RtDst,  s16 off) {
    // * 4
    // my_printf("_emit_strd_i: %x\n", inst);
static void inline _emit_add_reg(jit_state *state, const s8 dst, const s8 src, const bool is64, const bool hi) {
    if (is64) {
        if (hi) { // ADC should not update flag
        } else { // set flag ADDS
    } else { // ADD
static void _emit_add_imm(jit_state *state, const s8 dst, const s8 src, s32 val) {
    if (val >= 0 && val <= 255) {
        if (dst == src && dst < 8) {
        } 
    if (val >= 0 && val <= 4095) {
static void _emit_sub_imm(jit_state *state, const s8 dst, const s8 src, s32 val) {
    if (val < 0 || val > 4095) {
    if (dst < 8 && dst >= 0 && src < 8 && src >= 0) {
        if (dst == src && val <= 0xff) {
        if (val <= 0x7) {
static void inline _emit_sub_reg(jit_state *state, const s8 dst, const s8 src, const bool is64, const bool hi) {
    if (is64 && !hi) { // subs.w
    } else if (is64 && hi) { // suc
        uint32_t inst = (0xeb600000) | (src << 16) | (dst << 8) | (dst);
    } else { // subs or sub.w
        if (src < 8 && dst < 8) {
        } else {
static void inline _emit_orr_reg(jit_state *state, const s8 dst, const s8 src) {
    if (dst < 8 && src < 8) {
    } else {
static void inline _emit_and_reg(jit_state *state, const s8 dst, const s8 src) {
    if (dst < 8 && src < 8) {
    } else {
static void inline _emit_cmp_reg(jit_state *state, const s8 Rn, const s8 Rm) {
    if (Rn < 0x8 && Rm < 0x8) {
    } else {

static bool inline _use_b4(jit_state *state) {
static void inline _emit_b_cond(jit_state *state, s32 off, u8 cond) {
    if (!_use_b4(state) && off >= -256 && off <= 254) {
    } else if (off > -1048576 && off < 1048574) {
static void inline _emit_b(jit_state *state, s32 off) {
    if (off > -2048 && off < 2046) {
    } else if (off > -16777216 && off < 16777214) {
static void emit_alu32_reg(jit_state *state, const s8 dst, const s8 src, 
            const bool is64, const bool hi, const u8 op) {
        if (rn > 0 && rn < 8 && rd > 0 && rd < 8) {
        } else {
        if (rn > 0 && rn < 8 && rd > 0 && rd < 8) {
        } else {
        if (rn > 0 && rn < 8 && rd > 0 && rd < 8) {
        } else {
        if (rn > 0 && rn < 8 && rd > 0 && rd < 8) {
        } else {
        if (rn > 0 && rn < 8 && rd > 0 && rd < 8) {
        } else {
	arm_bpf_put_reg32(state, dst, rd);
void emit_alu64_reg(jit_state *state, bool is64, const s8 dst[], const s8 src[], const u8 op) {
	const s8 *tmp2 = bpf2a32[TMP_REG_2];
	const s8 *rd = arm_bpf_get_reg64(state, dst, tmp);
    if (is64) {
    } else {
static void emit_alu32_imm(jit_state *state, const s8 dst, const u16 val, const u8 op) {
    switch (op) {
static void emit_u32_div_mod(jit_state *state, const s8 dst[], const s8 src[], const u16 code, const u16 imm) {
    const s8 *tmp = bpf2a32[TMP_REG_1];
    switch (BPF_SRC(code)) {
    if (BPF_OP(code) == EBPF_ALU_DIV) {
    } else { // MOD
// dst: rd rt 
static void _emit_cmp_cond(jit_state *state, s8 rd, s8 rt, s8 rm, s8 rn, u8 op, bool is_jmp64) {
        if (is_jmp64) {
        } else {
    
    case EBPF_JNE: // != 
        if (is_jmp64) {
			// emit(ARM_CMP_R(rd, rm), ctx);
			/* Only compare low halve if high halve are equal. */
			// _emit(ARM_COND_EQ, ARM_CMP_R(rt, rn), ctx);
             _emit_cmp_reg(state, rt, rn);
		} else {
			// emit(ARM_CMP_R(rt, rn), ctx);
             _emit_cmp_reg(state, rt, rn);
        if (is_jmp64) { // subtract with carray b - a, rm - rd
        if (is_jmp64) {
static void _emit_jump(jit_state *state, s32 jmp_off, s8 op) {
    switch (op)
    case EBPF_JNE: // != 
		// _emit(ARM_COND_CS, ARM_B(jmp_offset), ctx);
void _emit_lsh64_reg(jit_state *state, const s8 dst[], const s8 src[]) {
   
	emit(ARM_SUBS_I(tmp2[0], rt, 32), ctx);
	emit(ARM_MOV_SR(ARM_LR, rd[1], SRTYPE_LSR, rt), ctx);
	emit(ARM_ORR_SR(ARM_LR, ARM_LR, rd[0], SRTYPE_ASL, ARM_IP), ctx);
	emit(ARM_ORR_SR(ARM_LR, ARM_LR, rd[0], SRTYPE_LSR, tmp2[0]), ctx);
	emit(ARM_MOV_SR(ARM_IP, rd[0], SRTYPE_LSR, rt), ctx);
    
    inst = (THUMB2_ORRW_REG) | (tmp2[0] << 16) | (ARM_IP << 8) | (ARM_IP); 
    
   
    inst = (THUMB2_ORRW_REG) | (tmp2[0] << 16) | (ARM_IP << 8) | (ARM_IP); 
	arm_bpf_put_reg32(state, dst_lo, tmp2[0]);
	arm_bpf_put_reg32(state, dst_hi, ARM_IP);
void _emit_lsh64_imm(jit_state *state, const s8 dst[], const u16 val) {
	const s8 *tmp2 = bpf2a32[TMP_REG_2];
	const s8 *rd;
	/* Setup operands */
	rd = arm_bpf_get_reg64(state, dst, tmp);
	/* Do LSH operation */
    if (val < 32) {
        u32 inst = (0xea5f0000) | (imm3 << 12) | (tmp2[0] << 8) | (imm2 << 4) | (rd[0]);  
        // lsls imm 
        emit2(state, (0x0000) | (val << 6) | (rd[1]<< 3) | (rd[1]));
    } else {
        if (val == 32) { // 0
            // emit(ARM_MOV_R(rd[0], rd[1]), ctx); 

        } else {
static inline void emit_a32_rsh_r64(jit_state *state, const s8 dst[], const s8 src[]) {
static inline void emit_a32_rsh_i64(jit_state *state, const s8 dst[], const u16 val) {
    if (val == 0) {
            * for LSR. To shift by 0, don't do anything.
            */
    } else if (val < 32) {
    } else if (val == 32) {
		// emit(ARM_MOV_I(rd[0], 0), ctx);
    } else {

static inline void emit_a32_arsh_r64(jit_state *state, const s8 dst[], const s8 src[]) {
	// emit(ARM_SUBS_I(tmp2[0], rt, 32), ctx);
	// emit(ARM_MOV_SR(ARM_LR, rd[1], SRTYPE_LSR, rt), ctx);
	// emit(ARM_ORR_SR(ARM_LR, ARM_LR, rd[0], SRTYPE_ASL, ARM_IP), ctx);
	// _emit(ARM_COND_PL, ARM_ORR_SR(ARM_LR, ARM_LR, rd[0], SRTYPE_ASR, tmp2[0]), ctx);
static inline void emit_a32_arsh_i64(jit_state *state, const s8 dst[], const u32 val) {
    if (val == 0) {
            * for ASR. To shift by 0, don't do anything.
            */
    } else if (val < 32) {
    } else if (val == 32) {
    } else {
static inline void emit_a32_neg64(jit_state *state, const s8 dst[]){
static inline void emit_a32_mul_r64(jit_state *state, const s8 dst[], const s8 src[]) {
	const s8 *tmp = bpf2a32[TMP_REG_1];
	const s8 *tmp2 = bpf2a32[TMP_REG_2];
	const s8 *rd, *rt;
	/* Setup operands for multiplication */
	rd = arm_bpf_get_reg64(state, dst, tmp);
	rt = arm_bpf_get_reg64(state, src, tmp2);
	/* Do Multiplication */
	// emit(ARM_MUL(ARM_IP, rd[1], rt[0]), ctx);
	// emit(ARM_MUL(ARM_LR, rd[0], rt[1]), ctx);
	// emit(ARM_ADD_R(ARM_LR, ARM_IP, ARM_LR), ctx);
	// emit(ARM_UMULL(ARM_IP, rd[0], rd[1], rt[1]), ctx);
	// emit(ARM_ADD_R(rd[0], ARM_LR, rd[0]), ctx);
     emit2(state, _thumb16_ADD_REG_T2(rd[0], ARM_LR));
	arm_bpf_put_reg32(state, dst_lo, ARM_IP);
	arm_bpf_put_reg32(state, dst_hi, rd[0]);
void test_alu(jit_state *state) {
void emit_ldx_reg(jit_state *state, const s8 dst[], const s8 src, s16 off, const u8 sz) 
    const s8 *rd = is_stacked(dst_lo) ? tmp : dst; //Rt
    s8 rm = src; // Rn
    // 
    if (!is_ldst_imm(off, sz)) {
    } else if (rd[1] == rm) {
    //const u16 ARM_LDR_I = 0x6800; // 0b011010
    // my_printf("emit_ldx size: %d\n", sz);
    u16 inst = 0;
    switch (sz) {
        case EBPF_SIZE_B:
            // DEBUG_LOG("_emit_ldrb_i: %d %d off=%d\n", rd[1], rm, off);
            _emit_ldrb_i(state, rd[1], rm, off);
            break;
        case EBPF_SIZE_H:
            _emit_ldrh_i(state, rd[1], rm, off);
            break;
        case EBPF_SIZE_W: // A7-246
            // DEBUG_LOG("EBPF_SIZE_W %d %d\n", rd[1], rm);
            _emit_ldr_i(state, rd[1], rm, off);
            break;
        case EBPF_SIZE_DW:
            // emit(ARM_LDR_I(rd[1], rm, off), ctx);
		    // emit(ARM_LDR_I(rd[0], rm, off + 4), ctx);
            // DEBUG_LOG("EBPF_SIZE_DW: %d %d %d\n", rd[0], rd[1], rm);
            _emit_ldr_i(state, rd[1], rm, off);
            _emit_ldr_i(state, rd[0], rm, off + 4);
            // _emit_ldrd_i(state, rd, rm, off);
            break;
static void emit_str_reg(jit_state *state, const s8 dst, const s8 src[], s16 off, const u8 sz) {
    if (!is_ldst_imm(off, sz)) {
    switch (sz) {
    u16 imm8 = 0xff, imm13 = 0xff, imm16 = 0xffff;
	//int imm12 = imm8m(val);
	if (val <= imm8 && val >= 0 && rd < 8) {
    } else {
        if (val > 0xffff) { // movt
            // inst = 
	// 	emit(ARM_MOV_I(rd, imm12), ctx);
	// else
	// 	emit_mov_i_no8m(rd, val, ctx);
static void _emit_mov_reg(jit_state *state, s8 src, s8 dst) {
   // uint16_t inst =  0x4600 | (src << 3) | (dst);
    if (dst != ARM_SP && src != ARM_SP) {
   
static void emit_a32_mov_reg(jit_state *state, s8 src, s8 dst) {
	s8 rt = arm_bpf_get_reg32(state, src, tmp[0]);
	arm_bpf_put_reg32(state, dst, rt);
static void emit_mov_reg64(jit_state *state, const bool is64, const s8 dst[], const s8 src[]) {
    if (!is64) {
    } else if (is_stacked(src_lo) && is_stacked(dst_lo)) {
        const u8 *tmp = bpf2a32[TMP_REG_1];
    } else if (is_stacked(src_lo)) {
    }  else if (is_stacked(dst_lo)) {
    } else {
static void emit_push_r64(jit_state *state, s8 src[]) {
    if ((rt[0] == ARM_LR || rt[0] < 8) && (rt[1] == ARM_LR || rt[1] < 8)) {
    } else {
   
static void emit_mov_se_imm64(jit_state *state, const bool is64, const s8 dst[], const u32 val) {
    if (is64) {
        if (is64 && (val & (1<<31))) // < 0
        //my_printf("emit_mov_se_imm64asd\n");
    } else {
static void test_mov(jit_state *state) {
    s8 dst[] = {0, 3};
    emit_mov_se_imm64(state, false, dst, 0x100);
    emit_mov_se_imm64(state, false, dst, 0xfffff82f);
    emit_a32_mov_reg(state, 0, 1);
}
static inline int bpf2a32_offset(jit_state *state, int bpf_from, int bpf_to, int bsize) {
    if (!state->needGen) {
static inline int epilogue_offset(jit_state *state) {
    if (!state->needGen) {
    from = state->idx; // <-----
    // 
static void gen_return(jit_state *state) {
    // emit_mov_reg(state, false, )
    _emit_mov_reg(state, ARM_IP, 0);
    _emit_mov_reg(state, ARM_LR, 1);
}
static int build_inst(jit_state *state, ebpf_inst *inst) {
    uint32_t target_pc = pc + inst->offset + 1;
    int8_t rd_lo, rt, rm, rn;
    switch (code) {
/* ALU operations */
    
            if (imm == 1) {
        
            * and then do the ALU operation on the temporary
            * register as this will sign-extend the immediate
            * value into temporary reg and then it would be
            * safe to do the operation on it.
            */
        if (imm > 31) {
        if (imm) {
	/* dst = dst * src/imm */
	case EBPF_OP_MUL64_IMM:
	case EBPF_OP_MUL64_REG: {
        switch (BPF_SRC(code)) {
        
         case EBPF_SRC_REG:
       
	/* dst = htobe(dst) */
	case EBPF_OP_LE:
	case EBPF_OP_BE:
    case EBPF_OP_LDDW: { // cur-inst.imm + next-inst.imm
        u64 val = (u32) (imm) | (u64) ((u32) inst[1].imm) << 32;
    case EBPF_OP_STDW: {
    case EBPF_OP_JSLE_REG: {
        int start_delta = state->idx;
        if (BPF_SRC(code) == EBPF_SRC_REG) {
        } else { // IMM
        if (!_use_b4(state)) {
    case EBPF_OP_CALL: {
        const u32 func = *(u32 *) (state->__bpf_call_base + imm * 4);
       
        
    
        if (pc == state->inst_num - 1) 
notyet:
        DEBUG_LOG("Do not implement current op: %x pc: %d\n", code, pc);
        state->err_line = __LINE__;
        return -1;
todo:
static void build_prologue(jit_state *state) {
	const s8 *bpf_fp = bpf2a32[BPF_REG_FP];
	// emit_a32_mov_r64(state, true, bpf_fp, bpf_r1);
static void build_body(jit_state *state) {
    for (int i = 0; i < inst_num; i++) {
        if (ret > 0) { // load value, skip
            if (!state->needGen) {
        if (!state->needGen) { // offset = end
        if (ret < 0) {
static void build_epilogue(jit_state *state) {
	// emit(ARM_MOV_R(ARM_SP, ARM_FP), ctx);
	// emit(ARM_POP(CALLEE_POP_MASK), ctx);
static void test_branch(jit_state *state) {
    emit_mov_imm(state, 0, 3);
    emit_mov_imm(state, 1, 0);
    emit4(state, _thumb32_ORRW_REG_T2(0, 0, 1, 0, SRTYPE_LSL, FLAG_S));
    _emit_b_cond(state, 1, COND_NE);
    emit_mov_imm(state, 0, 2);
}
void jit_compile(jit_state *state) {
	state->idx = 0;
static void ebpf_ret(uint64_t ret) {
    uint32_t op = ret >> 32;
    uint32_t lr = (uint32_t) (ret & 0x00000000FFFFFFFF);
    // DEBUG_LOG("ebpf_ret: op=%x lr=%x\n", op, lr);
}
uint64_t ebpf_run_jit(jit_state *state, void *ctx) {
    jit_func func = (jit_func) ((uint32_t) state->jit_code | 0x1);
    ebpf_ret(ret2);

jit_state* init_jit_state(uint8_t *code, int code_len) {
    ebpf_inst *insts = (ebpf_inst *) code;
    state->jit_code = (uint8_t *) ((uint32_t) jit_buffer & (~0x3));
void run_jit_func(uint8_t *code, int len, void *ctx) {
char code_t1[] = ""
"\x61\x12\x08\x00\x00\x00\x00\x00\x61\x11\x04\x00\x00\x00\x00\x00\x07\x01\x00\x00\x05\x00\x00\x00\x67"
"\x01\x00\x00\x20\x00\x00\x00\x77\x01\x00\x00\x20\x00\x00\x00\x69\x11\x00\x00\x00\x00\x00\x00\xbf\x24"
"\x00\x00\x00\x00\x00\x00\x0f\x14\x00\x00\x00\x00\x00\x00\x67\x04\x00\x00\x20\x00\x00\x00\x77\x04\x00"
"\x00\x20\x00\x00\x00\x18\x00\x00\x00\xea\xff\xff\xff\x00\x00\x00\x00\x01\x00\x00\x00\x18\x03\x00\x00"
"\xea\xff\xff\xff\x00\x00\x00\x00\x01\x00\x00\x00\x25\x04\x01\x00\xfe\xff\x00\x00\xb7\x03\x00\x00\x00"
"\x00\x00\x00\x2d\x21\x01\x00\x00\x00\x00\x00\xbf\x30\x00\x00\x00\x00\x00\x00\x95\x00\x00\x00\x00\x00"
"\x00\x00"
"";

uint64_t my_test_func2(uint64_t a1, uint64_t a2) {
} 
static void gen_code_for_ebpf1() {
