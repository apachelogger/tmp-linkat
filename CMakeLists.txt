cmake_minimum_required(VERSION 3.0)

project(tmp-linkat)

add_executable(${PROJECT_NAME} main.c)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
