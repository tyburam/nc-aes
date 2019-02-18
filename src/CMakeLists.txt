set(SRC_SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/neuro/tree_parity_machine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/neuro/tpm_input_vector.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/neuro/neuro_crypto.cpp)

set(SRC_HEADER_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/neuro/dynamic_array.h
        ${CMAKE_CURRENT_SOURCE_DIR}/neuro/tree_parity_machine.h
        ${CMAKE_CURRENT_SOURCE_DIR}/neuro/common.h
        ${CMAKE_CURRENT_SOURCE_DIR}/neuro/tpm_input_vector.h
        ${CMAKE_CURRENT_SOURCE_DIR}/neuro/neuro_crypto.h)

add_library(src ${SRC_HEADER_FILES} ${SRC_SOURCE_FILES})