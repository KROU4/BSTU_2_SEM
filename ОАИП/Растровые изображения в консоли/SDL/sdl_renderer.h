// ������������ ���� SDLRenderer, ����������� ����� SDLRenderer � ��� ������
#pragma once

#include "graph.h"
#include <SDL.h>
#include <SDL_ttf.h>

class SDLRenderer {
public:
	// �����������, ������� ��������� SDL_Renderer
	explicit SDLRenderer(SDL_Renderer* renderer);
	// ������ ��������� ���� � �������
	void drawAxis();
	void drawGraph(const Graph& graph);
	// ����� ��������� ����������� ����
	void drawLabeledAxis();

private:
	// ���������� ���� SDL_Renderer, ������������ ��� ��������� �������
	SDL_Renderer* renderer;
	// ��������� �� �����, ������������ ��� ������� ����
	TTF_Font* font;
};