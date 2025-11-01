#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
#include <Corral.hpp>
using namespace ftxui;

int main() {
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24)
    );

    //edificios
    const std::vector<std::u32string> edificio1 = {
        U"  |‾‾‾|",
        U"  |   |",
        U"  |   |",
        U"  |___|"
    };

    const std::vector<std::u32string> edificio2 = {
        U"  |‾‾‾‾‾|",
        U"  |     |",
        U"  |     |",
        U"  |_____|"
    };

    //sol
    const std::vector<std::u32string> sol = {
        U" \\ | / ",
        U" --O-- ",
        U" / | \\ "
    };

    //auto rojo
    const std::vector<std::u32string> auto_rojo = {
        U"   ______",
        U" _/[] []\\_",
        U"(_________)",
        U"  O     O "
    };

    //auto azul
    const std::vector<std::u32string> auto_azul = {
        U"   ______",
        U" _/[][]\\_",
        U"(________)",
        U"  o     o"
    };

    //arbol
    const std::vector<std::u32string> arbol = {
        U"   &&&  ",
        U"  &&&&& ",
        U"   |||  "
    };

    GestorDibujos gestor;

    //edificios de fondo
    gestor.Agregar(Dibujo(5, 5, edificio1, Color::GrayLight));
    gestor.Agregar(Dibujo(15, 4, edificio2, Color::GrayLight));
    gestor.Agregar(Dibujo(30, 6, edificio1, Color::GrayLight));
    gestor.Agregar(Dibujo(45, 4, edificio2, Color::GrayLight));
    gestor.Agregar(Dibujo(60, 5, edificio1, Color::GrayLight));

    //sol
    gestor.Agregar(Dibujo(10, 1, sol, Color::YellowLight));

    //arboles
    gestor.Agregar(Dibujo(10, 17, arbol, Color::Green));
    gestor.Agregar(Dibujo(40, 17, arbol, Color::Green));
    gestor.Agregar(Dibujo(70, 17, arbol, Color::Green));

    //autos
    gestor.Agregar(Dibujo(0, 19, auto_rojo, Color::RedLight));
    gestor.Agregar(Dibujo(60, 21, auto_azul, Color::BlueLight));

    int frames = 200;
    for (int frame = 0; frame < frames; ++frame) {
        screen.Clear();

        gestor.dibujos[5].x = 10 + (frame % 60);
        gestor.dibujos[5].y = 1 + int(2 * std::sin(frame * 0.1));

        gestor.dibujos[9].x = (frame * 2) % 85 - 10;

        gestor.dibujos[10].x = 80 - ((frame * 2) % 90);

        for (int i = 6; i <= 8; ++i)
            gestor.dibujos[i].color = (frame % 10 < 5) ? Color::Green : Color::GreenLight;

        gestor.DibujarTodos(screen);

        std::cout << screen.ToString();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "\033[H"; // reset cursor
    }

    return 0;
}