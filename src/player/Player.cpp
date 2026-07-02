#include <SFML/Graphics.hpp>
#include "player/Player.hpp"
#include <cmath>

Player::Player() {
    m_shape.setSize({WIDTH, HEIGHT});
    m_shape.setOrigin({WIDTH / 2.0f, HEIGHT / 2.0f});
    m_shape.setFillColor(sf::Color::Red);
}

void Player::update(float deltaTime) noexcept {
    sf::Vector2f direction{0.0f, 0.0f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) direction.y -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) direction.y += 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) direction.x -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) direction.x += 1.0f;

    float length = std::hypot(direction.x, direction.y);

    if (length > 0.0f) {
        direction /= length;
    }

    m_position += direction * m_speed * deltaTime;
}
