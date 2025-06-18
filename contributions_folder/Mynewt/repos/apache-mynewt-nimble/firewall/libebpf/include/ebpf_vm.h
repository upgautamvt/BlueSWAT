# Lines added by author
#define MAX_BPF_EXT_REG 16
typedef struct ebpf_helper_func {
	ext_func *ext_funcs;
	// const char **ext_func_names;
	int refcnt;
typedef struct ebpf_vm {
	struct ebpf_inst *insts;
	u16 num_insts;
	bool bounds_check_enabled;
	ebpf_helper_func *helper_func;
	ebpf_jit_fn jit_func;
	struct jit_mem *jmem;
	bool use_jit;
		      uint32_t code_len);
		  void *fn);
