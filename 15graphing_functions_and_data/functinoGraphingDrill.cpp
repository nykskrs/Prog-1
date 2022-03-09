/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    Simple_window win{{100,100},600,600,"Function graphs."};

    win.wait_for_button();
}
