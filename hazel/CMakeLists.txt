find_package(tesseract_common REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(spdlog REQUIRED)
find_package(glm REQUIRED)
find_package(stb REQUIRED)
find_package(yaml-cpp REQUIRED)

# Load variable for clang tidy args, compiler options and cxx version
tesseract_variables()

add_library(${PROJECT_NAME}_hazel SHARED
  src/core/Application.cpp
  src/core/Layer.cpp
  src/core/LayerStack.cpp
  src/core/Log.cpp
  src/core/Window.cpp
  src/imgui/ImGuiBuild.cpp
  src/imgui/ImGuiLayer.cpp
  src/math/Math.cpp
  src/platform/Windows/WindowsInput.cpp
  src/platform/Windows/WindowsPlatformUtils.cpp
  src/platform/Windows/WindowsWindow.cpp
  src/platform/OpenGL/OpenGLBuffer.cpp
  src/platform/OpenGL/OpenGLContext.cpp
  src/platform/OpenGL/OpenGLFramebuffer.cpp
  src/platform/OpenGL/OpenGLRendererAPI.cpp
  src/platform/OpenGL/OpenGLShader.cpp
  src/platform/OpenGL/OpenGLTexture.cpp
  src/platform/OpenGL/OpenGLUniformBuffer.cpp
  src/platform/OpenGL/OpenGLVertexArray.cpp
  src/renderer/Buffer.cpp
  src/renderer/EditorCamera.cpp
  src/renderer/Framebuffer.cpp
  src/renderer/GraphicsContext.cpp
  src/renderer/OrthographicCamera.cpp
  src/renderer/OrthographicCameraController.cpp
  src/renderer/RenderCommand.cpp
  src/renderer/Renderer.cpp
  src/renderer/Renderer2D.cpp
  src/renderer/RendererAPI.cpp
  src/renderer/Shader.cpp
  src/renderer/Texture.cpp
  src/renderer/UniformBuffer.cpp
  src/renderer/VertexArray.cpp
  src/scene/Entity.cpp
  src/scene/Scene.cpp
  src/scene/SceneCamera.cpp
  src/scene/SceneSerializer.cpp
  )
target_compile_features(${PROJECT_NAME}_hazel PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME}_hazel PUBLIC
  imgui
  imgui_glfw
  imgui_opengl3
  glfw
  ${OPENGL_LIBRARIES}
  glad
  yaml-cpp
  spdlog::spdlog
  glm::glm
  ${stb_LIBRARIES})
target_include_directories(${PROJECT_NAME}_hazel PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>")
target_include_directories(${PROJECT_NAME}_hazel SYSTEM PUBLIC
    ${OPENGL_INCLUDE_DIRS}
    ${stb_INCLUDE_DIRS})

add_subdirectory(demo)

# Mark cpp header files for installation
install(DIRECTORY include/${PROJECT_NAME}
  DESTINATION include
)

install_targets(TARGETS
  ${PROJECT_NAME}_hazel
  glad)
