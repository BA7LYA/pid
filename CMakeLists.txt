# --- cmake version ---
cmake_minimum_required(VERSION 3.21)

# --- project ---
project(ba7lya.pid LANGUAGES CXX)

# --- includes ---
include(CTest)
include(GoogleTest)

enable_testing()

# --- build options ---
option(${PROJECT_NAME}_BUILD_BENCHMARK "Build the benchmark" OFF)
option(${PROJECT_NAME}_BUILD_DEMO "Build demo programs" OFF)
option(${PROJECT_NAME}_BUILD_TEST "Build Test" OFF)

# --- dependencies ---
find_package(benchmark CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(ode CONFIG REQUIRED)

# --- target ---
add_library(${PROJECT_NAME} INTERFACE)

# --- include directories ---
target_include_directories(
	${PROJECT_NAME}
	INTERFACE
	${PROJECT_SOURCE_DIR}/include/
)

# --- compile features ---
target_compile_features(
	${PROJECT_NAME}
	INTERFACE
	cxx_std_23
)

# --- link libraries ---
target_link_libraries(
	${PROJECT_NAME}
	INTERFACE
	ODE::ODE
)

# --- benchmarks ---
if(${PROJECT_NAME}_BUILD_BENCHMARK)
    add_subdirectory(benchmark)
endif()

# --- demo ---
if(${PROJECT_NAME}_BUILD_DEMO)
    add_subdirectory(demo)
endif()

# --- unit tests ---
if(${PROJECT_NAME}_BUILD_TEST)
    enable_testing()
    add_subdirectory(test)
endif()
