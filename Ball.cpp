#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "Player.cpp"

class Ball
{
  public:
    Ball() : ball(5.f),
             velocity(rand() % 3 + 2, rand() % 3 + 2)
    {
        ball.setOrigin(2.5, 2.5);
        ball.setPosition(400, 300);
        position = sf::Vector2f(ball.getPosition());
        font.loadFromFile("./Jumpman.ttf");
        score.setFont(font);
        score.setFillColor(sf::Color::Blue);
        score.setPosition(340, 550);
        score.setString(":SCORE:");

        A.setFont(font);
        A.setFillColor(sf::Color::Blue);
        A.setPosition(320, 550);
        A.setString("0");

        B.setFont(font);
        B.setFillColor(sf::Color::Blue);
        B.setPosition(430, 550);
        B.setString("0");

        scoreA = 0;
        scoreB = 0;
    }

    ~Ball()
    {
    }

    void draw(sf::RenderWindow *window)
    {
        window->draw(ball);
        window->draw(score);
        window->draw(A);
        window->draw(B);
    }

    void update()
    {
        position += velocity;
        ball.setPosition(position);
    }

    void checkEdges()
    {
        if (position.y >= 600)
            velocity.y *= -1;

        if (position.y <= 0)
            velocity.y *= -1;

        if (position.x >= 800)
        {
            velocity.x *= -1;
            scoreA = scoreA + 1;
            convert << scoreA;
            string_A = convert.str();
            A.setString(string_A);
        }

        if (position.x <= 0)
        {
            velocity.x *= -1;
            scoreB = scoreB + 1;
            convert << scoreB;
            string_B.clear();
            string_B = convert.str();
            B.setString(string_B);
        }

        convert.clear();
        convert.str("");

    }

    void collision(Player p)
    {
        sf::Vector2f interaction = p.getPosition();
        int player = p.getPlayer();

        if (player == 1)
        {
            if (position.x <= interaction.x)
                if (position.y >= interaction.y && position.y <= interaction.y + 100)
                {
                    velocity.x *= -1;
                }
        }

        else
        {
            if (position.x >= interaction.x)
                if (position.y >= interaction.y && position.y <= interaction.y + 100)
                    velocity.x *= -1;
        }
    }

  private:
    sf::CircleShape ball;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Text score;
    sf::Font font;
    sf::Text A;
    sf::Text B;
    std::string string_A;
    std::string string_B;
    std::ostringstream convert;
    int scoreA;
    int scoreB;
};
