set(MAIN_FILE Main.cpp)
set(SOURCE_FILES
  Vec3.cpp
  Ray.cpp
)

# Add Main.cpp to main executable
target_sources(${MAIN_EXE_NAME} PRIVATE ${MAIN_FILE})

# Add source files to source library
target_sources(${SOURCE_LIB_NAME} PUBLIC ${SOURCE_FILES})
