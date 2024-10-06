#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

#include "Game.h"
#include "utility/Vec2.hpp"
#include "print"

int main()
{
    auto game = Game(1280u, 720u, 60u);
    game.init();
    // auto window = sf::RenderWindow{ { 1280u, 720u }, "CMake SFML Project" };
    // window.setFramerateLimit(60);
    // if (!ImGui::SFML::Init(window))
    //     return -1;
    //
    // sf::Clock clock;
    // while (window.isOpen())
    // {
    //     for (auto event = sf::Event{}; window.pollEvent(event);)
    //     {
    //         ImGui::SFML::ProcessEvent(window, event);
    //
    //         if (event.type == sf::Event::Closed)
    //         {
    //             window.close();
    //         }
    //     }
    //
    //     ImGui::SFML::Update(window, clock.restart());
    //
    //     ImGui::Begin("Hello, world!");
    //     ImGui::Button("Look at this pretty button");
    //     ImGui::End();
    //
    //     window.clear();
    //     ImGui::SFML::Render(window);
    //     window.display();
    // }
    //
    // ImGui::SFML::Shutdown();

    return 0;
}