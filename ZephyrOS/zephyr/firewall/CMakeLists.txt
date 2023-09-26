# IoTFirewall for Zephyr

add_compile_definitions(CONFIG_USE_PERIPHERAL_FILTER ZEPHYR_OS DEV_NRF52840)

file(GLOB filter_src
        "core/*.h"
        "core/*.c"
        # "experiment/*.h"
        # "experiment/*.c"
        )

file(GLOB policies_src "policy/src/*.c")

zephyr_include_directories("../")
zephyr_include_directories(".")
zephyr_include_directories("policy")
zephyr_include_directories("include")
# zephyr_include_directories("experiment")
zephyr_include_directories("libebpf/ebpf-src/")
zephyr_sources(${filter_src} ${policies_src})


add_subdirectory("libebpf")