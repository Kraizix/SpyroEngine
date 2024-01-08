#include <stdexcept>
#include <core/Window.h>

using namespace core;
Window::Window(const char* name, unsigned width, unsigned height, bool fullscreen)
	: m_window(nullptr), m_name(name), m_width(width), m_height(height), m_fullscreen(fullscreen)
{
	if (!InitWindow())
		throw std::runtime_error("Unable to initialize GLFW");
}

Window::~Window()
{
	glfwDestroyWindow(m_window);
}

bool Window::InitWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#ifndef NDEBUG
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#else /* !NDEBUG */
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_FALSE);
#endif /* !NDEBUG */
	glfwWindowHint(GLFW_SRGB_CAPABLE, GL_TRUE);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
	m_window = glfwCreateWindow(m_width, m_height, m_name, m_fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
	if (!m_window)
		return false;
	glfwMakeContextCurrent(m_window);
	return true;
}

bool Window::ShouldClose() const
{
	return glfwWindowShouldClose(m_window);
}

void Window::Clear() const
{
	glClearColor(0.f, 0.f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::SwapBuffer() const
{
	glfwSwapBuffers(m_window);
}

void Window::PollEvents() const
{
	glfwPollEvents();
}

