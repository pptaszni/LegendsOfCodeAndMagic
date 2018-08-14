cmake_minimum_required(VERSION 3.0.0)
project(LegendsOfCodeAndMagic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wno-unused-variable -std=c++14 -O -pthread -g")

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_subdirectory(src)
add_subdirectory(tests)

add_custom_target(createOutput
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/createOutput.sh
    COMMENT "Creating output.cpp file for CodingGame ... "
    DEPENDS createOutput.sh
)

add_dependencies(mainExec createOutput)
add_dependencies(createOutput LegendsOfCodeSolution)
