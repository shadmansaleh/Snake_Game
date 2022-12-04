cmake_minimum_required(VERSION 3.0)

project(SnakeGame VERSION 1.0)
include(FetchContent)

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type selected, default to Debug")
  set(CMAKE_BUILD_TYPE "Debug")
endif()

IF(WIN32)
    SET(CMAKE_FIND_LIBRARY_SUFFIXES .lib .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
ELSE(WIN32)
    SET(CMAKE_FIND_LIBRARY_SUFFIXES .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
ENDIF(WIN32)

set(SFML_USE_STATIC_STD_LIB TRUE)
set(BUILD_SHARED_LIBS FALSE)

set(BUILD_SHARED_LIBRARIES OFF)
set(FETCHCONTENT_BASE_DIR "${PROJECT_SOURCE_DIR}/.deps")
FetchContent_Declare(
  SFML
  URL https://github.com/SFML/SFML/archive/refs/tags/2.5.1.tar.gz
  URL_HASH MD5=0d8a10fad7f10fa7b4453e647fb6b1a8
)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_options(
    -Wall
    -Wpedantic
    -Wextra
    -fexceptions
    -O0
    -g
    -fsanitize=address
  )
  add_link_options(-fsanitize=address)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  add_compile_options(-O2)
endif()

include_directories(include)

file(GLOB SRC_SNAKE_GAME 
  "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(snake ${SRC_SNAKE_GAME})

target_link_libraries(
 snake
 sfml-graphics
 sfml-window
 sfml-system
 sfml-audio
)
