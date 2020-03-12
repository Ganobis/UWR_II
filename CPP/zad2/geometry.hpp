#ifdef GEOMETRY_HPP
#define GEOMETRY_HPP


Point inter(Line l1, Line l2);
Vector two_vec(Vector v1, Vector v2);

class Point
{
public:
	double x;
	double y;

	Point();
	Point(double x, double y);
	Point(const Vector &v, const Point &p);
	Point(const Point &p);
};

class Vector
{
public:
	double dx;
	double dy;
	
	Vector();
	Vector(double dx, double dy);
	Vector(const Vector &vector);
};

class Line
{
private:
	double a;
	double b;
	double c;
public:
	Line();
	Line(Point p1, Point p2);
	Line(Vector v1);
	Line(double a, double b, double c);
	Line(Line l1, Vector v1);
	
	double getA();
	double getB();
	double getC();

	bool is_prep(Vector v1);
	double how_far(Point p1);
};