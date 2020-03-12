#include "geometry.hpp"

#include <cmath>

Vector::Vector(): dx(0), dy(0){

}

Vector::Vector(double dx, double dy): this->dx(dx), this->dy(dy){

}

Vector::Vector(const Vector &vector): dx(vector.dx), dy(vector.dy){

}

Point::	Point() : x(0), y(0){

}

Point::	Point(double x, double y) : this->x(x), this->y(y){

}

Point::Point(const Vector &v, const Point &p) : x(p.x + v.dx), y(p.y + v.dy){

}

Point::	Point(const Point &p) : x(p.x), y(p.y){

}

double Line::mi(double a, double b, double c){
	double mi = 1/(sqrt(pow(a, 2) + pow(b, 2)));
	return (c > 0) ? mi : (-1)*mi;
}

Line::Line(){
	
}

Line::Line(Point p1, Point p2){
	if(p1.x == p2.x && p1.y == p2.y)
		throw invalid_argument("Cannot make line form one point!");
	a = p1.y - p2.y;
	b = p2.x - p1.x;
	c = (p1.y * (p2.x - p1.x) + p1.x * (p1.y - p2.y));
}
Line::Line(Vector v1){
	a = v1.dx;
	b = v2.dy;

}

Line::Line(Line l1, Vector v1){

}

Line::Line(double a, double b, double c){
	if (a == 0 || b ==0)
		throw invalid_argument("Cannot make line without A or B!");
	this->a = a;
	this->b = b;
	this->c = c;
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
	return (a == v1.dx && b == v1.dy);
}

double Line::how_far(Point p1){
	return (abs(a*p1.x + b*p1.y +c)/sqrt(pow(a, 2)+pow(b, 2)));
}


Point inter(Line l1, Line l2){
	try{
		double x = (((l1.getB*l2.getC)-(l2.getB*l1.getC))/((l1.getA*l2.getB)-(l2.getA*l1.getB)));
		double y = (((l2.getA*l1.getC)-(l1.getA*l2.getC))/((l1.getA*l2.getB)-(l2.getA*l1.getB)));
	}
	catch(const char* msg){
		std::cerr << msg << endl;
	}
	return new Point(x, y);
}

Vector two_vec(Vector v1, Vector v2){
	return new Vector(v1.dx+v2.dx, v1.dy+v2.dy);
}