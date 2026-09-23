#include "Arbiter/Core/Application.h"

#include <cmath>

arbiter::Application::Application()
    : m_window(sf::VideoMode(sf::Vector2u(1280, 720)), "Arbiter")
    , m_camera(sf::Vector2f(640.0f, 360.0f), sf::Vector2f(1280.0f, 720.0f))
{
}

void arbiter::Application::Run()
{
    while (m_window.isOpen())
    {
        ProcessEvents();
        Update();
        Render();
    }
}

void arbiter::Application::ProcessEvents()
{
    while (const std::optional event = m_window.pollEvent() )
    {
        if (event->is<sf::Event::Closed>())
            m_window.close();

        if (const auto* resizedEvent = event->getIf<sf::Event::Resized>())
        {
            m_camera.setSize(sf::Vector2f(resizedEvent->size));
        }
    }
}

void arbiter::Application::Update()
{
    float dt = m_clock.restart().asSeconds();

    m_window.setView(m_camera);
    sf::Vector2i mousePixel = sf::Mouse::getPosition(m_window);
    sf::Vector2f mouseWorld = m_window.mapPixelToCoords(mousePixel);

    m_entity.Update(dt);
    m_player.Update(dt, mouseWorld);

    m_camera.setCenter(m_player.kinematic.position);
}

void arbiter::Application::RenderGrid()
{
    const float spacing = 100.0f;
    const sf::Color color(220, 220, 220);

    sf::Vector2f center = m_camera.getCenter();
    sf::Vector2f half = m_camera.getSize() / 2.0f;
    float left = center.x - half.x;
    float right = center.x + half.x;
    float top = center.y - half.y;
    float bottom = center.y + half.y;

    sf::VertexArray lines(sf::PrimitiveType::Lines);

    for (float x = std::floor(left / spacing) * spacing; x <= right; x += spacing)
    {
        lines.append(sf::Vertex{sf::Vector2f(x, top), color});
        lines.append(sf::Vertex{sf::Vector2f(x, bottom), color});
    }

    for (float y = std::floor(top / spacing) * spacing; y <= bottom; y += spacing)
    {
        lines.append(sf::Vertex{sf::Vector2f(left, y), color});
        lines.append(sf::Vertex{sf::Vector2f(right, y), color});
    }

    m_window.draw(lines);
}

void arbiter::Application::Render()
{
    m_window.clear(sf::Color::White);
    m_window.setView(m_camera);

    RenderGrid();

    m_entity.Render(m_window);
    m_player.Render(m_window);

    m_window.display();
}
