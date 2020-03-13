#include <iostream>
#include "geometry.hpp"

using namespace std;


int main()
{
	Point p1(1, 2);
	Point p2();
	Point p3(p1);
	Point p4(0, 0);
	cout << "Punkt1:(" << p1.x << ", " << p1.y << ")\n";
	//cout << "Punkt2:(" << p2.x << ", " << p2.y << ")\n";
	cout << "Punkt3:(" << p3.x << ", " << p3.y << ")\n";
	Vector v1(1, 1);
	Vector v2();
	Vector v3(v1);
	cout << "Wektor1:[" << v1.dx << ", " << v1.dy <<"]\n";
	//cout << "Wektor2:[" << v2.dx << ", " << v2.dy <<"]\n";
	cout << "Wektor3:[" << v3.dx << ", " << v3.dy <<"]\n";
	Line l1(p1, p4);
	Line l2(v1);
	Line l3(1, 1, 0);
	Line l4();
	cout << "Prosta1: A = " << l1.getA() << ", B = " << l1.getB() << ", C = " << l1.getC() << endl;
	cout << "Prosta2: A = " << l2.getA() << ", B = " << l2.getB() << ", C = " << l2.getC() << endl;
	cout << "Prosta3: A = " << l3.getA() << ", B = " << l3.getB() << ", C = " << l3.getC() << endl;
	//cout << "Prosta4: A = " << l4.getA() << ", B = " << l4.getB() << ", C = " << l4.getC() << endl;
	
	cout << "Punkt przecięcia l1 i l3: (" << inter(l1, l3).x << ", " << inter(l1, l3).y << ")\n";
	return 0;
}