cmake_minimum_required(VERSION 3.10.2)
project(simple_arm_bt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(behaviortree_cpp REQUIRED)
message(STATUS "behaviortree_cpp found at: ${behaviortree_cpp_DIR}")

add_executable(simple_bt simple_bt.cpp)
target_link_libraries(simple_bt behaviortree_cpp::behaviortree_cpp)