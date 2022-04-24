# Ray Tracing

### Example Render

![Example Render](image.png "Example Render")

### Getting Started

Initialize project: ```./scripts/init```

Running project:
- ```./scripts/build``` to build project
- ```./scripts/run``` to run project
- ```./scripts/test``` to run tests

Initialize project without using scripts:
- ```cd``` into the root directory of this project
- ```git submodule init``` to initialize git submodules
- ```git submodule update``` to download git submodules
- ```cmake -S . -B build``` to initialize cmake

Run project without using scripts:
- ```cd``` into the root directory of this project
- ```cmake --build build``` to build project
- ```./bin/ray-tracing``` to run project
- ```./bin/ray-tracing-test``` to run tests