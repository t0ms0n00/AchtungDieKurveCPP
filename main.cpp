#include <iostream>
#include <cstdlib>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <X11/Xlib.h>
#include <algorithm>

#include "flat_map.h"
#include "player.h"

#define MAP_WIDTH 600
#define MAP_HEIGHT 600

using namespace std;

int players_count = 2;
int commit = 0;
int state = 1;
FlatMap area(MAP_WIDTH, MAP_HEIGHT);

int main(int argc, char* argv[]){
    /// menu screen config

    XInitThreads();

    sf::RenderWindow screen(sf::VideoMode(MAP_WIDTH, MAP_HEIGHT), "Tron Game", sf::Style::Close);
    screen.setPosition(sf::Vector2i(150, 150));

    sf::Texture texture;
    if(!texture.loadFromFile("bg.jpeg")){
        cout << "Cannot load background\n";
        exit(1);
    }
    texture.setRepeated(false);
    sf::Sprite background(texture);
    background.setTextureRect(sf::IntRect(0, 0, MAP_WIDTH, MAP_HEIGHT));
    screen.draw(background);

    sf::Font font;
    if (!font.loadFromFile("arial_unicode_ms/ArialUnicodeMS.ttf")){
        cout << "Cannot load font\n";
        exit(1);
    }

    sf::Text name;
    name.setFont(font);
    name.setString("Tron Game");
    name.setCharacterSize(40);
    name.setFillColor(sf::Color::Black);
    name.setStyle(sf::Text::Italic);
    name.setPosition(sf::Vector2f(200, 125));
    screen.draw(name);

    sf::Text start;
    start.setFont(font);
    start.setString("Start");
    start.setCharacterSize(30);
    start.setFillColor(sf::Color::Red);
    start.setStyle(sf::Text::Italic);
    start.setPosition(sf::Vector2f(250, 185));
    screen.draw(start);

    sf::Text exit_text;
    exit_text.setFont(font);
    exit_text.setString("Exit");
    exit_text.setCharacterSize(30);
    exit_text.setFillColor(sf::Color::Black);
    exit_text.setStyle(sf::Text::Italic);
    exit_text.setPosition(sf::Vector2f(250, 245));
    screen.draw(exit_text);

    while(screen.isOpen() && !commit){
        sf::Event event;
        while(screen.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                screen.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {};
            if(state == 1){
                commit = 1;
            }
            if(state == 2){
                screen.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {};
            state = 2;
            exit_text.setFillColor(sf::Color::Red);
            start.setFillColor(sf::Color::Black);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {};
            state = 1;
            exit_text.setFillColor(sf::Color::Black);
            start.setFillColor(sf::Color::Red);
        }
        screen.draw(start);
        screen.draw(exit_text);
        screen.display();
    }

    screen.clear();

    /// instruction screen config

    sf::Text htp;
    htp.setFont(font);
    htp.setString("How to play");
    htp.setCharacterSize(40);
    htp.setFillColor(sf::Color::White);
    htp.setStyle(sf::Text::Italic);
    htp.setPosition(sf::Vector2f(200, 10));
    screen.draw(htp);

    sf::Text para;
    para.setFont(font);
    para.setString("This game was inspired by game called Tron which was inspired by Light Cycles.");
    para.setCharacterSize(14);
    para.setFillColor(sf::Color::White);
    para.setPosition(sf::Vector2f(10, 60));
    screen.draw(para);

    para.setString("It's multiplayer game for 2-4 players.");
    para.setPosition(sf::Vector2f(10, 80));
    screen.draw(para);

    para.setString("On the next screen you will choose number of players.");
    para.setPosition(sf::Vector2f(10, 100));
    screen.draw(para);

    para.setString("Game type is Last Man Standing (or Hunger Games if you prefer) ");
    para.setPosition(sf::Vector2f(10, 120));
    screen.draw(para);

    para.setString("Only one can be the winner.");
    para.setPosition(sf::Vector2f(10, 140));
    screen.draw(para);

    para.setString("If you hit your opponent or your tail, you will die. :(");
    para.setPosition(sf::Vector2f(10, 160));
    screen.draw(para);

    para.setString("Controllers.");
    para.setPosition(sf::Vector2f(10, 180));
    screen.draw(para);

    para.setString("Player 1: WSAD");
    para.setPosition(sf::Vector2f(10, 200));
    screen.draw(para);

    para.setString("Player 2: Arrows");
    para.setPosition(sf::Vector2f(10, 220));
    screen.draw(para);

    para.setString("Player 3: TGFH");
    para.setPosition(sf::Vector2f(10, 240));
    screen.draw(para);

    para.setString("Player 4: IKJL");
    para.setPosition(sf::Vector2f(10, 260));
    screen.draw(para);

    para.setString("Good luck for everyone!");
    para.setPosition(sf::Vector2f(10, 280));
    screen.draw(para);

    para.setString("Let the game begin.");
    para.setPosition(sf::Vector2f(10, 300));
    screen.draw(para);

    para.setString("Hope you enjoy it :)");
    para.setPosition(sf::Vector2f(10, 320));
    screen.draw(para);

    para.setString("Press enter or spacebar to continue.");
    para.setPosition(sf::Vector2f(10, 340));
    screen.draw(para);

    commit = 0;

    while(screen.isOpen() && !commit){
        sf::Event event;
        while(screen.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                screen.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {};
            commit = 1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {};
            commit = 1;
        }
        screen.display();
    }

    screen.clear();

    /// options screen config

    screen.draw(background);

    sf::Text communicate;
    communicate.setFont(font);
    communicate.setString("Choose number of players");
    communicate.setCharacterSize(40);
    communicate.setFillColor(sf::Color::Black);
    communicate.setStyle(sf::Text::Italic);
    communicate.setPosition(sf::Vector2f(50, 125));
    screen.draw(communicate);

    sf::Text two;
    two.setFont(font);
    two.setString("2");
    two.setCharacterSize(30);
    two.setFillColor(sf::Color::Red);
    two.setStyle(sf::Text::Italic);
    two.setPosition(sf::Vector2f(240, 185));
    screen.draw(two);

    sf::Text three;
    three.setFont(font);
    three.setString("3");
    three.setCharacterSize(30);
    three.setFillColor(sf::Color::Black);
    three.setStyle(sf::Text::Italic);
    three.setPosition(sf::Vector2f(280, 185));
    screen.draw(three);

    sf::Text four;
    four.setFont(font);
    four.setString("4");
    four.setCharacterSize(30);
    four.setFillColor(sf::Color::Black);
    four.setStyle(sf::Text::Italic);
    four.setPosition(sf::Vector2f(320, 185));
    screen.draw(four);

    commit = 0;
    state = 2;

    while(screen.isOpen() && !commit){
        sf::Event event;
        while(screen.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                screen.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {};
            players_count = state;
            commit = 1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {};
            if(state == 2){
                state = 3;
                three.setFillColor(sf::Color::Red);
                two.setFillColor(sf::Color::Black);
                continue;
            }
            if(state == 3){
                state = 4;
                four.setFillColor(sf::Color::Red);
                three.setFillColor(sf::Color::Black);
                continue;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
            while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {};
            if(state == 3){
                state = 2;
                three.setFillColor(sf::Color::Black);
                two.setFillColor(sf::Color::Red);
                continue;
            }
            if(state == 4){
                state = 3;
                four.setFillColor(sf::Color::Black);
                three.setFillColor(sf::Color::Red);
                continue;
            }
        }
        screen.draw(two);
        screen.draw(three);
        screen.draw(four);
        screen.display();
    }

    screen.clear();

    /// gameplay config

    vector <Player*> data;

    Player player1(1, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, Vector2D(100, 300), Vector2D(1, 0), sf::Color::Red);
    Player player2(2, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, Vector2D(500, 300), Vector2D(-1, 0), sf::Color::Cyan);
    Player player3(3, sf::Keyboard::T, sf::Keyboard::G, sf::Keyboard::F, sf::Keyboard::H, Vector2D(300, 100), Vector2D(0, 1), sf::Color::Yellow);
    Player player4(4, sf::Keyboard::I, sf::Keyboard::K, sf::Keyboard::J, sf::Keyboard::L, Vector2D(300, 500), Vector2D(0, -1),sf::Color::Green);
    data.push_back(&player1);
    data.push_back(&player2);
    sf::Thread th1(&Player::gameplay, &player1);
    sf::Thread th2(&Player::gameplay, &player2);
    sf::Thread th3(&Player::gameplay, &player3);
    sf::Thread th4(&Player::gameplay, &player4);
    th1.launch();
    th2.launch();
    if(players_count > 2) {
        data.push_back(&player3);
        th3.launch();
    }
    if(players_count > 3 ) {
        data.push_back(&player4);
        th4.launch();
    }

    /// gameplay

    while(data.size() > 1 && screen.isOpen()){
        sf::Event event;
        while(screen.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                screen.close();
            }
        }

        for(vector<Player*>::iterator player = data.begin(); player != data.end();){
            
            if(!(*player)->check_alive(area) && (*player)->is_alive()){
                (*player)->set_dead();
                data.erase(remove(data.begin(), data.end(), (*player)), data.end());
                continue;
            }
            (*player)->move(area);
            sf::RectangleShape line(sf::Vector2f(1.f, 1.f));
            line.setPosition(sf::Vector2f((*player)->getXpos(), (*player)->getYpos()));
            line.setFillColor((*player)->getColor());
            screen.draw(line);
            player++;
        }

        screen.display();
        sf::sleep(sf::milliseconds(1000/60));
    }

    /// ending handle

    sf::Text win_msg;
    win_msg.setFont(font);
    win_msg.setString("YOU WIN");
    win_msg.setCharacterSize(60);
    win_msg.setFillColor(data[0]->getColor());
    win_msg.setStyle(sf::Text::Italic);
    win_msg.setPosition(sf::Vector2f(170, 200));
    screen.draw(win_msg);

    for(vector<Player*>::iterator player = data.begin(); player != data.end(); ++player){
        (*player)->set_dead();
    }

    while(screen.isOpen()){
        sf::Event event;
        while(screen.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                screen.close();
            }
        }
        screen.display();
    }

    return 0;
}