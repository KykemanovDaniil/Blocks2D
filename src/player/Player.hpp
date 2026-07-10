#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();

    void setPosition(const sf::Vector2f position) noexcept {
        m_position = position;
    }

    sf::Vector2f getPosition() const noexcept {
        return m_position;
    }

    float getSpeed() const noexcept {
        return m_speed;
    }

    void setSpeed(float speed) {
        m_speed = speed;
    }

    void update(float deltaTime) noexcept;
    void interpolate(float interpolationFactor) noexcept;
    
    void draw(sf::RenderTarget& target) const;
private:
    sf::Vector2f m_previousPosition;
    sf::Vector2f m_position;
    sf::Vector2f m_visualPosition;
    float m_speed{900.0f};

    mutable sf::RectangleShape m_shape;
    
    static constexpr float HEIGHT = 55.0f;
    static constexpr float WIDTH = 25.0f;
};
