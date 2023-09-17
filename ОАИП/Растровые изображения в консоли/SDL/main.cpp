#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "sdl_renderer.h"
#include "graph.h"

void displayMenu() {
    system("cls");
    std::cout << "Выберите действие:\n";
    std::cout << "1) Импортировать точки из файла\n";
    std::cout << "2) Добавить точки на график\n";
    std::cout << "3) Отображение финального графика\n";
    std::cout << "4) Экспортировать данные в файл\n";
    std::cout << "5) Вывод текущих точек на экран\n";
    std::cout << "6) Выход из программы\n";
    std::cout << "\nВаш выбор: ";
}

int main(int argc, char* argv[]) {
    // Инициализируем SDL
    setlocale(0, "rus");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { // Инициализация SDL
        std::cerr << "Не удалось инициализировать SDL: " << SDL_GetError() << std::endl;
        return 1;
    }
    // Инициализируем SDL_ttf
    if (TTF_Init() < 0) { // Инициализация SDL_ttf
        std::cerr << "Не удалось инициализировать SDL_ttf: " << TTF_GetError() << std::endl;
        return 1;
    }

    int screenWidth, screenHeight;
    std::cout << "Введите ширину экрана: ";
    std::cin >> screenWidth;
    std::cout << "Введите высоту экрана: ";
    std::cin >> screenHeight;

    // Создаем окно
    SDL_Window* window = SDL_CreateWindow("Grafics by Velutich", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN); // Название окна и его параметры
    if (!window) {
        std::cerr << "Не удалось создать окно: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Создаем рендерер
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cerr << "Не удалось создать рендерер: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Создаем экземпляр SDLRenderer
    SDLRenderer sdlRenderer(renderer);

    // Создаем экземпляр Graph и добавляем несколько точек
    Graph graph;

    bool running = true;
    while (running) {
        displayMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Запросить у пользователя название файла
            std::cout << "Введите название файла: ";
            std::string fileName;
            std::cin >> fileName;

            // Загрузить данные о точках графика из файла
            try {
                graph.loadFromFile(fileName);
                std::cout << "Данные успешно загружены из файла " << fileName << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }
            system("pause");
            break;
        }

        case 2: {
            int numPoints;
            std::cout << "Сколько точек вы хотите добавить на график? ";
            std::cin >> numPoints;

            double x, y;
            for (int i = 0; i < numPoints; i++) {
                std::cout << "Введите координату x для точки " << i + 1 << ": ";
                std::cin >> x;
                std::cout << "Введите координату y для точки " << i + 1 << ": ";
                std::cin >> y;

                // Проверяем, чтобы координаты были в пределах размеров экрана
                if (x < -screenWidth || x > screenWidth || y < -screenHeight || y > screenHeight) {
                    std::cerr << "Координаты вне пределов экрана. Попробуйте снова.\n";
                    i--; // Повторяем ввод для этой точки
                }
                else {
                    graph.addPoint(x, y);
                }
            }
            break;
        }

        case 3: {
            std::cout << "Вы можете нажать ESC находясь в окне графика для возварата в меню" << std::endl;
            bool displayGraph = true;
            while (displayGraph) {
                SDL_Event e;
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) {
                        displayGraph = false;
                        running = false; // Выход из программы
                    }
                    else if (e.type == SDL_KEYDOWN) {
                        if (e.key.keysym.sym == SDLK_ESCAPE) { // Если нажата клавиша ESC
                            displayGraph = false; // Возвращаемся в главное меню
                        }
                        else if (e.key.keysym.sym == SDLK_q) { // Если нажата клавиша Q
                            displayGraph = false;
                            running = false; // Выход из программы
                        }
                    }
                }

                // Очищаем экран
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderClear(renderer);

                // Рисуем координатные оси и график
                sdlRenderer.drawAxis();
                sdlRenderer.drawGraph(graph);

                // Обновляем экран
                SDL_RenderPresent(renderer);
            }
            break;
        }

        case 4: {
            // Запросить у пользователя название файла
            std::cout << "Введите название файла: ";
            std::string fileName;
            std::cin >> fileName;

            // Сохранить данные о точках графика в файл
            try {
                graph.saveToFile(fileName);
                std::cout << "Данные успешно сохранены в файл " << fileName << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }
            system("pause");
            break;
        }
        case 6: {
            running = false;
            break;
        }

        case 5: {
            // Вывести точки на экран
            const auto& points = graph.getPoints();
            if (points.empty()) {
                std::cout << "График пуст, нет точек для вывода." << std::endl;
            }
            else {
                std::cout << "Текущие точки графика:" << std::endl;
                for (const auto& point : points) {
                    std::cout << point.first << ", " << point.second << std::endl;
                }
            }
            system("pause");
            break;
        }

        default: {
            std::cout << "Неизвестный выбор. Попробуйте снова.\n";
        }

        }
    }

    // Чистим память
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}