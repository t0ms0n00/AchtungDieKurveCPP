#include "player.h"
#include <SFML/Graphics.hpp>

/// returns player color

sf::Color Player::getColor(){
    return color;
}

/// returns player id

int Player::getID(){
    return id;
}

/// returns player status (still alive or dead)

int Player::is_alive(){
    return alive;
}

/// get x coordinate

int Player::getXpos(){
    return position.getX();
}

/// get player's y coordinate

int Player::getYpos(){
    return position.getY();
}

/// change player status to dead, helpful in function for thread, thread knows when its time to end

void Player::set_dead(){
    alive = 0;
}

/// move player to neighbour square, based on orient vector2D

void Player::move(FlatMap & area){
    area.set_element(id, position.getX(), position.getY());
    position += orient;
    if(position.getX() < 0){
        position=Vector2D(area.getWidth()-1, position.getY());
    }
    if(position.getY() < 0){
        position=Vector2D(position.getX(), area.getHeight()-1);
    }
    if(position.getX() > area.getWidth()-1){
        position=Vector2D(0, position.getY());
    }
    if(position.getY() > area.getHeight()-1){
        position=Vector2D(position.getX(), 0);
    }
}

/// return true if player is alive being in his square

bool Player::check_alive(FlatMap & area){
    if(area.is_occupied(position.getX(), position.getY())){
        return false;
    }
    return true;
}

/// function for thread to catch keyboard interrupt and react

void Player::gameplay(){
    while(alive){
        if (sf::Keyboard::isKeyPressed(up) && !(orient==Vector2D(0, 1)))
        {
            orient = Vector2D(0, -1);
        }
        else if(sf::Keyboard::isKeyPressed(down) && !(orient==Vector2D(0, -1))){
            orient = Vector2D(0, 1);
        }
        else if(sf::Keyboard::isKeyPressed(left) && !(orient==Vector2D(1, 0))){
            orient = Vector2D(-1, 0);
        }
        else if(sf::Keyboard::isKeyPressed(right) && !(orient==Vector2D(-1, 0))){
            orient = Vector2D(1, 0);
        }
    }
}

/// helpful in removing from std::vector

bool Player::operator==(const Player & another){
    if(id == another.id) return true;
    return false;
}