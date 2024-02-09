#pragma once

#include <SFML/Graphics.hpp>

// Contoh class nonplayer.h

class NonPlayer {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    float x, y;

public:
    NonPlayer(const std::string& filename, float x, float y);
    void draw(sf::RenderWindow& window);
    // Tambahkan metode lain yang diperlukan
};


