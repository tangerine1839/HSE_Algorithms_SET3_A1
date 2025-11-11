#include <algorithm>
#include <iostream>
#include <random>

class Circle
{
public:
    double r;
    double x;
    double y;
};

double findMaxX(Circle c1, Circle c2, Circle c3)
{
    double x1 = c1.x + c1.r;
    double x2 = c2.x + c2.r;
    double x3 = c3.x + c3.r;
    return std::min({x1, x2, x3});
}

double findMinX(Circle c1, Circle c2, Circle c3)
{
    double x1 = c1.x - c1.r;
    double x2 = c2.x - c2.r;
    double x3 = c3.x - c3.r;
    return std::max({x1, x2, x3});
}

double findMaxY(Circle c1, Circle c2, Circle c3)
{
    double y1 = c1.y + c1.r;
    double y2 = c2.y + c2.r;
    double y3 = c3.y + c3.r;
    return std::min({y1, y2, y3});
}

double findMinY(Circle c1, Circle c2, Circle c3)
{
    double y1 = c1.y - c1.r;
    double y2 = c2.y - c2.r;
    double y3 = c3.y - c3.r;
    return std::max({y1, y2, y3});
}

bool isInCircle(double cx, double cy, double r, double x, double y)
{
    return pow((x - cx), 2) + pow((y - cy), 2) <= pow(r, 2);
}

double calculateArea(double x_max, double x_min, double y_max, double y_min, Circle c1, Circle c2, Circle c3, int number_of_generated_points)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib_x(x_min, x_max);
    std::uniform_real_distribution<> distrib_y(y_min, y_max);
    int count = 0;
    for (int i = 0; i < number_of_generated_points; ++i)
    {
        double x = distrib_x(gen);
        double y = distrib_y(gen);
        if (isInCircle(c1.x, c1.y, c1.r, x, y) && isInCircle(c2.x, c2.y, c2.r, x, y)
            && isInCircle(c3.x, c3.y, c3.r, x, y))
        {
            count++;
        }
    }
    double rectangle_square = (x_max - x_min) * (y_max - y_min);
    return (static_cast<double>(count) / number_of_generated_points) * rectangle_square;
}
int main()
{
    double x;
    double y;
    double r;
    Circle c1;
    Circle c2;
    Circle c3;
    c1.x = 1.0;
    c1.y = 1.0;
    c1.r = 1.0;

    c2.x = 1.5;
    c2.y = 2.0;
    c2.r = sqrt(5.0) / 2.0;

    c3.x = 2.0;
    c3.y = 1.5;
    c3.r = sqrt(5.0) / 2.0;

    double x_max = findMaxX(c1,c2,c3);
    double x_min = findMinX(c1,c2,c3);
    double y_max = findMaxY(c1,c2,c3);
    double y_min = findMinY(c1,c2,c3);

    for (int i = 100; i <= 100000; i += 500)
    {
        double area = calculateArea(x_max, x_min, y_max, y_min, c1, c2, c3, i);
        std::cout << i << " " << area << std::endl;
    }
}