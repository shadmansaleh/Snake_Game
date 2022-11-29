cmake_minimum_required(VERSION 3.0)
project(DinoGame)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
  "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
  "-fsanitize=address"
  "$<$<CONFIG:DEBUG>:-O0;-gdwarf-4;-ggdb>"
)

add_link_options(-fsanitize=address)

include_directories(include)

file(GLOB SRC_DINO_GAME 
  "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(snake ${SRC_DINO_GAME})
