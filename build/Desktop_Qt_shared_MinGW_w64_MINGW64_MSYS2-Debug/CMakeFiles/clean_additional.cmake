# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\kolibritestovoe_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\kolibritestovoe_autogen.dir\\ParseCache.txt"
  "kolibritestovoe_autogen"
  )
endif()
