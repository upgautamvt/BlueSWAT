
set(LIBEBPF_DIR ebpf-src)

file(GLOB libebpf_src
        "${LIBEBPF_DIR}/*.h"
        "${LIBEBPF_DIR}/*.c")

zephyr_library()
zephyr_library_sources(${libebpf_src})
