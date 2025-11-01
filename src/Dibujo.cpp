#include "Dibujo.hpp"
using namespace ftxui;

void Dibujo::Dibujar(Screen& screen) const {
    for (size_t i = 0; i < figura.size(); ++i) {
        const auto& linea = figura[i];
        for (size_t j = 0; j < linea.size(); ++j) {
            if (x + j >= 0 && y + i >= 0 && 
                x + j < screen.dimx() && y + i < screen.dimy()) {
                screen.PixelAt(x + j, y + i).character = linea[j];
                screen.PixelAt(x + j, y + i).foreground_color = color;
            }
        }
    }
}