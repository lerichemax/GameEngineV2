#include "pch.h"
#include "Renderer.h"

#include <cstring>

Renderer::Renderer(std::string const& name, int width, int height)
	:m_pWindow(nullptr),
	m_pRenderer(nullptr)
{
	m_pWindow = SDL_CreateWindow(
		name.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_OPENGL
	);

	if (m_pWindow == nullptr)
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}
	
	m_pRenderer = SDL_CreateRenderer(m_pWindow, GetOpenGLDriverIndex(), SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_pRenderer == nullptr)
	{
		throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
	}
	SDL_SetRenderDrawBlendMode(m_pRenderer, SDL_BLENDMODE_BLEND);
}

Renderer::~Renderer()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
}

void Renderer::Render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,1);
	SDL_RenderClear(m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
}


int Renderer::GetOpenGLDriverIndex()
{
	int oglIdx = -1;
	int nRD = SDL_GetNumRenderDrivers();
	for (int i = 0; i < nRD; i++)
	{
		SDL_RendererInfo info;
		if (!SDL_GetRenderDriverInfo(i, &info))
		{
			if (!strcmp(info.name, "opengl"))
			{
				oglIdx = i;
			}
		}
	}
	return oglIdx;
}