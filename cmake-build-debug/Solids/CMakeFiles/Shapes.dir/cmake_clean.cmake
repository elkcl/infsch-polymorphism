file(REMOVE_RECURSE
  "libShapes.a"
  "libShapes.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Shapes.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
