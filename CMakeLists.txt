cmake_minimum_required( VERSION 2.8 )

project(arm-kernel C ASM)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostartfiles")

set(SOURCES 
    main.c
)

set(
    HEADERS definitions.h
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
