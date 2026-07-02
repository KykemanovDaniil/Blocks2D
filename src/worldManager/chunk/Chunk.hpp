#include <SFML/Graphics.hpp>
#include <vector>
#include "../blockType/BlockType.hpp"

constexpr unsigned int CHUNK_W = 16;
constexpr unsigned int CHUNK_H = 128;
constexpr unsigned int CHUNK_SIZE = CHUNK_W * CHUNK_H;

constexpr unsigned int BLOCK_SIZE = 32;

class Chunk {
public:
    void init();
    void updateGeometry();

    int getX() noexcept {
        return m_x;
    }

    void setX(int x) noexcept {
        m_x = x;
    }

    void draw(sf::RenderTarget& target, const sf::Texture& atlas) const {
        target.draw(m_mesh, &atlas);
    }
private:
    int m_x = 0;
    BlockType blocks[CHUNK_SIZE] = {BlockType::Air};
    sf::VertexArray m_mesh;
};