cmake_minimum_required(VERSION 3.10)
project(simple-svg VERSION 1.0.0)

# Options
option(BUILD_EXAMPLES "Build example executable" ON)
option(BUILD_TESTING "Build tests with GTest" ON)

# Header-only library (always INTERFACE)
add_library(simple-svg INTERFACE)
target_include_directories(simple-svg INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(simple-svg INTERFACE cxx_std_11)

# Optional: Build example executable
if(BUILD_EXAMPLES)
    add_executable(simple-svg-example main_1.0.0.cpp)
    target_link_libraries(simple-svg-example PRIVATE simple-svg)
    
    if(MSVC)
        target_compile_definitions(simple-svg-example PRIVATE
            _CRT_SECURE_NO_WARNINGS
            _SCL_SECURE_NO_WARNINGS
            NOMINMAX
        )
    endif()
endif()

# Optional: Build tests
if(BUILD_TESTING)
    enable_testing()
    
    find_package(GTest REQUIRED)
    
    add_executable(simple-svg-test tests/simple_svg_test.cpp)
    target_link_libraries(simple-svg-test 
        PRIVATE 
        simple-svg 
        GTest::gtest
        GTest::gtest_main
    )
    
    add_test(NAME SimplesvgTest COMMAND simple-svg-test)
endif()

# Installation
install(TARGETS simple-svg
    EXPORT simple-svg-targets
)
install(FILES simple_svg_1.0.0.hpp 
    DESTINATION include
)
install(EXPORT simple-svg-targets
    FILE simple-svg-targets.cmake
    NAMESPACE simple-svg::
    DESTINATION lib/cmake/simple-svg
)
