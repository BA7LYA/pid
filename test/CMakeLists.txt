# --- CMake Version ---
cmake_minimum_required(VERSION 3.21)

# --- Taget ---
add_executable(${PROJECT_NAME}_test)

# --- Sources ---
target_sources(
	${PROJECT_NAME}_test
	PRIVATE
    ${PROJECT_SOURCE_DIR}/test/test.cxx
)

# --- Linakge ---
target_link_libraries(
	${PROJECT_NAME}_test
	PRIVATE
	${PROJECT_NAME}
	GTest::gtest
	GTest::gtest_main
)

# --- Compile Feature ---
target_compile_features(
	${PROJECT_NAME}_test
	PRIVATE
	cxx_std_23
)

gtest_discover_tests(${PROJECT_NAME}_test)