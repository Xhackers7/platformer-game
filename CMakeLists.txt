cmake_minimum_required(VERSION 3.2)
project(platformer VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -pedantic -g3 -Og")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -DNDEBUG")


set(SFML_INCLUDE_DIR "./libs/SFML/include")
set(SFML_LIBRARY_DIR "./libs/SFML/lib")
set(SFML_DIR "./libs/SFML/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

include(CTest)
enable_testing()

include_directories(include)

file( GLOB_RECURSE SRC src/*.cpp )
add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries (${PROJECT_NAME} sfml-graphics sfml-window sfml-audio sfml-system)
message(STATUS "${PROJECT_SOURCE_DIR}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
