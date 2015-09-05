cmake_minimum_required( VERSION 2.8 )

project(arm-kernel C ASM)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostartfiles")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -O0 -g")

set(SOURCES 
    main.c
    start.S
    cstartup.c
)

set(
    HEADERS definitions.h
)

set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS} -Wl,-T,${CMAKE_CURRENT_SOURCE_DIR}/rpi.x"
)

add_executable(
    arm-kernel
    ${SOURCES}
    ${HEADERS}
)    

add_custom_command(
    TARGET arm-kernel
    COMMAND ${CMAKE_OBJCOPY} ./arm-kernel${EXECUTABLE_SUFFIX} -O binary kernel.img
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Convert ELF output to binary image"
)
