#include "flat_map.h"

/// free dynamic allocated array

FlatMap::~FlatMap(){
    for(int i = 0; i < height; i++){
        delete [] values[i];
    }
    delete [] values;
}

/// was helpful at begin, before created UI with SFML

void FlatMap::print_map_in_console(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << values[i][j] << " ";
        }
        cout << "\n";
    }
}

/// player marks his field with that procedure

void FlatMap::set_element(int val, int xpos, int ypos){
    values[xpos][ypos] = val;
}

/// check if field was marked before or not

bool FlatMap::is_occupied(int xpos, int ypos){
    if(values[xpos][ypos] != 0){
        return true;
    }
    return false;
}

/// getter for width of map

int FlatMap::getWidth(){
    return width;
}

/// getter for height of map

int FlatMap::getHeight(){
    return height;
}