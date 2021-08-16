#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "vector2D.h"
#include "flat_map.h"

using namespace std;

class Player{
private:
    int id;
    Vector2D position;
    Vector2D orient;
    int alive = 1;
    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    sf::Color color;
public:
    Player(int _id, sf::Keyboard::Key _up, sf::Keyboard::Key _down, sf::Keyboard::Key _left, sf::Keyboard::Key _right, Vector2D _begin_pos, 
       Vector2D _orient ,sf::Color _color): 
        id(_id), up(_up), down(_down), left(_left), right(_right){
        
        orient = _orient;
        position = _begin_pos;
        color = _color;
    }
    ~Player(){};
    void set_dead();
    void gameplay();
    void move(FlatMap &);
    int getID();
    int getXpos();
    int getYpos();
    sf::Color getColor();
    bool check_alive(FlatMap &);
    int is_alive();
    bool operator==(const Player &);
};

#endif