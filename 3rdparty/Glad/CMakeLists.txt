cmake_minimum_required(VERSION 2.8)
project(glad C)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(tesseract_common REQUIRED)

# Load variable for clang tidy args, compiler options and cxx version
tesseract_variables()

add_library(${PROJECT_NAME} SHARED src/glad.c)
target_link_libraries(${PROJECT_NAME} PUBLIC)
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>")

# Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}
  DESTINATION include
)

install(
  TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
