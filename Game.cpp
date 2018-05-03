#include <SFML/Graphics.hpp>
#include "Ball.cpp"

class Game
{
  public:
    Game() : window(sf::VideoMode(800, 600), "Game"),
             player1(1),
             player2(-1)
    {
        window.setFramerateLimit(60);
        loop();
    }
    ~Game()
    {
    }

    void loop()
    {

        while (window.isOpen())
        {
            sf::Event event;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            player1.keyboard_input();
            player2.keyboard_input();
            player1.update();
            player2.update();
            ball.checkEdges();
            ball.collision(player1);
            ball.collision(player2);
            ball.update();
            render();
        }
    }

    void render()
    {
        window.clear();
        player1.draw(&window);
        player2.draw(&window);
        ball.draw(&window);
        window.display();
    }

  private:
    sf::RenderWindow window;
    Ball ball;
    Player player1;
    Player player2;
};

//g++ main.cpp Game.cpp -o sfml-app -lsfml-graphics -lsfml-system -lsfml-window