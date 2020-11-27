project(Solids)

add_library(SolidsLib STATIC sphere.cpp)
target_include_directories(SolidsLib PUBLIC ${CMAKE_SOURCE_DIR}/Figures)
target_include_directories(SolidsLib PUBLIC ${CMAKE_SOURCE_DIR}/Figures/Shapes)