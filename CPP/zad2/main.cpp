#include <iostream>

class Point
{
public:
	double const x;
	double const y;

	Point(){
		this->x = 0;
		this->y = 0;
	}
	Point(double x, double y){
		this->x = x;
		this->y = y;
	}
	Point(const Vector &v, const Point &p){
		this->x = p.x + v.dx;
		this->y = p.y + v.dy;
	}
	Point(const Point &p){
		this->x = p.x;
		this->y = p.y;
	}
	~Point();
	
};

class Vector
{
public:
	double const dx;
	double const dy;
	
	Vector(){
		this->dx = 0;
		this->dy = 0;
	}
	Vector(double dx, double dy){
		this->dx = dx;
		this->dy = dy;
	}
	Vector(const Vector &vector){
		this->dx = vector.dx;
		this->dy = vector.dy;
	}
	~Vector();

	Vector  
	
};

class Line
{
private:
	double a;
	double b;
	double c;
public:
	Line(){
	}
	~Line();
	
	double getA(){
		return a;
	}
	double getB(){
		return b;
	}
	double getC(){
		return c;
	}
};

Vector additon(Vector &v1, Vector &v2){
	return new Vector(v1.dx + v2.dx, v1.dy + v2.dy);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}