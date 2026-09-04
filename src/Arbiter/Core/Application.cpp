#include "Arbiter/Core/Application.h"

arbiter::Application::Application()
    : m_window(sf::VideoMode(sf::Vector2u(10, 10)), "Arbiter")
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
    m_entity.Update();
}

void arbiter::Application::Render()
{
    m_window.clear(sf::Color::Black);
    m_window.display();
}
