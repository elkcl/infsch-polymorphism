cmake_minimum_required(VERSION 3.17)
project(polymorphism)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Figures/Shapes)
add_subdirectory(Figures/Solids)

add_executable(SolidTest solidtest.cpp)
target_include_directories(SolidTest PUBLIC ${CMAKE_SOURCE_DIR}/Figures)
target_include_directories(SolidTest PUBLIC ${CMAKE_SOURCE_DIR}/Figures/Shapes)
target_include_directories(SolidTest PUBLIC ${CMAKE_SOURCE_DIR}/Figures/Solids)
target_link_libraries(SolidTest ShapesLib SolidsLib)