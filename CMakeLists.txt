cmake_minimum_required(VERSION 3.0.0)
project(algorithm VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
include_directories("include")

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Bin)
add_library(binary_tree_library  STATIC src/binary_tree_impl.cpp)
target_include_directories(binary_tree_library 
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include    
)

set(CMAKE_CXX_STANDARD 11)
add_executable(2d_find 001_2d_find.cpp)
add_executable(stringreplace stringreplace.cpp)
add_executable(link_node link_node.cpp)
add_executable(shared shared_ptr_test.cpp)
add_executable(introsort introsort.cpp)
add_executable(fibonacci fibonacci.cpp)
add_executable(binary_tree_exe binary_tree.cpp)
add_executable(pow pow.cpp)
add_executable(print1toN print1_to_n.cpp)
add_executable(odd_1st odd_1st_even_2nd.cpp)
add_executable(last_k last_k_th.cpp)
add_executable(valid_stack_sequence valid_stack_sequence.cpp)

target_link_libraries(binary_tree_exe 
    PRIVATE
    binary_tree_library    
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)