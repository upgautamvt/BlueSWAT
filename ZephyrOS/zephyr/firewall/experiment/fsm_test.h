#ifndef FSM_TEST_H_
#define FSM_TEST_H_

enum experiment_index {
	SINGLE_POLICY_LOCAL,
	ALL_POLICIES_LOCAL,
	SINGLE_POLICY_END_TO_END,
	SINGLE_POLICY_END_TO_END_JIT,
	ALL_POLICIES_END_TO_END,
	ALL_POLICIES_END_TO_END_JIT,
};

void test_local_conn_chan_map();
void test_local_conn_chan_hop();
void test_local_ebpf_helper();
void test_all_mem();

#endif // FSM_TEST_H_