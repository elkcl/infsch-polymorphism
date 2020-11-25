file(REMOVE_RECURSE
  "libPrimitives.a"
  "libPrimitives.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Primitives.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
