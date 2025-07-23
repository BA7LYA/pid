# --- CMake Version ---
cmake_minimum_required(VERSION 3.21)

# --- example_1_order ---
add_executable(${PROJECT_NAME}_example_1_order)
target_sources(${PROJECT_NAME}_example_1_order PRIVATE example_1_order.cxx)
target_link_libraries(${PROJECT_NAME}_example_1_order PRIVATE ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME}_example_1_order PRIVATE cxx_std_23)

# --- example_2_order ---
add_executable(${PROJECT_NAME}_example_2_order)
target_sources(${PROJECT_NAME}_example_2_order PRIVATE example_2_order.cxx)
target_link_libraries(${PROJECT_NAME}_example_2_order PRIVATE ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME}_example_2_order PRIVATE cxx_std_23)

# --- example_n_order ---
add_executable(${PROJECT_NAME}_example_n_order)
target_sources(${PROJECT_NAME}_example_n_order PRIVATE example_n_order.cxx)
target_link_libraries(${PROJECT_NAME}_example_n_order PRIVATE ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME}_example_n_order PRIVATE cxx_std_23)

# --- example_dc_motor ---
add_executable(${PROJECT_NAME}_example_dc_motor)
target_sources(${PROJECT_NAME}_example_dc_motor PRIVATE example_dc_motor.cxx)
target_link_libraries(${PROJECT_NAME}_example_dc_motor PRIVATE ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME}_example_dc_motor PRIVATE cxx_std_23)

# --- example_temp ---
add_executable(${PROJECT_NAME}_example_temp)
target_sources(${PROJECT_NAME}_example_temp PRIVATE example_temp.cxx)
target_link_libraries(${PROJECT_NAME}_example_temp PRIVATE ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME}_example_temp PRIVATE cxx_std_23)
