/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

// using namespace Graph_lib;

int main()
try
{
    Point tl(150, 150);
    

    Simple_window win(tl, 800, 600, "My Window");

    Axis xa(Axis::x,Point(20, 300), 600, 10, "x axis");
    Axis ya(Axis::y,Point(20, 300), 280, 10, "y axis");
    ya.set_color(Color::dark_blue);
    ya.label.set_color(Color::red);

    Function sine(sin,0,100,Point(20,150),1000,50,50);
    sine.set_color(Color::cyan);
    // plot sin() in the range (0:100) with (0,0) at (20,150)


    Polygon poly;
    poly.add(Point(300,200));
    poly.add(Point(350,100));
    poly.add(Point(400,200));
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);

    Rectangle r(Point(200,200),100,50);

    Closed_polyline poly_rect;
    poly_rect.add(Point(100,50));
    poly_rect.add(Point(200,50));
    poly_rect.add(Point(200,100));
    poly_rect.add(Point(100,100));
    poly_rect.add(Point(50,75));
    
    r.set_fill_color(Color::green);
    poly.set_style(Line_style(Line_style::dash,5));
    poly_rect.set_style(Line_style(Line_style::dash,6));

    Text t(Point(150,150), "Hello, Graphical world!");
    t.set_font(Font::helvetica);
    t.set_font_size(20);

    Image ii(Point(300, 130), "chad_cat.jpg");

    Circle c(Point(100,200),50);
    Ellipse e(Point(100,200),75,25);
    e.set_color(Color::dark_red);
    Mark m(Point(100,200),'x');

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes(Point(150,580),oss.str());
    sizes.set_font_size(25);

    Image cal(Point(220,250),"chad_cat.jpg");
    cal.set_mask(Point(40,40),200,150);

    win.attach(ii);
    win.attach(c);
    win.attach(m);
    win.attach(e);
    win.attach(sizes);
    win.attach(cal);
    win.attach(t);
    win.attach(poly_rect);
    win.attach(r);
    win.attach(poly);
    win.attach(sine);
    win.attach(xa);
    win.attach(ya);
    // win.set_label("My Window #2"); //rename window
    win.wait_for_button();


}
catch(exception& e)
{
    //error
    return 1;
}
catch(...)
{
    //error
    return 2;
}
