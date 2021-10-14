#include "pch.h"
#include "GameEngine.h"

#include "Renderer.h"

GameEngine::GameEngine(std::string const& name, int width, int height)
	:m_GameName(name),
	m_Width(width),
	m_Height(height)
{
	
}

GameEngine::~GameEngine()
{
	delete m_pRenderer;
}

void GameEngine::Initialize()
{
	m_pRenderer = new Renderer{ m_GameName, m_Width, m_Height };
}

void GameEngine::Run()
{
	Initialize();

	while (true)
	{
		m_pRenderer->Render();
	}
}
