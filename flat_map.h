#ifndef FLAT_MAP_H
#define FLAT_MAP_H

#include <cstdlib>
#include <iostream>

using namespace std;

class FlatMap{
private:
    const int width;
    const int height;
    int** values;
public:
    FlatMap(int _width, int _height) : width(_width), height(_height){
        values = new int*[height];
        for(int i = 0; i < height; i++){
            values[i] = new int[width];
        }
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                values[i][j] = 0;
            }
        }
    };
    ~FlatMap();
    void print_map_in_console();
    void set_element(int, int, int);
    bool is_occupied(int, int);
    int getWidth();
    int getHeight();
};

#endif