/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x * x; }

int main()
{
    using namespace Graph_lib;

    int xMax = 1280;
    int yMax = 720;

    int xOrig = xMax / 2;
    int yOrig = yMax / 2;

    int rmin = -11;
    int rmax = 11;

    int nPoints = 400;

    Simple_window win{Point{100, 100}, xMax, yMax, "Canvas"};

    Point origo{xOrig, yOrig};

    int xLength = xMax - 10;
    int yLength = yMax - 40;

    int xScale = 30;
    int yScale = 30;

    Function s(one, rmin, rmax, origo, nPoints, xScale, yScale);
    Function sq(square, rmin, rmax, origo, nPoints, xScale, yScale);
    Function cosFunc([](double x)
                     { return cos(x); },
                     rmin, rmax, origo, nPoints, xScale, yScale);

    Axis x{Axis::x, Point{20, yOrig}, xLength, xLength / xScale, "x"};
    Axis y{Axis::y, Point{xOrig, yLength + 20}, yLength, yLength / yScale, "y"};

    Rectangle r{Point{200, 200}, 100, 50};
    r.set_fill_color(Color::yellow);
    r.set_style(Line_style(Line_style::dash, 4));

    Text t{Point{200, 400}, "Hello graphics!"};
    t.set_font(Font::times_bold);
    t.set_font_size(20);

    Image ii{Point{400, 100}, "chad_cat.jpg"};

    Circle c{Point{400, 400}, 50};

    win.attach(ii);
    win.attach(c);
    win.attach(t);
    win.attach(r);
    win.attach(s);
    win.attach(sq);
    win.attach(cosFunc);
    win.attach(x);
    win.attach(y);

    win.wait_for_button();
}
