#include <SFML/Graphics.hpp>
#include "src/player/Player.hpp"
#include <cmath>

Player::Player() {
    m_shape.setSize({WIDTH, HEIGHT});
    m_shape.setOrigin({WIDTH / 2.0f, HEIGHT / 2.0f});
    m_shape.setFillColor(sf::Color::Red);
}

void Player::update(float deltaTime) noexcept {
    m_previousPosition = m_position; 

    sf::Vector2f direction{0.0f, 0.0f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) direction.y -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) direction.y += 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) direction.x -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) direction.x += 1.0f;

    float length = std::hypot(direction.x, direction.y);
    if (length > 0.0f) {
        direction /= length;
    }

    m_position += direction * m_speed * deltaTime;
}

void Player::interpolate(float interpolationFactor) noexcept {
    m_visualPosition = m_previousPosition + 
        (m_position - m_previousPosition) * interpolationFactor;

    m_shape.setPosition(m_visualPosition); 
}

void Player::draw(sf::RenderTarget& target) const {
    target.draw(m_shape);
}