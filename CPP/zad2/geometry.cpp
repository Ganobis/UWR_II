#include "geometry.hpp"

#include <cmath>
#include <stdexcept>

Vector::Vector(): dx(0), dy(0){

}

Vector::Vector(double dx_f, double dy_f): dx(dx_f), dy(dy_f){

}

Vector::Vector(const Vector &vector): dx(vector.dx), dy(vector.dy){

}

Point::Point() : x(0.0), y(0.0){

}

Point::Point(double x_f, double y_f) : x(x_f), y(y_f){

}

Point::Point(const Vector &v, const Point &p) : x(p.x + v.dx), y(p.y + v.dy){

}

Point::Point(const Point &p) : x(p.x), y(p.y){

}

double normal(double a, double b, double c){
	double mi = 1/(sqrt(pow(a, 2) + pow(b, 2)));
	return (c > 0) ? mi : (-1)*mi;
}

Line::Line(){
	a = normal(1, 1, 0); //y = x
	b = normal(1, 1, 0);
	c = 0;
}

Line::Line(Point p1, Point p2){
	if(p1.x == p2.x && p1.y == p2.y)
		throw std::invalid_argument("Cannot make line form one point!");
	double temp_a = p1.y - p2.y;
	double temp_b = p2.x - p1.x;
	double temp_c = (p1.y * (p2.x - p1.x) + p1.x * (p1.y - p2.y));

	a = temp_a*normal(temp_a, temp_b, temp_c);
	b = temp_b*normal(temp_a, temp_b, temp_c);
	c = temp_c*normal(temp_a, temp_b, temp_c);
}
Line::Line(Vector v1){
	double temp_a = v1.dx;
	double temp_b = v1.dy;

	a = temp_a*normal(temp_a, temp_b, 0);
	b = temp_b*normal(temp_a, temp_b, 0);
	c = 0;
}

Line::Line(Line l1, Vector v1){
	a = l1.getA();
	b = l1.getB();
	c = l1.getC() + sqrt(pow(v1.dx, 2) + pow(v1.dy, 2));
}

Line::Line(double a_f, double b_f, double c_f){
	if (a_f == 0 || b_f ==0)
		throw std::invalid_argument("Cannot make line without A or B!");
	a = a_f*normal(a_f, b_f, c_f);
	b = b_f*normal(a_f, b_f, c_f);
	c = c_f*normal(a_f, b_f, c_f);
}

double Line::getA(){
	return a;
}
double Line::getB(){
	return b;
}
double Line::getC(){
	return c;
}

bool Line::is_prep(Vector v1){
	return (a/v1.dx == b/v1.dy);
}

double Line::how_far(Point p1){
	return (abs(a*p1.x + b*p1.y +c)/sqrt(pow(a, 2)+pow(b, 2)));
}


Point inter(Line l1, Line l2){
	double x;
	double y;
	try{
		x = (((l1.getB()*l2.getC())-(l2.getB()*l1.getC()))/((l1.getA()*l2.getB())-(l2.getA()*l1.getB())));
		y = (((l2.getA()*l1.getC())-(l1.getA()*l2.getC()))/((l1.getA()*l2.getB())-(l2.getA()*l1.getB())));
	}
	catch(const char* msg){
		throw std::invalid_argument("Lines are parallel");
	}
	return Point(x, y);
}

Vector two_vec(Vector v1, Vector v2){
	return Vector(v1.dx+v2.dx, v1.dy+v2.dy);
}