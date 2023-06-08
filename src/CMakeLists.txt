cmake_minimum_required(VERSION 3.20.2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_executable(taskscheduler
  main.cpp
  Event.cpp
  EventList.cpp
  Goal.cpp
  GoalList.cpp
)

add_library(shcedulerLibrary
  Event.cpp
  EventList.cpp
  Goal.cpp
  GoalList.cpp
)

find_library(M_LIB m)
target_link_libraries(shcedulerLibrary ${M_LIB})



