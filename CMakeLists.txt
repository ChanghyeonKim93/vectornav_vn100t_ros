cmake_minimum_required(VERSION 2.8.3)
project(vectornav_vn100t_ros)

add_definitions("-std=c++17")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  diagnostic_updater
)
find_package(Boost REQUIRED)

catkin_package(
  INCLUDE_DIRS include vncpplib/include
  LIBRARIES imu_vn_100
  CATKIN_DEPENDS diagnostic_updater roscpp sensor_msgs
  DEPENDS boost
)

include_directories(
  include
  vncpplib/include
  ${catkin_INCLUDE_DIRS}
)


add_library(imu_vn_100
  vncpplib/src/arch/linux/vncp_services.c
  vncpplib/src/vndevice.c
  vncpplib/src/vn100.c
  src/imu_vn_100.cpp
)
target_link_libraries(imu_vn_100
  ${catkin_LIBRARIES}
)
add_dependencies(imu_vn_100
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)

add_executable(vn100t_node
  src/vn100t_node.cpp)
target_link_libraries(vn100t_node
  ${catkin_LIBRARIES}
  imu_vn_100
)
add_dependencies(vn100t_node
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)
