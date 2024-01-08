#pragma once
#include <GLFW/glfw3.h>

namespace core
{
	enum WindowMode
	{
		Fullscreen,
		Windowed
	};
	class Window
	{
	public:
		Window(const char* name, unsigned width, unsigned height, bool fullscreen);
		~Window();
		[[nodiscard]] bool ShouldClose() const;
		void Clear() const;
		void SwapBuffer() const;
		void PollEvents() const;

	private:
		bool InitWindow();
		GLFWwindow* m_window;
		const char* m_name;
		unsigned m_width;
		unsigned m_height;
		bool m_fullscreen;
	};
}
