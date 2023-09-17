#include "sdl_renderer.h"
#include <iostream>

SDLRenderer::SDLRenderer(SDL_Renderer* renderer)
	: renderer(renderer) {
	font = TTF_OpenFont("SDL2.ttf", 16);
	if (!font) {
		std::cerr << "�� ������� ��������� �����: " << TTF_GetError() << std::endl;
	}
}

void SDLRenderer::drawAxis() {
	// �������� ������ ����
	int windowWidth, windowHeight;
	SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
	// ������������� ���� ������
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	// ������ �������������� ���
	SDL_RenderDrawLine(renderer, 0, windowHeight / 2, windowWidth, windowHeight / 2);

	// ������ ������������ ���
	SDL_RenderDrawLine(renderer, windowWidth / 2, 0, windowWidth / 2, windowHeight);

	// ����� �������� ��� �����, ����� ���������� ������� ���� � ������� ���������� SDL_ttf, ���� ��� ���������
}

void SDLRenderer::drawGraph(const Graph& graph) {
	// ������������� ���� ��� ������� ������ ������ (��������, �������)
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	// �������� ������ ����
	int windowWidth, windowHeight;
	SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

	// ������ ����� �������
	const auto& points = graph.getPoints();
	for (const auto& point : points) {
		int x = windowWidth / 2 + point.first;
		int y = windowHeight / 2 - point.second;

		SDL_RenderDrawPoint(renderer, x, y);
	}

	// ������ ����� ����� ����������������� �������
	for (size_t i = 1; i < points.size(); ++i) {
		int x1 = windowWidth / 2 + points[i - 1].first;
		int y1 = windowHeight / 2 - points[i - 1].second;
		int x2 = windowWidth / 2 + points[i].first;
		int y2 = windowHeight / 2 - points[i].second;

		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	}
}

