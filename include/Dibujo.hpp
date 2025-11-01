#pragma once
#include <ftxui/screen/screen.hpp>
#include <vector>
#include <string>

class Dibujo {
public:
    int x, y;
    std::vector<std::u32string> figura;
    ftxui::Color color;

    Dibujo(int x, int y, std::vector<std::u32string> figura, ftxui::Color color)
        : x(x), y(y), figura(figura), color(color) {}

    void Dibujar(ftxui::Screen& screen) const;
};