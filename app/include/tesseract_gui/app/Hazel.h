#pragma once

// For use by Hazel applications

#include <tesseract_gui/app/core/Base.h>
#include <tesseract_gui/app/core/Application.h>
#include <tesseract_gui/app/core/Layer.h>
#include <tesseract_gui/app/core/Log.h>
#include <tesseract_gui/app/core/Assert.h>
#include <tesseract_gui/app/core/Timestep.h>
#include <tesseract_gui/app/core/Input.h>
#include <tesseract_gui/app/core/KeyCodes.h>
#include <tesseract_gui/app/core/MouseCodes.h>

#include <tesseract_gui/app/imgui/ImGuiLayer.h>

#include <tesseract_gui/app/scene/Scene.h>
#include <tesseract_gui/app/scene/Entity.h>
#include <tesseract_gui/app/scene/ScriptableEntity.h>
#include <tesseract_gui/app/scene/Components.h>

// ---Renderer------------------------
#include <tesseract_gui/app/renderer/Renderer.h>
#include <tesseract_gui/app/renderer/Renderer2D.h>
#include <tesseract_gui/app/renderer/RenderCommand.h>
#include <tesseract_gui/app/renderer/Buffer.h>
#include <tesseract_gui/app/renderer/Shader.h>
#include <tesseract_gui/app/renderer/Framebuffer.h>
#include <tesseract_gui/app/renderer/Texture.h>
#include <tesseract_gui/app/renderer/VertexArray.h>
#include <tesseract_gui/app/renderer/OrthographicCamera.h>
#include <tesseract_gui/app/renderer/OrthographicCameraController.h>
// -----------------------------------
