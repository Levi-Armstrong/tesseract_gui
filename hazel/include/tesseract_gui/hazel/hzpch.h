#pragma once

#include <tesseract_gui/hazel/core/PlatformDetection.h>

#ifdef HZ_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <tesseract_gui/hazel/core/Base.h>
#include <tesseract_gui/hazel/core/Log.h>
#include <tesseract_gui/hazel/debug/Instrumentor.h>

#ifdef HZ_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
