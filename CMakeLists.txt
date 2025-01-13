cmake_minimum_required(VERSION 3.0.2)
project(microphone_time_sync)

## Compile as C++11
add_compile_options(-std=c++11)

## Package dependencies
find_package(catkin REQUIRED COMPONENTS
  audio_common_msgs
  roscpp
  std_msgs
  message_generation
)

## Declare custom message
add_message_files(
  FILES
  AudioStamped.msg
)

## Generate messages
generate_messages(
  DEPENDENCIES
  std_msgs
)

## Catkin specific configuration
catkin_package(
  CATKIN_DEPENDS audio_common_msgs roscpp std_msgs message_runtime
)

## Include header directories
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Create executable and link libraries
add_executable(microphone_node src/microphone_node.cpp)
target_link_libraries(microphone_node ${catkin_LIBRARIES})
add_dependencies(microphone_node ${catkin_EXPORTED_TARGETS})
