set(MAIN_FILE Main.cpp)
set(SOURCE_FILES
  Camera.cpp
  HitRecord.cpp
  HittableList.cpp
  Ray.cpp
  Sphere.cpp
  Vec3.cpp
)

# Add Main.cpp to main executable
target_sources(${MAIN_EXE_NAME} PRIVATE ${MAIN_FILE})

# Add source files to source library
target_sources(${SOURCE_LIB_NAME} PUBLIC ${SOURCE_FILES})
