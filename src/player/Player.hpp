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

    void update(float deltaTime) noexcept;
    
    void draw(sf::RenderTarget& target) const {
        m_shape.setPosition(m_position);
        target.draw(m_shape);
    }
private:
    sf::Vector2f m_position{0.0f, 0.0f};
    float m_speed{300.0f};

    mutable sf::RectangleShape m_shape;
    
    static constexpr float HEIGHT = 55.0f;
    static constexpr float WIDTH = 25.0f;
};
