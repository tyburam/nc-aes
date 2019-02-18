cmake_minimum_required(VERSION 3.6)
project(nc_aes)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)

add_subdirectory("${PROJECT_SOURCE_DIR}/src")
add_subdirectory("${PROJECT_SOURCE_DIR}/vendor")
add_executable(nc_aes ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} src)
target_link_libraries(${PROJECT_NAME} vendor)
