# GoogleTest
add_subdirectory(${PROJECT_SOURCE_DIR}/external/googletest external/googletest)

enable_testing()
include(GoogleTest)

# Keep CACHE cleaner
mark_as_advanced(
  BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
  gmock_build_tests gtest_build_samples gtest_build_tests
  gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

# Keep IDEs that support folders clean
set_target_properties(gtest PROPERTIES FOLDER external)
set_target_properties(gtest_main PROPERTIES FOLDER external)
set_target_properties(gmock PROPERTIES FOLDER external)
set_target_properties(gmock_main PROPERTIES FOLDER external)

set(TEST_EXECUTABLE_NAME ray-tracing-test)
set(TEST_FILES
  Vec3Test.cpp
  RayTest.cpp
)

add_executable(${TEST_EXECUTABLE_NAME} ${TEST_FILES})
target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE gtest gmock gtest_main ${SOURCE_LIB_NAME})
gtest_discover_tests(${TEST_EXECUTABLE_NAME})