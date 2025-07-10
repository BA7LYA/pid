# --- CMake Version ---
cmake_minimum_required(VERSION 3.21)

# --- example_01 ---
add_executable(${PROJECT_NAME}_example_01)
target_sources(${PROJECT_NAME}_example_01 PRIVATE example_01.cxx)
target_link_libraries(${PROJECT_NAME}_example_01 PRIVATE ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME}_example_01 PRIVATE cxx_std_23)

# --- example_temp ---
add_executable(${PROJECT_NAME}_example_temp)
target_sources(${PROJECT_NAME}_example_temp PRIVATE example_temp.cxx)
target_link_libraries(${PROJECT_NAME}_example_temp PRIVATE ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME}_example_temp PRIVATE cxx_std_23)
