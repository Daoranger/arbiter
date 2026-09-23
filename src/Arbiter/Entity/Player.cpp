#include "Arbiter/Entity/Player.h"

arbiter::Player::Player()
    : m_circle(20.0f)
{
    m_circle.setOrigin(sf::Vector2f(20.0f, 20.0f));
    m_circle.setFillColor(sf::Color(255, 140, 0));

    kinematic.position = sf::Vector2f(450.0f, 300.0f);
    kinematic.maxSpeed = 250.0f;
}

void arbiter::Player::Update(float dt)
{
    sf::Vector2f direction(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        direction.y -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        direction.y += 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        direction.x -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        direction.x += 1.0f;

    if (direction.lengthSquared() > 0.0f)
        direction = direction.normalized();

    kinematic.velocity = direction * kinematic.maxSpeed;
    kinematic.position += kinematic.velocity * dt;
}

void arbiter::Player::Render(sf::RenderTarget& target)
{
    m_circle.setPosition(kinematic.position);
    target.draw(m_circle);
}
