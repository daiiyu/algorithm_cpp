include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)

set(unit_name unit_test)
add_executable(${unit_name}
        maxValue.cpp
        )

target_link_libraries(${unit_name}
        gtest
        gtest_main
        )

set(test_target ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/${unit_name})
add_test(NAME unit
        COMMAND ${test_target} --gtest_color=yes
)

add_custom_target(check
        COMMAND env CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND}
        DEPENDS ${test_target})