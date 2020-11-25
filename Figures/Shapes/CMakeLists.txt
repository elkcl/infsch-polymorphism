project(Shapes)

add_library(ShapesLib circle.cpp polygon.cpp rectangle.cpp square.cpp parallelogram.cpp parallelogram.h)
target_include_directories(ShapesLib PUBLIC ${CMAKE_SOURCE_DIR}/Figures)