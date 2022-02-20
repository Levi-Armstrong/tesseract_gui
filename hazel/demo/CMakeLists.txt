add_executable(${PROJECT_NAME}_hazel_demo
  src/HazelnutApp.cpp
  src/EditorLayer.cpp
  src/HazelnutApp.cpp
  src/Panels/ContentBrowserPanel.cpp
  src/Panels/SceneHierarchyPanel.cpp)
target_compile_features(${PROJECT_NAME}_hazel_demo PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME}_hazel_demo PRIVATE
  ${PROJECT_NAME}_hazel)

install_targets(TARGETS ${PROJECT_NAME}_hazel_demo)
