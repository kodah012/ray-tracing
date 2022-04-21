cmake_minimum_required(VERSION 3.20)
project(ray-tracing)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Include directories containing header files
set(INCLUDE
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/external/stb
)

# Main library
set(SOURCE_LIB_NAME source_lib)
add_library(${SOURCE_LIB_NAME})
target_include_directories(${SOURCE_LIB_NAME} PUBLIC ${INCLUDE})

# Main executable
add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SOURCE_LIB_NAME})

# Subdirectories
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)

