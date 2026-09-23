#include "Arbiter/Core/Application.h"

arbiter::Application::Application()
    : m_window(sf::VideoMode(sf::Vector2u(1280, 720)), "Arbiter")
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
            sf::FloatRect visibleArea(sf::Vector2f(0, 0), sf::Vector2f(resizedEvent->size.x, resizedEvent->size.y));
            m_window.setView(sf::View(visibleArea));
        }
    }
}

void arbiter::Application::Update()
{
    float dt = m_clock.restart().asSeconds();
    sf::Vector2i mousePixel = sf::Mouse::getPosition(m_window);
    sf::Vector2f mouseWorld = m_window.mapPixelToCoords(mousePixel);

    m_entity.Update(dt);
    m_player.Update(dt, mouseWorld);
}

void arbiter::Application::Render()
{
    m_window.clear(sf::Color::White);

    m_entity.Render(m_window);
    m_player.Render(m_window);

    m_window.display();
}
