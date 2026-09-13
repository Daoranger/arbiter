#include "Arbiter/Core/Application.h"

#include "Arbiter/AI/Utility/Actions/Action.h"

arbiter::Application::Application()
    : m_window(sf::VideoMode(sf::Vector2u(900, 600)), "Arbiter")
    , m_entityShape(10.0f)
{
    m_entityShape.setOrigin(sf::Vector2f(10.0f, 10.0f));
    m_entityShape.setFillColor(sf::Color::White);

    struct StationDef { sf::Vector2f position; sf::Color color; };
    const StationDef stationDefs[] = {
        { sf::Vector2f(450.0f, 50.0f), sf::Color(255, 165, 0) },  // Eat
        { sf::Vector2f(50.0f, 300.0f), sf::Color::Blue },          // Drink
        { sf::Vector2f(850.0f, 300.0f), sf::Color(128, 128, 128) },// Sleep
        { sf::Vector2f(450.0f, 550.0f), sf::Color::Green },        // Heal
    };

    for (const auto& def : stationDefs)
    {
        sf::CircleShape station(15.0f);
        station.setOrigin(sf::Vector2f(15.0f, 15.0f));
        station.setFillColor(def.color);
        station.setPosition(def.position);
        m_stations.push_back(station);
    }
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
    m_entity.Update(dt);
}

void arbiter::Application::Render()
{
    m_window.clear(sf::Color::Black);

    for (const auto& station : m_stations)
    {
        m_window.draw(station);
    }

    if (const Action* currentAction = m_entity.agent.GetCurrentAction())
    {
        std::string name = currentAction->GetName();

        if (name == "Drink")
            m_entityShape.setFillColor(sf::Color::Blue);
        else if (name == "Eat")
            m_entityShape.setFillColor(sf::Color(255, 165, 0));
        else if (name == "Sleep")
            m_entityShape.setFillColor(sf::Color(128, 128, 128));
        else if (name == "Heal")
            m_entityShape.setFillColor(sf::Color::Green);
    }

    m_entityShape.setPosition(m_entity.kinematic.position);
    m_window.draw(m_entityShape);

    m_window.display();
}
