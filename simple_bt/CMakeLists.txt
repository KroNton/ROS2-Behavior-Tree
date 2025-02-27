cmake_minimum_required(VERSION 3.5)

project(btcpp_sample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(${BehaviorTreeV4_INCLUDE_DIRS})  # Add BehaviorTree.CPP include paths
include_directories(include)  # Add your project's include directory
add_executable(btcpp_sample src/simple_bt.cpp)

find_package(ament_cmake QUIET)

if(ament_cmake_FOUND)

    find_package(behaviortree_cpp REQUIRED)
    ament_target_dependencies(btcpp_sample behaviortree_cpp)

elseif( CATKIN_DEVEL_PREFIX OR CATKIN_BUILD_BINARY_PACKAGE)

    find_package(catkin REQUIRED COMPONENTS behaviortree_cpp)
    catkin_package(CATKIN_DEPENDS behaviortree_cpp)
    target_include_directories(btcpp_sample PRIVATE ${catkin_INCLUDE_DIRS})
    target_link_libraries(btcpp_sample ${catkin_LIBRARIES})

else()

    find_package(behaviortree_cpp REQUIRED)
    target_link_libraries(btcpp_sample BT::behaviortree_cpp)

endif()
