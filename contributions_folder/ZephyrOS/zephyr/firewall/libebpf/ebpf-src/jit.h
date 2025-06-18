# Lines added by author


    uint8_t *jit_code;
    int code_size;
    uint8_t *jmp_offsets;
jit_mem* jit_mem_allocate(int insts_num);
    struct ebpf_inst *insts;
    int inst_num;
    uint8_t *jit_code;
    int size;
    int idx;
    int epilogue_offset;
    int err_line;
    uint32_t *offsets;
    void *__bpf_call_base;
    jit_mem *jmem;
    // int inst_loc;
    bool needGen; // pre-pass or generate-pass
static inline void
emit_bytes(struct jit_state *state, void *data, uint32_t len) 
    // my_printf("emit_bytes: %s 0x%x\n", state->jit_code, *((uint16_t*) data));
    if (state->needGen) {
        memcpy(state->jit_code + state->idx, data, len);
    }
    
    // uint8_t *d = (uint8_t *) data;
    // for (int i = 0; i < len; i++) {
    //     state->jit_code[state->idx + i] = d[i];
    //     my_printf("state->jit_code[%d] = 0x%x\n", state->idx + i, d[i]);
    // }
    state->idx += len;
static inline void
emit2(struct jit_state *state, uint16_t x)
    emit_bytes(state, &x, sizeof(x));
    //state->inst_loc += 1;
static inline void
emit4(struct jit_state *state, uint32_t x)
    uint16_t *u2 = (uint16_t *) (&x);
    emit2(state, u2[1]);
    emit2(state, u2[0]);
    // emit_bytes(state, &u2[1], sizeof(u2[1]));
    // emit_bytes(state, &u2[0], sizeof(u2[0]));
