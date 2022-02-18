cmake_minimum_required(VERSION 2.8)
project(imgui C CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Freetype REQUIRED)

add_library(${PROJECT_NAME}
  src/imgui.cpp
  src/imgui_draw.cpp
  src/imgui_demo.cpp
  src/imgui_tables.cpp
  src/imgui_widgets.cpp
  src/imgui_themes.cpp
  src/cpp/imgui_stdlib.cpp
  src/freetype/imgui_freetype.cpp)
target_link_libraries(${PROJECT_NAME} ${FREETYPE_LIBRARIES})
target_compile_definitions(${PROJECT_NAME} PUBLIC -DImTextureID=ImU64)
target_compile_definitions(${PROJECT_NAME} PUBLIC INTERFACE IMGUI_SHARE_DIR="${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>")
target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC
    ${FREETYPE_INCLUDE_DIRS})

add_library(${PROJECT_NAME}_glut src/backends/imgui_impl_glut.cpp)
target_link_libraries(${PROJECT_NAME}_glut imgui ${GLUT_LIBRARIES})
target_compile_definitions(${PROJECT_NAME}_glut PUBLIC -DImTextureID=ImU64)
target_compile_features(${PROJECT_NAME}_glut PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME}_glut PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>")
target_include_directories(${PROJECT_NAME}_glut SYSTEM PUBLIC
    ${GLUT_INCLUDE_DIRS})

add_library(${PROJECT_NAME}_opengl2 src/backends/imgui_impl_opengl2.cpp)
target_link_libraries(${PROJECT_NAME}_opengl2 ${OPENGL_LIBRARIES})
target_compile_definitions(${PROJECT_NAME}_opengl2 PUBLIC -DImTextureID=ImU64)
target_compile_features(${PROJECT_NAME}_opengl2 PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME}_opengl2 PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>")
target_include_directories(${PROJECT_NAME}_opengl2 SYSTEM PUBLIC
    ${OPENGL_INCLUDE_DIRS})

install(
  DIRECTORY include/${PROJECT_NAME}
  DESTINATION include)

foreach(dir fonts)
  install(DIRECTORY ${dir}/ DESTINATION share/${PROJECT_NAME}/${dir})
endforeach()

install(
  TARGETS
    ${PROJECT_NAME}
    ${PROJECT_NAME}_glut
    ${PROJECT_NAME}_opengl2
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
