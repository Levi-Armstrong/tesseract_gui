find_package(tesseract_common REQUIRED)
find_package(glfw3 REQUIRED)

# Load variable for clang tidy args, compiler options and cxx version
tesseract_variables()

add_library(${PROJECT_NAME}_imgui SHARED
  src/imgui_widget.cpp
  src/imgui_manager.cpp)
target_link_libraries(${PROJECT_NAME}_imgui PUBLIC imgui)
target_include_directories(${PROJECT_NAME}_imgui PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>")

add_library(${PROJECT_NAME}_imgui_glfw SHARED src/imgui_manager_glfw.cpp)
target_link_libraries(${PROJECT_NAME}_imgui_glfw PUBLIC
  ${PROJECT_NAME}_imgui
  imgui
  imgui_glfw
  imgui_opengl3)
target_include_directories(${PROJECT_NAME}_imgui_glfw PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>")

add_executable(${PROJECT_NAME}_imgui_glfw_demo demo/glfw_demo.cpp )
target_link_libraries(${PROJECT_NAME}_imgui_glfw_demo PRIVATE
  ${PROJECT_NAME}_imgui_glfw)

# Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}
  DESTINATION include
)

install_targets(TARGETS
  ${PROJECT_NAME}_imgui
  ${PROJECT_NAME}_imgui_glfw
  ${PROJECT_NAME}_imgui_glfw_demo
  imgui
  imgui_glfw
  imgui_opengl3)
