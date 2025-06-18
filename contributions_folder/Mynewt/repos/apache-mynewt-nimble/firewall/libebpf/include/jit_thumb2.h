# Lines added by author
    DEBUG_LOG("_thumb32_LSRW_IMM_T2: %x -> lsr.w r1, r2, #5\n",
    DEBUG_LOG("_thumb32_ORRW_REG_T2: %x -> orr.w r1, r2, r3, lsl #5\n",
// typedef unsigned char		u8;
// typedef unsigned short		u16;
// typedef unsigned int		u32;
// typedef unsigned long long	u64;
// typedef signed char		s8;
// typedef short			s16;
// typedef int				s32;
// typedef long long		s64;

// #define USE_JIT_TEST
// #define DEBUG
// #ifdef DEBUG
// #define DEBUG_LOG(...)								\
// do {												\
// 	my_printf(__VA_ARGS__);							\
// } while (0)
// #else
// #define DEBUG_LOG(...) do {} while(0)
// #endif // end DEBUG

#define ERR_IMM(imm)                                                           \
	DEBUG_LOG("Invalide imm value. Line:%d Val:%d\n", __LINE__, imm)
#define CALLEE_MASK                                                            \
	(1 << ARM_R4 | 1 << ARM_R5 | 1 << ARM_R6 | 1 << ARM_R7 | 1 << ARM_R8 | \
	 1 << ARM_R9 | 1 << ARM_FP)
	return (THUMB2_UMULL_T2) | (Rn << 16) | (RdLo << 12) | (RdHi << 8) |
	       (Rm);
	return (THUMB2_MUL_T2) | (Rn << 16) | (Rd << 8) | (Rm);
	return (THUMB2_IT) | (cond << 4) | (mask);
	s32 imm8 = shiftImm12 & 0xff;
	s32 imm3 = (shiftImm12 >> 8) & 0b111;
	s32 i = (shiftImm12 >> 11) & 0x1;
	return (THUMB2_RSBW_IMM) | (i << 26) | (flagS << 20) | (Rn << 16) |
	       (imm3 << 12) | (Rd << 8) | (imm8);
				       u8 srtype, u8 flagS)
	s32 imm2 = shiftImm5 & 0b11;
	s32 imm3 = (shiftImm5 >> 2) & 0b111;
	return (THUMB2_RSBW_REG) | (flagS << 20) | (Rn << 16) | (imm3 << 12) |
	       (Rd << 8) | (imm2 << 6) | (srtype << 4) | (Rm);
	u16 imm8 = (offImm9 >> 1) & 0x00ff;
	// DEBUG_LOG("----------------------offset: %d\n", imm8);
	return (THUMB2_B_COND_T1) | (cond << 8) | (imm8);
	u16 imm11 = (offImm12 >> 1) & 0x7ff;
	// DEBUG_LOG("----------------------offset: %d\n", imm11);
	return (THUMB2_B_T2) | (imm11);
	return (THUMB2_BLX_REG_T1) | (Rm << 3);
	u32 S = offImm20 < 0;
	u32 imm11 = (offImm20 >> 1) & 0x7ff;
	u32 imm6 = (offImm20 >> 12) & 0x3f;
	u32 J1 = (offImm20 >> 18) & 0x1;
	u32 J2 = (offImm20 >> 19) & 0x1;
	return (THUMB2_BW_COND_T3) | (S << 26) | (cond << 22) | (imm6 << 16) |
	       (J1 << 13) | (J2 << 11) | (imm11);
	s32 S = offImm23 < 0;
	s32 imm11 = (offImm23 >> 1) & 0x7ff;
	s32 imm10 = (offImm23 >> 12) & 0x3ff;
	s32 I1 = (offImm23 >> 18) & 0x1;
	s32 I2 = (offImm23 >> 19) & 0x1;
	s32 J1 = (~I1 ^ S) & 0x1;
	s32 J2 = (~I2 ^ S) & 0x1;
	return (THUMB2_BW_COND_T3) | (S << 26) | (imm10 << 16) | (J1 << 13) |
	       (J2 << 11) | (imm11);
				   u8 srtype, u8 flagS)
	s32 imm3 = (shiftImm5 >> 2) & 0b111;
	s32 imm2 = shiftImm5 & 0b11;
	return (THUMB2_SBCW_REG) | (flagS << 20) | (Rn << 16) | (imm3 << 12) |
	       (Rd << 8) | (imm2 << 6) | (srtype << 4) | (Rm);
	return (THUMB2_CMP_REG_T1) | (Rm << 3) | (Rn);
	u16 N = (Rn & 0b1000) >> 3;
	u16 Rn3 = Rn & 0b111;
	return (THUMB2_CMP_REG_T2) | (N << 7) | (Rm << 3) | (Rn3);
	u32 imm3 = (offImm5 >> 2) & 0b111;
	u32 imm2 = offImm5 & 0b11;
	return (THUMB2_CMPW_REG_T3) | (Rn << 16) | (imm3 << 12) | (imm2 << 6) |
	       (srtype << 4) | (Rm);
	return (THUMB2_MUL_REG_T2) | (Rn << 16) | (Rd << 8) | (Rm);
	u16 imm = imm8 & 0xff;
	return (THUMB2_ADD_IMM_T2) | (RDn << 8) | (imm);
	u32 i = (imm12 >> 11) & 0x1;
	u32 imm3 = (imm12 >> 8) & 0b111;
	u32 imm8 = imm12 & 0xff;
	return (THUMB2_ADD_IMM_T4) | (i << 26) | (Rn << 16) | (imm3 << 12) |
	       (Rd << 8) | imm8;
	u16 DN = (RDn >> 3) & 0x1;
	u16 rdn = RDn & 0b111;
	return (THUMB2_ADD_REG_T2) | (DN << 7) | (Rm << 3) | (rdn);
				       u8 srtype, u8 flagS)
	u32 imm3 = (offImm5 >> 2) & 0b111;
	u32 imm2 = offImm5 & 0b11;
	return (THUMB2_ADDW_REG) | (flagS << 20) | (Rn << 16) | (imm3 << 12) |
	       (Rd << 8) | (imm2 << 6) | (srtype << 4) | (Rm);
	return (THUMB2_AND_REG_T1) | (Rm << 3) | (RDn);
				      u8 srtype, u8 flagS)
	u32 imm3 = (offImm5 >> 2) & 0b111;
	u32 imm2 = offImm5 & 0b11;
	return (THUMB2_AND_REG_T2) | (flagS << 20) | (Rn << 16) | (imm3 << 12) |
	       (Rd << 8) | (imm2 << 6) | (srtype << 4) | (Rm);
	u16 D = (Rd >> 3) & 0b0001;
	u16 Rd3 = Rd & 0b111;
	return (THUMB2_MOV_REG) | (D << 7) | (Rm << 3) | (Rd3);
	return (THUMB2_MOVS_REG) | (Rm << 3) | (Rd);
	return (THUMB2_MOVW_REG) | (flagS << 20) | (Rd << 8) | (Rm);
	imm3 = imm3 & 0b111;
	return (THUMB2_SUB_IMM_T1) | (imm3 << 6) | (Rn3 << 3) | (Rd3);
	imm8 = imm8 & 0xff;
	return (THUMB2_SUB_IMM_T2) | (Rdn3 << 8) | imm8;
	u32 i = (imm12 >> 11) & 0x1;
	u32 imm3 = (imm12 >> 8) & 0b11;
	u32 imm8 = imm12 & 0xff;
	return (THUMB2_SUBW_IMM_T4) | (i << 26) | (Rn << 16) | (imm3 << 12) |
	       (Rd << 8) | (imm8);
	return (THUMB2_SUB_REG_T1) | (Rm << 6) | (Rn << 3) | (Rd);
				      u8 srtype, u8 flagS)
	u32 imm3 = (shiftOff5 >> 2) & 0b111;
	u32 imm2 = shiftOff5 & 0b11;
	return (THUMB2_SUB_REG_T2) | (flagS << 20) | (Rn << 16) | (imm3 << 12) |
	       (Rd << 8) | (imm2 << 6) | (srtype << 4) | (Rm);
	u16 M = (reg_mask >> 14) & 0x1;
	u16 reg_list = reg_mask & 0xff;
	return (THUMB2_PUSH_T1) | (M << 8) | (reg_list);
	u32 M = (reg_mask >> 14) & 0x1;
	u32 reg_list = reg_mask & 0x1fff;
	return (THUMB2_PUSH_W) | (M << 14) | (reg_list);
	u32 M = (reg_mask >> 14) & 0x1;
	u32 P = (reg_mask >> 15) & 0x1;
	u32 reg_list = reg_mask & 0x1fff;
	return (THUMB2_POP_W) | (P << 15) | (M << 14) | (reg_list);
	return (THUMB2_LDRB_IMM_T1) | (offImm5 << 6) | (Rn << 3) | (Rt);
	s32 imm8 = offImm8 > 0 ? offImm8 : -offImm8;
	u32 P = 1, U = offImm8 >= 0, W = 0; // p = 0 && w = 0 -> undefined
	u32 flag = 0b1000 | (P << 2) | (U << 1) | W;
	u32 inst = (THUMB2_LDRB_IMM_T3) | (Rn << 16) | (Rt << 12) |
		   (flag << 8) | (imm8);
	// DEBUG_LOG("_thumb32_LDRB_IMM_T3 inst: 0x%08x %d flag=%d\n", inst, imm8, flag);
	return inst;
	u32 imm8 = offImm8 > 0 ? offImm8 : -offImm8;
	u32 P = offImm8 != 0, U = offImm8 >= 0, W = 0;
	u32 flag = (P << 2) | (U << 1) | W;
	u32 inst = (THUMB2_LDR_IMM_T4) | (Rn << 16) | (Rt << 12) | (flag << 8) |
		   (imm8);
	return inst;
static inline u32 _thumb32_LDRD_IMM_T1(s8 Rt[], s8 Rn, s32 offImm8)
	u32 P = offImm8 != 0, U = offImm8 > 0, W = 0;
	u32 imm8 = offImm8 > 0 ? offImm8 : -offImm8;
	imm8 = (imm8 >> 2) & 0xff;
	u32 flag = 0b0010 | (P << 3) | (U << 2) | W;
	u32 inst = (THUMB2_LDRD_IMM) | (flag << 21) | (Rn << 16) |
		   (Rt[1] << 12) | (Rt[0] << 8) | (imm8);
	// DEBUG_LOG("inst: 0x%08x\n", inst);
	return inst;
	u32 P = offImm8 != 0;
	u32 U = offImm8 > 0, W = 0;
	u32 imm8 = offImm8 > 0 ? offImm8 : -offImm8;
	u32 flag = 0b111 | (P << 2) | (U << 1) | (W);
	u32 inst = (THUMB2_STRB_IMM_T3) | (Rn << 16) | (Rt << 12) |
		   (flag << 8) | (imm8);
	return inst;
	u32 P = offImm8 != 0;
	u32 U = offImm8 > 0, W = 0;
	u32 imm8 = offImm8 > 0 ? offImm8 : -offImm8;
	u32 flag = 0b111 | (P << 2) | (U << 1) | (W);
	u32 inst = (THUMB2_STRH_IMM_T3) | (Rn << 16) | (Rt << 12) |
		   (flag << 8) | (imm8);
	return inst;
static inline u32 _thumb32_STRD_IMM_T1(s8 RnSrc[], s8 RtDst, s16 offImm8)
	u32 P = offImm8 != 0;
	u32 U = offImm8 > 0, W = 0;
	u32 imm8 = offImm8 > 0 ? offImm8 : -offImm8;
	imm8 = (imm8 >> 2) & 0xff;
	u32 inst = (THUMB2_STRD_IMM) | (P << 24) | (U << 23) | (W << 22) |
		   (RtDst << 16) | (RnSrc[1] << 12) | (RnSrc[0] << 8) | (imm8);
	// DEBUG_LOG("_thumb32_STRD_IMM_T1: %d %d\n", offImm8, imm8);
	return inst;
	u32 imm3 = (imm5 >> 2) & 0b111;
	u32 imm2 = imm5 & 0b11;
	return (THUMB2_ASRW_IMM) | (flagS << 20) | (imm3 << 12) | (Rd << 8) |
	       (imm2 << 6) | (Rm);
	return (THUMB2_ASRW_REG) | (flagS << 20) | (Rn << 16) | (Rd << 8) |
	       (Rm);
	return (THUMB2_LSLW_REG_T2) | (flagS << 20) | (Rn << 16) | (Rd << 8) |
	       (Rm);
	return (THUMB2_LSRW_REG) | (flagS << 20) | (Rn << 16) | (Rd << 8) |
	       (Rm);
	if (shiftImm5 < 0 || shiftImm5 > 0b11111) {
		// DEBUG_LOG("Invalide imm value. Line:%d Val:%d\n", __LINE__, shiftImm5);
		return -1;
	}
	u32 imm3 = (shiftImm5 >> 2) & 0b111;
	u32 imm2 = shiftImm5 & 0b11;
	u32 inst = (THUMB2_LSRW_IMM) | (flagS << 20) | (imm3 << 12) |
		   (Rd << 8) | (imm2 << 6) | (Rm);
	return inst;
	u16 RDn3 = RDn & 0b111;
	u16 Rm3 = Rm & 0b111;
	return (THUMB2_ORR_REG) | (RDn3 << 4) | (Rm3);
				      u8 srtype, u8 flagS)
	u32 imm3 = (shiftImm5 >> 2) & 0b111;
	u32 imm2 = shiftImm5 & 0b11;
	return (THUMB2_EOR_REG_T2) | (flagS << 20) | (Rn << 16) | (imm3 << 12) |
	       (Rd << 8) | (imm2 << 6) | (srtype << 4) | (Rm);
				       u8 srtype, u8 flagS)
	if (shiftImm5 < 0 || shiftImm5 > 0b11111) {
		// DEBUG_LOG("Invalide imm value. Line:%d Val:%d\n", __LINE__, shiftImm5);
		return -1;
	}
	u32 imm3 = (shiftImm5 >> 2) & 0b111;
	u32 imm2 = shiftImm5 & 0b11;
	u32 inst = (THUMB2_ORRW_REG) | (flagS << 20) | (Rn << 16) |
		   (imm3 << 12) | (Rd << 8) | (imm2 << 6) | (srtype << 4) |
		   (Rm);
	return inst;
	DEBUG_LOG("_thumb32_LSRW_IMM_T2: %x -> lsr.w r1, r2, #5\n",
		  _thumb32_LSRW_IMM_T2(1, 2, 5, FLAG_NOS));
	DEBUG_LOG("_thumb32_ORRW_REG_T2: %x -> orr.w r1, r2, r3, lsl #5\n",
		  _thumb32_ORRW_REG_T2(1, 2, 3, 5, SRTYPE_LSL, FLAG_NOS));
