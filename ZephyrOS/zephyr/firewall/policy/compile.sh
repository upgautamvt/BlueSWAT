#!/bin/bash
fi=$1
python3 ../libebpf/tools/compile_code.py -s ebpf_C_code/${fi}.ebpf.c -f ebpf_bytecode/${fi}.h -o ../libebpf/tools/prog.bin