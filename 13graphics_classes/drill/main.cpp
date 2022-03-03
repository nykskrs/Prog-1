/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

// using namespace Graph_lib;

int main()
try
{
    Simple_window win(Point(100, 100), 800, 1000, "My Window");

    int xSize = win.x_max();
    int ySize = win.y_max();
    int xGrid = 100;
    int yGrid = 100;

    Lines grid;
    for (int x = xGrid; x < xSize; x += xGrid)
        grid.add(Point(x, 0), Point(x, ySize));
    for (int y = yGrid; y < ySize; y += yGrid)
        grid.add(Point(0, y), Point(xSize, y));

    // diagonal red squares
    Rectangle rect01(Point(0, 0), 100, 100);
    Rectangle rect02(Point(100, 100), 100, 100);
    Rectangle rect03(Point(200, 200), 100, 100);
    Rectangle rect04(Point(300, 300), 100, 100);
    Rectangle rect05(Point(400, 400), 100, 100);
    Rectangle rect06(Point(500, 500), 100, 100);
    Rectangle rect07(Point(600, 600), 100, 100);
    Rectangle rect08(Point(700, 700), 100, 100);

    rect01.set_fill_color(Color::red);
    rect02.set_fill_color(Color::red);
    rect03.set_fill_color(Color::red);
    rect04.set_fill_color(Color::red);
    rect05.set_fill_color(Color::red);
    rect06.set_fill_color(Color::red);
    rect07.set_fill_color(Color::red);
    rect08.set_fill_color(Color::red);

    // 3 imgs random posit
    Image img01(Point(0, 500), "chad_cat.jpg");
    img01.set_mask(Point(60, 50), 200, 200);
    Image img02(Point(0, 200), "chad_cat.jpg");
    img02.set_mask(Point(60, 50), 200, 200);
    Image img03(Point(600, 200), "chad_cat.jpg");
    img03.set_mask(Point(60, 50), 200, 200);

    Image img100px(Point(500, 400), "chad_cat.jpg");
    img100px.set_mask(Point(110, 70), 100, 100);

    win.attach(img01);
    win.attach(img02);
    win.attach(img03);

    win.attach(rect01);
    win.attach(rect02);
    win.attach(rect03);
    win.attach(rect04);
    win.attach(rect05);
    win.attach(rect06);
    win.attach(rect07);
    win.attach(rect08);

    win.attach(grid);

    win.attach(img100px);

    int randomValue = 0;

    // moving img
    //  ----------segmentation fault(core dumped)----------------

    // for (int i = 0; i < 10; i++)
    // {
    //     randomValue = ((rand() % 8) + 1) * 100;
    //     img100px.move(randomValue, randomValue);
    //     win.wait_for_button();
    // }

    win.wait_for_button();
}
catch (exception &e)
{
    // error
    return 1;
}
catch (...)
{
    // error
    return 2;
}
