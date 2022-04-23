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

# Source library
set(SOURCE_LIB_NAME main_lib)
add_library(${SOURCE_LIB_NAME})
target_include_directories(${SOURCE_LIB_NAME} PUBLIC ${INCLUDE})

# Main executable
set(MAIN_EXE_NAME ${PROJECT_NAME})
add_executable(${MAIN_EXE_NAME})
target_link_libraries(${MAIN_EXE_NAME} PRIVATE ${SOURCE_LIB_NAME})

# Subdirectories
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

# Tests
set(BUILD_TESTS ON)
if(BUILD_TESTS)
  add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
endif()

