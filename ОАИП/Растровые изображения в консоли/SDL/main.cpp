#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "sdl_renderer.h"
#include "graph.h"

void displayMenu() {
    system("cls");
    std::cout << "�������� ��������:\n";
    std::cout << "1) ������������� ����� �� �����\n";
    std::cout << "2) �������� ����� �� ������\n";
    std::cout << "3) ����������� ���������� �������\n";
    std::cout << "4) �������������� ������ � ����\n";
    std::cout << "5) ����� ������� ����� �� �����\n";
    std::cout << "6) ����� �� ���������\n";
    std::cout << "\n��� �����: ";
}

int main(int argc, char* argv[]) {
    // �������������� SDL
    setlocale(0, "rus");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { // ������������� SDL
        std::cerr << "�� ������� ���������������� SDL: " << SDL_GetError() << std::endl;
        return 1;
    }
    // �������������� SDL_ttf
    if (TTF_Init() < 0) { // ������������� SDL_ttf
        std::cerr << "�� ������� ���������������� SDL_ttf: " << TTF_GetError() << std::endl;
        return 1;
    }

    int screenWidth, screenHeight;
    std::cout << "������� ������ ������: ";
    std::cin >> screenWidth;
    std::cout << "������� ������ ������: ";
    std::cin >> screenHeight;

    // ������� ����
    SDL_Window* window = SDL_CreateWindow("Grafics by Velutich", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN); // �������� ���� � ��� ���������
    if (!window) {
        std::cerr << "�� ������� ������� ����: " << SDL_GetError() << std::endl;
        return 1;
    }

    // ������� ��������
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cerr << "�� ������� ������� ��������: " << SDL_GetError() << std::endl;
        return 1;
    }

    // ������� ��������� SDLRenderer
    SDLRenderer sdlRenderer(renderer);

    // ������� ��������� Graph � ��������� ��������� �����
    Graph graph;

    bool running = true;
    while (running) {
        displayMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // ��������� � ������������ �������� �����
            std::cout << "������� �������� �����: ";
            std::string fileName;
            std::cin >> fileName;

            // ��������� ������ � ������ ������� �� �����
            try {
                graph.loadFromFile(fileName);
                std::cout << "������ ������� ��������� �� ����� " << fileName << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << "������: " << e.what() << std::endl;
            }
            system("pause");
            break;
        }

        case 2: {
            int numPoints;
            std::cout << "������� ����� �� ������ �������� �� ������? ";
            std::cin >> numPoints;

            double x, y;
            for (int i = 0; i < numPoints; i++) {
                std::cout << "������� ���������� x ��� ����� " << i + 1 << ": ";
                std::cin >> x;
                std::cout << "������� ���������� y ��� ����� " << i + 1 << ": ";
                std::cin >> y;

                // ���������, ����� ���������� ���� � �������� �������� ������
                if (x < -screenWidth || x > screenWidth || y < -screenHeight || y > screenHeight) {
                    std::cerr << "���������� ��� �������� ������. ���������� �����.\n";
                    i--; // ��������� ���� ��� ���� �����
                }
                else {
                    graph.addPoint(x, y);
                }
            }
            break;
        }

        case 3: {
            std::cout << "�� ������ ������ ESC �������� � ���� ������� ��� ��������� � ����" << std::endl;
            bool displayGraph = true;
            while (displayGraph) {
                SDL_Event e;
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) {
                        displayGraph = false;
                        running = false; // ����� �� ���������
                    }
                    else if (e.type == SDL_KEYDOWN) {
                        if (e.key.keysym.sym == SDLK_ESCAPE) { // ���� ������ ������� ESC
                            displayGraph = false; // ������������ � ������� ����
                        }
                        else if (e.key.keysym.sym == SDLK_q) { // ���� ������ ������� Q
                            displayGraph = false;
                            running = false; // ����� �� ���������
                        }
                    }
                }

                // ������� �����
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderClear(renderer);

                // ������ ������������ ��� � ������
                sdlRenderer.drawAxis();
                sdlRenderer.drawGraph(graph);

                // ��������� �����
                SDL_RenderPresent(renderer);
            }
            break;
        }

        case 4: {
            // ��������� � ������������ �������� �����
            std::cout << "������� �������� �����: ";
            std::string fileName;
            std::cin >> fileName;

            // ��������� ������ � ������ ������� � ����
            try {
                graph.saveToFile(fileName);
                std::cout << "������ ������� ��������� � ���� " << fileName << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << "������: " << e.what() << std::endl;
            }
            system("pause");
            break;
        }
        case 6: {
            running = false;
            break;
        }

        case 5: {
            // ������� ����� �� �����
            const auto& points = graph.getPoints();
            if (points.empty()) {
                std::cout << "������ ����, ��� ����� ��� ������." << std::endl;
            }
            else {
                std::cout << "������� ����� �������:" << std::endl;
                for (const auto& point : points) {
                    std::cout << point.first << ", " << point.second << std::endl;
                }
            }
            system("pause");
            break;
        }

        default: {
            std::cout << "����������� �����. ���������� �����.\n";
        }

        }
    }

    // ������ ������
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}