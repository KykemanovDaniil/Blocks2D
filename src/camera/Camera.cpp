#include <SFML/Graphics.hpp>
#include "camera/Camera.hpp"

void Camera::setZoom(float zoom) {
    cameraView.zoom(zoom);
}

void Camera::setLerp(float newLerp) {
    lerp = newLerp;
}

void Camera::setCenter(const sf::Vector2f& center) {
    cameraView.setCenter(center);
}

void Camera::setSize(const sf::Vector2f& size) {
    cameraView.setSize(size);
}

void Camera::setView(sf::RenderWindow& window) {
    window.setView(cameraView);
}

void Camera::updateLerp(const sf::Vector2f& target) {
    position.x = position.x + (target.x - position.x) * lerp;
    position.y = position.y + (target.y - position.y) * lerp;

    cameraView.setCenter(position);
}