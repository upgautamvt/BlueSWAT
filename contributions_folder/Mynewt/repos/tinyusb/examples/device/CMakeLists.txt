# Lines added by author
cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../hw/bsp/family_support.cmake)

project(tinyusb_device_examples)
family_initialize_project(tinyusb_device_examples ${CMAKE_CURRENT_LIST_DIR})

# family_add_subdirectory will filter what to actually add based on selected FAMILY
family_add_subdirectory(audio_4_channel_mic)
family_add_subdirectory(audio_test)
family_add_subdirectory(board_test)
family_add_subdirectory(cdc_dual_ports)
family_add_subdirectory(cdc_msc)
family_add_subdirectory(cdc_msc_freertos)
family_add_subdirectory(dfu)
family_add_subdirectory(dfu_runtime)
family_add_subdirectory(dynamic_configuration)
family_add_subdirectory(hid_composite)
family_add_subdirectory(hid_composite_freertos)
family_add_subdirectory(hid_generic_inout)
family_add_subdirectory(hid_multiple_interface)
family_add_subdirectory(midi_test)
family_add_subdirectory(msc_dual_lun)
family_add_subdirectory(net_lwip_webserver)
family_add_subdirectory(uac2_headset)
family_add_subdirectory(usbtmc)
family_add_subdirectory(video_capture)
family_add_subdirectory(webusb_serial)
