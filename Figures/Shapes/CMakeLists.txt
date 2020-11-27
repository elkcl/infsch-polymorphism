project(Shapes)

add_library(ShapesLib STATIC circle.cpp polygon.cpp rectangle.cpp square.cpp parallelogram.cpp)
target_include_directories(ShapesLib PUBLIC ${CMAKE_SOURCE_DIR}/Figures)