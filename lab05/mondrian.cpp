/*
 * mondrian.cpp
 *
 * Author: <your name here>
 *
 * Generate recursive pictures inspired by the art of Piet Mondrian.
 */

#include <cstdlib>
#include <ctime>

#include "mondrian.h"

using namespace std;

void Mondrian::_paint_recursive(Picture &picture, int left, int top, int right, int bottom) {
    // base case 1 - in case we made a zero width or height rectangle
    if (abs(right - left) <= 0 || abs(bottom - top) <= 0){
        return;
    }
    // base case 2 - rectangle is now "small enough"
    if (abs((right - left)*(bottom - top)) <= 35000 ){
        _color_fill(picture, left + 1, top + 1, right - 1, bottom - 1);
    }else if (abs(right - left) > abs(bottom - top)){
        int x = ( rand() % (right - left) )+ left;
        _draw_vertical_line(picture, x, top, bottom);
        _paint_recursive(picture, left, top, x, bottom);
        _paint_recursive(picture, x, top, right, bottom);
    }
    // Fill with a color (or not)

    // otherwise, split the rectangle in two at random, paint the two
    // rectangles recursively
    else {
        int y = (rand() % (bottom - top) )+ top;
        _draw_horizontal_line(picture, y, left, right);
        _paint_recursive(picture, left, top, right, y);
        _paint_recursive(picture, left, y, right, bottom);
    }
}

void Mondrian::_color_fill(Picture &picture, int left, int top, int right, int bottom) {

//    vector<colors> color (0);

//    colors red;
//    colors blue;
//    colors yellow;
//    colors white;
//    colors white1;
//    colors white2;
//    colors white3;
//    colors white4;

//    red.r = 255; red.g = 0; red.b = 0;
//    blue.r = 0; blue.g = 0; blue.b = 128;
//    yellow.r = 255; yellow.g = 215; yellow.b = 0;
//    white.r = 255; white.g = 255; white.b = 255;
//    white1.r = 255; white1.g = 255; white1.b = 255;
//    white2.r = 255; white2.g = 255; white2.b = 255;
//    white3.r = 255; white3.g = 255; white3.b = 255;
//    white4.r = 255; white4.g = 255; white4.b = 255;

    // for traditional Mondrian colors, a good palette is:
    //red: r = 255, g = 0, b = 0
    // blue: r = 0, g = 0, b = 128
    // yellow: r = 255, g = 215, b = 0
    // white: r = 255, g = 255, b = 255
    // black: r = 0, g = 0, b = 0

//    color.push_back(red);
//    color.push_back(blue);
//    color.push_back(yellow);
//    color.push_back(white);
//    color.push_back(white1);
//    color.push_back(white2);
//    color.push_back(white3);
//    color.push_back(white4);

    int rando = rand () % 8;

    int r, g, b;

    int red;

    red +=30;
    r = red;
    g = 0;
    b = 0;

//    r = color.at(rando).r;
//    g = color.at(rando).g;
//    b = color.at(rando).b;


    for (int x = left; x <= right; x++) {
        for (int y = top; y <= bottom; y++) {
            picture.set(x, y, r, g, b);
        }
    }
}

void Mondrian::_draw_horizontal_line(Picture &picture, int y, int left, int right) {
    for (int x = left; x <= right; x++) {
        picture.set(x, y, 0, 0, 0);
    }
}

void Mondrian::_draw_vertical_line(Picture &picture, int x, int top, int bottom) {
    for (int y = top; y <= bottom; y++) {
        picture.set(x, y, 0, 0, 0);
    }
}

void Mondrian::paint(string output_filename, int width, int height) {
    // get a new random seed each time
    srand(time(nullptr));

    // create a white picture
    Picture picture(width, height, 255, 255, 255);

    // put a frame around it
    _draw_horizontal_line(picture, 0, 0, width - 1);
    _draw_horizontal_line(picture, height - 1, 0, width - 1);
    _draw_vertical_line(picture, 0, 0, height - 1);
    _draw_vertical_line(picture, width - 1, 0, height - 1);

    // invoke our computer artist!
    _paint_recursive(picture, 1, 1, width - 2, height - 2);

    // save result
    picture.save(output_filename);
}
