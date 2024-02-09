#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "nonplayer.h"

// Contoh class nonplayer.cpp

using namespace std;

int i;

NonPlayer::NonPlayer(const std::string& filename, float x, float y) : x(x), y(y) {
    if (!texture.loadFromFile(filename)) {
        // Handle error jika gagal memuat gambar
        cout << "Gambar Tidak muncul" << endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(250, 10);
    
}

void NonPlayer::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}