#include <SFML/Graphics.hpp>
#include "camera/Camera.hpp"
#include <cmath>

void Camera::updateLerp(sf::Vector2f target, float deltaTime) noexcept {
    sf::Vector2f currentCenter = m_view.getCenter();

    float blend = 1.0f - std::exp(-m_lerp * deltaTime);

    float newX = currentCenter.x + (target.x - currentCenter.x) * blend;
    float newY = currentCenter.y + (target.y - currentCenter.y) * blend;

    m_view.setCenter({newX, newY});
}