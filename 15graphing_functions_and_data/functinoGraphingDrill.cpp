/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }

double slope(double x) { return x / 2; }

double square(double x) { return x * x; }

double slopingCos(double x) { return cos(x) + slope(x); }
int main()
{
    const int xMax = 600;
    const int yMax = 600;

    const int xOrig = xMax / 2;
    const int yOrig = yMax / 2;

    Point orig(xOrig, yOrig);

    const int rangeMin = -10;
    const int rangeMax = 11;

    const int nPoints = 400;

    const int xScale = 20;
    const int yScale = 20;

    const int xLength = xMax - 200;
    const int yLength = yMax - 200;

    Point tl(100, 100);

    Simple_window win{tl, xMax, yMax, "Function graphs."};

    Axis x{Axis::x, Point{100, yOrig}, nPoints, xLength / xScale, "1 == 20 pixels"};
    Axis y{Axis::y, Point{xOrig, 500}, nPoints, yLength / yScale, "1 == 20 pixels"};

    x.set_color(Color::red);
    y.set_color(Color::red);

    // Function s(one, rangeMin, rangeMax, orig, nPoints);
    Function s(one, rangeMin, rangeMax, orig, nPoints, xScale, yScale);

    Function s2(slope, rangeMin, rangeMax, orig, nPoints, xScale, yScale);
    Text t(Point(100, yOrig + 4 * yScale), "x/2");

    Function s3(square, rangeMin, rangeMax, orig, nPoints, xScale, yScale);

    Function s4(cos, rangeMin, rangeMax, orig, nPoints, xScale, yScale);
    s4.set_color(Color::blue);

    Function s5(slopingCos, rangeMin, rangeMax, orig, nPoints, xScale, yScale);

    win.attach(s5);
    win.attach(s4);
    win.attach(s3);
    win.attach(t);
    win.attach(s2);
    win.attach(s);
    win.attach(x);
    win.attach(y);
    win.wait_for_button();
}
