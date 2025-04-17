#include "visual.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <chrono>
#include <thread>
#include "anthill.h"

using namespace std;
using namespace chrono_literals;

// Цвета для статусов
const string COLOR_ACTIVE = "\033[32m";   // Зеленый
const string COLOR_INACTIVE = "\033[31m"; // Красный
const string COLOR_RESET = "\033[0m";


void Visualizer::enableVTMode() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif
}

void Visualizer::visualize(Anthill& anthill) {
    SetConsoleOutputCP(CP_UTF8); // Для кириллицы
    enableVTMode();

    while (true) {
        system("cls || clear");
        int totalAnts = anthill.get_size();
        int activeAnts = 0;

        // Первый проход: подсчет активных муравьев
        for (int i = 0; i < totalAnts; ++i) {
            Ant* ant = anthill.get_ant(i);
            if (ant && ant->get_status()) activeAnts++;
        }

        // Вывод статистики
        cout << "=== Статистика ===" << endl;
        cout << "Муравьев: " << totalAnts << endl;
        cout << COLOR_ACTIVE << "Активных: " << activeAnts << COLOR_RESET << endl;
        cout << COLOR_INACTIVE << "Неактивных: " << (totalAnts - activeAnts) << COLOR_RESET << endl;
        cout << "Еда: " << anthill.get_food_count() << endl;
        cout << "Ветки: " << anthill.get_branches() << endl << endl;

        // Вывод муравьев
        int counter = 0;
        for (int i = 0; i < totalAnts; ++i) {
            Ant* ant = anthill.get_ant(i);
            if (!ant) continue;

            // Цвет по статусу
            string color = ant->get_status() ? COLOR_INACTIVE:COLOR_ACTIVE;

            // Символ по роли
            char symbol = 'K';
            Role* role = ant->get_role();
            if (role) {
                switch (role->get_number()) {
                case 0: symbol = 'N'; break;
                case 1: symbol = 'S'; break;
                case 2: symbol = 'H'; break;
                case 3: symbol = 'C'; break;
                case 4: symbol = 'B'; break;
                case 5: symbol = 'L'; break;
                }
            }

            cout << color << symbol << COLOR_RESET << " ";
            if (++counter % 10 == 0) cout << endl;
        }

        this_thread::sleep_for(1000ms);
    }
}

