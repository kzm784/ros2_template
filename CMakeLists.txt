cmake_minimum_required(VERSION 3.8)
project(ros2_template)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_library(${PROJECT_NAME} SHARED
  src/simple_server.cpp
  src/simple_client.cpp
)

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN "SimpleServer"
  EXECUTABLE simple_server_node
)

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN "SimpleClient"
  EXECUTABLE simple_client_node
)

target_link_libraries(${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package(
  INSTALL_TO_SHARE
  config
  launch
)

install(FILES DESTINATION share/${PROJECT_NAME})