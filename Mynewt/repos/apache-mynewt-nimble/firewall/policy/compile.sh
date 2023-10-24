#!/bin/bash
fi=$1
python3 ../libebpf/tools/compile_code.py -s specification/eBPF_C_code/${fi}.ebpf.c -f specification/include/${fi}.h -o ../libebpf/tools/prog.bin