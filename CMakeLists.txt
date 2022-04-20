cmake_minimum_required(VERSION 3.20)
project(ray-tracing)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(SOURCE_FILES
  ${PROJECT_SOURCE_DIR}/src/Main.cpp
)
set(INCLUDE
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/external/stb
)

# Main executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})

# Main library for testing
set(SOURCE_LIB_NAME source_lib)
add_library(${SOURCE_LIB_NAME} ${SOURCE_FILES})
target_include_directories(${SOURCE_LIB_NAME} PUBLIC ${INCLUDE})

# Subdirectories
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)

