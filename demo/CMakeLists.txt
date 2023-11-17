# --- CMake Version ---
cmake_minimum_required(VERSION 3.21)

# --- Taget ---
add_executable(${PROJECT_NAME}_demo)

# --- Sources ---
target_sources(
	${PROJECT_NAME}_demo
	PRIVATE
    ${PROJECT_SOURCE_DIR}/demo/demo.cxx
)

# --- Linakge ---
target_link_libraries(
	${PROJECT_NAME}_demo
	PRIVATE
	${PROJECT_NAME}
)

# --- Compile Feature ---
target_compile_features(
	${PROJECT_NAME}_demo
	PRIVATE
	cxx_std_23
)