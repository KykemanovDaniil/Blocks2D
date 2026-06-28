#pragma once
#include <SFML/Graphics.hpp>

struct Camera {
    sf::Vector2f position = {0.0f, 0.0f};
    float zoom = 1.0f;
    float lerp = 1.0f;

    sf::View cameraView;

    void updateLerp(const sf::Vector2f& target);

    void setZoom(float zoom);
    void setLerp(float newLerp);
    void setCenter(const sf::Vector2f& center);
    void setSize(const sf::Vector2f& size);
    void setView(sf::RenderWindow& window);
};