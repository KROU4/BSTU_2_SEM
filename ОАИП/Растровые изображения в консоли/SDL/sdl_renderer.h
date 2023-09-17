// заголовочный файл SDLRenderer, объ€вл€ющий класс SDLRenderer и его методы
#pragma once

#include "graph.h"
#include <SDL.h>
#include <SDL_ttf.h>

class SDLRenderer {
public:
	// конструктор, который принимает SDL_Renderer
	explicit SDLRenderer(SDL_Renderer* renderer);
	// методы отрисовки осей и графика
	void drawAxis();
	void drawGraph(const Graph& graph);
	// метод отрисовки подписанных осей
	void drawLabeledAxis();

private:
	// переменна€ типа SDL_Renderer, используема€ дл€ отрисовки графики
	SDL_Renderer* renderer;
	// указатель на шрифт, используемый дл€ подписи осей
	TTF_Font* font;
};