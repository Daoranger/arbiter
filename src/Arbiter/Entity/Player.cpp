#include "Arbiter/Entity/Player.h"

#include <cmath>

arbiter::Player::Player()
    : m_circle(50.0f)
    , m_leftHand(20.0f)
    , m_rightHand(20.0f)
{
    const sf::Color orange(255, 140, 0);

    m_circle.setOrigin(sf::Vector2f(50.0f, 50.0f));
    m_circle.setFillColor(orange);
    m_circle.setOutlineColor(sf::Color::Black);
    m_circle.setOutlineThickness(-2.0f);

    for (sf::CircleShape* hand : { &m_leftHand, &m_rightHand })
    {
        hand->setOrigin(sf::Vector2f(20.0f, 20.0f));
        hand->setFillColor(orange);
        hand->setOutlineColor(sf::Color::Black);
        hand->setOutlineThickness(-2.0f);
    }

    kinematic.position = sf::Vector2f(450.0f, 300.0f);
    kinematic.maxSpeed = 250.0f;
}

void arbiter::Player::Update(float dt, sf::Vector2f mouseWorld)
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

    sf::Vector2f toMouse = mouseWorld - kinematic.position;
    kinematic.orientation = std::atan2(toMouse.y, toMouse.x);
}

void arbiter::Player::Render(sf::RenderTarget& target)
{
    sf::Vector2f forward(std::cos(kinematic.orientation), std::sin(kinematic.orientation));
    sf::Vector2f side(-forward.y, forward.x);

    m_leftHand.setPosition(kinematic.position + forward * 45.0f - side * 42.0f);
    m_rightHand.setPosition(kinematic.position + forward * 45.0f + side * 42.0f);
    m_circle.setPosition(kinematic.position);

    target.draw(m_circle);
    target.draw(m_leftHand);
    target.draw(m_rightHand);
}
