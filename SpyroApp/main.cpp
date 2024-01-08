#ifdef NDEBUG
# define WIN32_LEAN_AND_MEAN
# define WIN32_EXTRA_LEAN
#endif /* NDEBUG */

#define GLEW_STATIC
#include <GL/glew.h>
#pragma comment(lib, "OpenGl32.lib")
#pragma comment(lib, "glew32s.lib")

#include <GLFW/glfw3.h>
#ifndef NDEBUG
# pragma comment(lib, "glfw3-s.lib")
#else /* !NDEBUG */
# pragma comment(lib, "glfw3-s-d.lib")
#endif /* !NDEBUG */

#include <core/Window.h>

int main(int argc, char** argv)
{
	core::Window w = core::Window("test", 1080, 607, false);
	glewExperimental = true;
	glewInit();
	do
	{
		w.PollEvents();

		w.Clear();

		w.SwapBuffer();
	} while (!w.ShouldClose());
	glfwTerminate();
	return 0;
}

#ifdef NDEBUG
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	return main(0, nullptr);
}
#endif /* NDEBUG */