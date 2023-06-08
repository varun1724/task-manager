cmake_minimum_required(VERSION 3.20.2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_executable(runAllTests
  test.cpp 
)
add_subdirectory(googletest)
target_link_libraries(runAllTests gtest gtest_main)
target_link_libraries(runAllTests shcedulerLibrary)


