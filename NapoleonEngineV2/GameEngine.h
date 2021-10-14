#pragma once
#include <string>

class Renderer;
class GameEngine
{
public:
	GameEngine(std::string const& name, int width, int height);
	~GameEngine();
	void Run();
private:
	std::string m_GameName;
	int m_Width;
	int m_Height;

	Renderer* m_pRenderer;

	void Initialize();
};
