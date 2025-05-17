# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/DeepSeekPlugin_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/DeepSeekPlugin_autogen.dir/ParseCache.txt"
  "DeepSeekPlugin_autogen"
  )
endif()
