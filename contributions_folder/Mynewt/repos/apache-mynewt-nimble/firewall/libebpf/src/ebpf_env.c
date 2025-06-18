# Lines added by author
void init_ubpf_env() {
ebpf_prog* ebpf_add_prog(const void *code, u32 code_len) {
	ebpf_prog *prog = (ebpf_prog*) ebpf_malloc(sizeof(ebpf_prog));
    // prog
    if (current_env.prog_list == NULL) {
    if (current_env.tail != NULL) {
int ebpf_remove_prog(ebpf_prog *prog) {
void destory_ebpf_env() {
    
