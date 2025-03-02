#include <vector>
#include "window.hh"

using pro2::ModKey, pro2::Colors;
using std::vector;

const int WIDTH = 320, HEIGHT = 200;
const int ZOOM = 3;

void paint_line(pro2::Window& window, int j, int color) {
    for (int i = 0; i < WIDTH; i++) {
        if (color == Colors::red and window.is_key_pressed(8)) window.set_pixel({i, j}, color);
        else window.set_pixel({i, j}, color);
    }
}

int bar_position(int time) {
    int f = time % (HEIGHT * 2);
    return (f >= HEIGHT ? (2 * HEIGHT - 1) - f : f);
}

int main() {
    pro2::Window window("Window Animation", WIDTH, HEIGHT, ZOOM);

    while (window.next_frame()) {
        // Al pressionar Escape es tanca la finestra
        if (window.is_key_pressed(27)) {
            break;
        }

        // Esborrem la pantalla (fondo negre per defecte)
        window.clear(Colors::black);

        // Pintem una barra vermella que va de dalt a baix
        int j = bar_position(window.frame_count());
        paint_line(window, j, Colors::red);

        // Pintem una barra a on es clica el ratolí
        // if (window.is_mouse_pressed()) {
        pro2::Pt pos = window.mouse_pos();
        paint_line(window, pos.y, Colors::yellow);
        
    }
}