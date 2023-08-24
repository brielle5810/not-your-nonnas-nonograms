cmake_minimum_required(VERSION 3.25)
project(sfmltest)

set(CMAKE_CXX_STANDARD 17)

add_executable(sfmltest main.cpp board.h rows.cpp rows.h tile.h resources.h board.cpp resources.cpp tile.cpp welcome.h welcome.cpp rows.cpp rows.cpp cols.h cols.cpp)



set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

#include_directories(c:/SFML/include/SFML)
include_directories(.)
target_link_libraries(sfmltest sfml-system sfml-window sfml-graphics sfml-audio)