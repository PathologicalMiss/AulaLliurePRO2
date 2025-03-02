#include <vector>
#include "window.hh"
#include <iostream>
using namespace std;

using pro2::Colors;

const int WIDTH = 256, HEIGHT = 240;
const int ZOOM = 4;

const int _ = -1;
const int r = Colors::red;
const int s = 0xecc49b;
const int b = 0x5e6ddc;
const int y = Colors::yellow;
const int h = Colors::black;
const int g = 0xaaaaaa;
const int w = 0x8d573c;

// clang-format off
const vector<vector<int>> mario_sprite = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, r, r, r, b, r, r, b, r, r, r, _},
    {r, r, r, r, b, b, b, b, r, r, r, r},
    {g, g, r, b, y, b, b, y, b, r, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};
// clang-format on

const char arrow_up = 17;
const char arrow_down = 18;
const char arrow_left = 20;
const char arrow_right = 19;

void put_sprite(pro2::Window& window, pro2::Pt orig, const vector<vector<int>>& sprite) {
    for (int i = 0; i < sprite.size(); i++) {
        const vector<int>& line = sprite[i];
        for (int j = 0; j < line.size(); j++) {
            if (line[j] >= 0) {
                window.set_pixel({orig.x + j, orig.y + i}, line[j]);
            }
        }
    }
}

// bool is_in_range(int lr, int bt) {

// }

int main() {
    pro2::Window window("Mario Bros", WIDTH, HEIGHT, ZOOM);

    window.clear();
    int lr, bt;
    lr = 6;
    bt = 8;
    put_sprite(window, {WIDTH / 2 - lr, HEIGHT / 2 - bt}, mario_sprite);

    while (window.next_frame()) {
        if (window.is_key_pressed(arrow_left) and (WIDTH / 2 - lr > 0)) ++lr;
        if (window.is_key_pressed(arrow_right) and (WIDTH / 2 - lr < WIDTH-12)) --lr;
        if (window.is_key_pressed(arrow_up) and (HEIGHT / 2 - bt > 0)) ++bt;
        if (window.is_key_pressed(arrow_down) and (HEIGHT / 2 - bt < HEIGHT-16)) --bt;
        window.clear();
        put_sprite(window, {WIDTH / 2 - lr, HEIGHT / 2 - bt}, mario_sprite);
    }
}