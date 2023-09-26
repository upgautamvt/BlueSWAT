
# Makefile to build all ebpf code

SRC := $(wildcard ebpf_code/*.ebpf.c)
EBPF_CODES := $(patsubst ebpf_code/%.ebpf.c, %.h, $(SRC))

all: $(EBPF_CODES)

%.h:
	@echo "Compile $@"
	@bash compile.sh $(basename $@)
	@echo "Genterate eBPF bytecode in include/$@"

cve_all:
	@echo "Gen CVE includes in cve_all.h"

clean:
	@rm -rf include/cve_*.h

# log: # @echo $(SRC) $(EBPF_CODES)

.PHONY: all clean