#pragma once
#include <SFML/Graphics.hpp>
#include "core/Config.hpp"

class Camera {
public:
    Camera() = default;

    void setZoom(float zoom) noexcept {
        m_currentZoom = zoom;
        m_view.setSize(m_baseSize * m_currentZoom);
    }

    void setLerp(float lerp) noexcept {
        m_lerp = lerp;
    }

    void setCenter(const sf::Vector2f center) noexcept {
        m_view.setCenter(center);
    }

    void setSize(const sf::Vector2f size) noexcept {
        m_view.setSize(size);
    }

    void setView(sf::RenderTarget& target) noexcept {
        target.setView(m_view);
    }

    void updateLerp(const sf::Vector2f target, float deltaTime) noexcept;
private:
    float m_currentZoom{1.0f};
    float m_lerp{7.0f};
    sf::Vector2f m_baseSize{1280, 720};

    sf::View m_view;
};