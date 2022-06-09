#include <iostream>

using namespace std;

class Shape
{
    public:
        void setwidth(int wid)
        {
            width = wid;
        }

        void setheight(int hei)
        {
            height = hei;
        }
    
    protected:
        int width;
        int height;
};

class PaintCost
{
    public:
        int getcost(int area)
        {
            return area * 70;
        }
};

class Rectangle: public Shape, public PaintCost
{
    public:
        int getArea()
        {
            return (width * height);
        }
};

int main(int argc, char const *argv[])
{
    Rectangle Rect;
    int area;

    Rect.setheight(10);
    Rect.setwidth(5);

    area = Rect.getArea();

    cout << "Total area: " << area << endl;

    cout << "Total paint cost: $" << Rect.getcost(area) << endl;
    
    return 0;
}
