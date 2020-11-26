project(Solids)

add_library(SolidsLib parallelepiped.h cylinder.h cone.h sphere.cpp sphere.h rect_parallelepiped.h cube.h solids.h)
target_include_directories(SolidsLib PUBLIC ${CMAKE_SOURCE_DIR}/Figures)
target_include_directories(SolidsLib PUBLIC ${CMAKE_SOURCE_DIR}/Figures/Shapes)