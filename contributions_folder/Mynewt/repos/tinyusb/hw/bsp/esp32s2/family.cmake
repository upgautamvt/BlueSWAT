# Lines added by author
cmake_minimum_required(VERSION 3.5)

# Add example src and bsp directories
set(EXTRA_COMPONENT_DIRS "src" "${TOP}/hw/bsp/esp32s2/boards" "${TOP}/hw/bsp/esp32s2/components")  
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
set(SUPPORTED_TARGETS esp32s2)
set(FAMILY_MCUS ESP32S2)
