# --- CMake Version ---
cmake_minimum_required(VERSION 3.21)

# --- Project ---
project(PIDController LANGUAGES CXX)

# --- Includes ---
include(CTest)
include(GoogleTest)

enable_testing()

# --- Build Options ---
option(${PROJECT_NAME}_BUILD_BENCHMARK "Build the benchmark" OFF)
option(${PROJECT_NAME}_BUILD_DEMO "Build demo programs" OFF)
option(${PROJECT_NAME}_BUILD_TEST "Build Test" OFF)

find_package(benchmark CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(ode CONFIG REQUIRED)

# --- Modules ---
add_subdirectory(benchmark)
add_subdirectory(demo)
add_subdirectory(test)

# --- Target ---
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(
	${PROJECT_NAME}
	INTERFACE
	${PROJECT_SOURCE_DIR}/src/include/
)

# --- Compile Feature ---
target_compile_features(
	${PROJECT_NAME}
	INTERFACE
	cxx_std_23
)

target_link_libraries(
	${PROJECT_NAME}
	INTERFACE
	ODE::ODE
)