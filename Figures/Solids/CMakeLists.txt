project(Solids)

add_library(SolidsLib parallelepiped.cpp parallelepiped.h cylinder.cpp cylinder.h cone.h sphere.cpp sphere.h)
target_include_directories(SolidsLib PUBLIC ${CMAKE_SOURCE_DIR}/Figures)
target_include_directories(SolidsLib PUBLIC ${CMAKE_SOURCE_DIR}/Figures/Shapes)