#pragma once
#include <string>

struct SDL_Window;
struct SDL_Renderer;
class Renderer final
{
public:
	Renderer(std::string const& name, int width, int height);
	~Renderer();
	void Render();
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	
	int GetOpenGLDriverIndex();
};