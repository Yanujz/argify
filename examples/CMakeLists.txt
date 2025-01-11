cmake_minimum_required(VERSION 3.20)
project(example)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../ ${CMAKE_BINARY_DIR}/argify)

# Add main executable
add_executable(${PROJECT_NAME} main.c)


target_link_libraries(${PROJECT_NAME} PUBLIC argify)