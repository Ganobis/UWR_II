#include "geometry.hpp"

#include <cmath>

Point::	Point(){
	this->x = 0;
	this->y = 0;
}

Point::	Point(double x, double y){
	this->x = x;
	this->y = y;
}

Point::Point(const Vector &v, const Point &p){
	this->x = p.x + v.dx;
	this->y = p.y + v.dy;
}

Point::	Point(const Point &p){
	this->x = p.x;
	this->y = p.y;
}

Vector::Vector(){
	this->dx = 0;
	this->dy = 0;
}

Vector::Vector(double dx, double dy){
	this->dx = dx;
	this->dy = dy;
}

Vector::Vector(const Vector &vector){
	this->dx = vector.dx;
	this->dy = vector.dy;
}

Line::Line(){
	a = 1;
	b = -1;
	c = 0;
}

Line::Line(Point p1, Point p2){
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
	{
		std::cout<<"Błędne dane!";
	}
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

}
