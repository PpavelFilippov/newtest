#include <SFML/Graphics.hpp>
#include <filesystem>
//#include "Version.hpp"
#include <Header.h>

static void modifyCurrentWorkingDirectory();

int main()
{
    modifyCurrentWorkingDirectory();

    Render Field;
    Builder Matrix;

    Matrix.FixField();

    //Window settings
    sf::RenderWindow window;
    window.create(sf::VideoMode(1440, 900), "Three in row");
    window.setFramerateLimit(FPS);

    while (window.isOpen())
    {
        //Main Menu
        MainMenu(&Matrix, &Field, &window);

        //main game
        GameProcess(&Matrix, &Field, &window);

        //End
         DeathScreen(&Matrix, &Field, &window);
    }

    return 0;

}

void modifyCurrentWorkingDirectory()
{
    while (!std::filesystem::exists("resources"))
    {
        std::filesystem::current_path(std::filesystem::current_path().parent_path());
    }
    auto cwd = std::filesystem::current_path();
}
