add_subdirectory(googlemock)

add_executable(ut main.cpp)
target_link_libraries(ut gmock)
add_test(UnitTest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ut)
