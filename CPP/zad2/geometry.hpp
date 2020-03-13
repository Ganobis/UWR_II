#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

class Vector
{
public:
	const double dx;
	const double dy;
	
	Vector();
	Vector(double dx_f, double dy_f);
	Vector(const Vector &vector);
};

class Point
{
public:
	const double x;
	const double y;

	Point();
	Point(double x_f, double y_f);
	Point(const Vector &v, const Point &p);
	Point(const Point &p);
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
	Line(double a_f, double b_f, double c_f);
	Line(Line l1, Vector v1);
	
	double getA();
	double getB();
	double getC();

	bool is_prep(Vector v1);
	double how_far(Point p1);
};

double normal(double a, double b, double c);
Point inter(Line l1, Line l2);
Vector two_vec(Vector v1, Vector v2);

#endif