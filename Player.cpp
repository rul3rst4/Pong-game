#include <SFML/Graphics.hpp>

class Player
{
public:
  Player(int cod) : rectangle(sf::Vector2f(10, 100)),
                    velocity(0, 0)
  {

    if (cod > 0)
    {
      rectangle.setPosition(780, 300);
      player = 2;
    }

    else if (cod < 0)
    {
      rectangle.setOrigin(10, 0);
      rectangle.setPosition(20, 300);
      player = 1;
    }

    position = sf::Vector2f(rectangle.getPosition());
  }

  ~Player()
  {
  }

  void draw(sf::RenderWindow *window)
  {
    window->draw(rectangle);
  }

  void update()
  {
    position += velocity;
    if (position.y + 100 >= 600)
      position.y = 500;

    if (position.y <= 0)
      position.y = 0;

    rectangle.setPosition(position);
    velocity.y = 0;
  }

  void keyboard_input()
  {

    if (player == 1)
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        velocity.y = -5;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        velocity.y = 5;
    }
    else
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        velocity.y = -5;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        velocity.y = 5;
    }
  }

  sf::Vector2f getPosition()
  {
    return rectangle.getPosition();
  }

  int getPlayer()
  {
    return player;
  }

private:
  sf::RectangleShape rectangle;
  sf::Vector2f position;
  sf::Vector2f velocity;
  int player;
};