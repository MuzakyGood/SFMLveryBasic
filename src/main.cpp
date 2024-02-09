#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "nonplayer.h"

using namespace std;

int main() {

    // Variable untuk score
    int score = 0;

    // Variabel True atau false pemeriksaan
    bool drawRectangle = true;

    // Buat jendela game
    sf::RenderWindow window(sf::VideoMode(800, 450), "Test Only SFML");

    NonPlayer nonPlayer("img/choseone.png", 100, 100);

    //Menambahkan font
    sf::Font font;
    if (!font.loadFromFile("font/arial.ttf"))
    {
        return -1;
    }

    //Membuat objek teks
    sf::Text title;
    // select the font
    title.setFont(font); // font is a sf::Font
    // set the string to display
    title.setString("Matrix Origin");
    // set text position
    title.setPosition(10, 5);
    // set the character size
    title.setCharacterSize(24); // in pixels, not points!
    // set outline text
    title.setOutlineColor(sf::Color::Black);
    //set thickness
    title.setOutlineThickness(2);
    // set the color
    title.setFillColor(sf::Color::White);
    // set the text style
    title.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::Italic);

    sf::Text help;
    help.setFont(font);
    help.setString("Walk :");
    help.setPosition(702, 5);
    help.setFillColor(sf::Color::Black);
    help.setOutlineColor(sf::Color::White);
    help.setOutlineThickness(1);
    help.setCharacterSize(10);

    sf::CircleShape triangle(20.f, 3.f);
    triangle.scale(1.f, 1.f);
    triangle.setOutlineThickness(3.f);
    triangle.setFillColor(sf::Color::Green);
    triangle.setOutlineColor(sf::Color::Black);
    triangle.setPosition(20, 190);

    sf::RectangleShape point(sf::Vector2f(10.f, 10.f));
    point.setOutlineThickness(3.f);
    point.setOutlineColor(sf::Color::Black);
    point.setSize(sf::Vector2f(10.f, 10.f));
    point.setFillColor(sf::Color::Yellow);
    point.setPosition(160, 190);

    // Untuk deklarasikan teks score
    sf::Text scoreText;
        scoreText.setFont(font);
        scoreText.setPosition(10, 400);
        scoreText.setFillColor(sf::Color::Yellow);
        scoreText.setOutlineColor(sf::Color::Black);
        scoreText.setOutlineThickness(2);

    sf::RectangleShape backkey(sf::Vector2f(70.f, 70.f));
    backkey.setFillColor(sf::Color::Cyan);
    backkey.setOutlineColor(sf::Color::White);
    backkey.setOutlineThickness(2);
    backkey.setPosition(700, 7);

    // Membuat objek gambar dan memuat gambar dari file (path relatif)
    sf::Texture texture;
    if (!texture.loadFromFile("img/chamber800x450.png")) {
        // Menampilkan pesan kesalahan jika gagal memuat gambar
        return -1;
    }

    sf::Texture keyboard;
    if (!keyboard.loadFromFile("img/keyboard.png")) {
        return -1;
    }
    
    sf::Sprite key(keyboard);
    key.setPosition(710, 23);

    sf::Sprite sprite(texture);  // Membuat sprite dari gambar

    // Mengatur ukuran gambar dengan lebar dan tinggi tertentu
    float targetWidth = 800.0f; // Ganti dengan lebar yang diinginkan
    float targetHeight = 600.0f; // Ganti dengan tinggi yang diinginkan

    // Menghitung faktor skalanya
    float scaleX = targetWidth / sprite.getLocalBounds().width;
    float scaleY = targetHeight / sprite.getLocalBounds().height;

    // Loop utama game
while (window.isOpen()) {
    // Proses event
    sf::Event event;

    while (window.pollEvent(event)) {
        // Kode ini digunakan untuk player jalan!

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {
            triangle.move(0, -11);
            cout << "Up" << endl;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
                triangle.move(-11, 0);
                cout << "Left" << endl;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
                triangle.move(11, 0);
                cout << "Right" << endl;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
                triangle.move(0, 11);
                cout << "Down" << endl;
        }
        
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        // Key untuk escape
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window.close();
            cout << "Exit!" << endl;
        }
        
        // Untuk event lainnya
    }

    // Event collision, example jika point di sentuh triangle maka akan hilang
    sf::FloatRect rectBounds = point.getGlobalBounds();
    sf::FloatRect triBounds = triangle.getGlobalBounds();

    if (rectBounds.intersects(triBounds)) {
        // Jika menyentuh, set drawRectangle menjadi false
        drawRectangle = false;
        // Jika menyentuh juga akan dapat 20 point
        score += 20;
        cout << "Level Up!" << endl;
    }

    // harus di dalam while karena ini bergerak
    scoreText.setString("Score: " + to_string(score));

    // Hapus layar window
    window.clear(sf::Color::Black);
    // Render gambar Background
    window.draw(sprite);

    // Tampilkan konten game (akan ditambahkan nanti)

    //Untuk menampilkan shape 
    window.draw(triangle);
    
    // Tampilkan rectangle jika drawRectangle true
    if (drawRectangle) {
        window.draw(point);
    }
    
    window.draw(backkey);
    window.draw(key);
    // Untuk menampilkan teks score
    window.draw(scoreText);
    // Membuat Text
    window.draw(title);
    window.draw(help);
    nonPlayer.draw(window);
    // Tampilkan konten ke layar
    window.display();
}

// Tutup kurung utama
return 0;
}
