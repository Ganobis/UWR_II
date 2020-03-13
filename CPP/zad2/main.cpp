#include <iostream>
#include <cmath>
#include "geometry.hpp"

using namespace std;


int main()
{
	Point p1(1, 2);
	Point p2(p1);
	Point p3(0, 0);
	Point p4();
	cout << "Proste testy:\n";
	cout << "Punkt1:(" << p1.x << ", " << p1.y << ")\n";
	cout << "Punkt2:(" << p2.x << ", " << p2.y << ")\n";
	cout << "Punkt3:(" << p3.x << ", " << p3.y << ")\n";
	Vector v1(1, 1);
	Vector v2(v1);
	Vector v3(-1, -2);
	Vector v4();
	cout << "Wektor1:[" << v1.dx << ", " << v1.dy <<"]\n";
	cout << "Wektor2:[" << v2.dx << ", " << v2.dy <<"]\n";
	cout << "Wektor3:[" << v3.dx << ", " << v3.dy <<"]\n";
	Line l1(p1, p3);
	Line l2(v1);
	Line l3(1, 1, 0);
	Line l4();
	cout << "Prosta1: A = " << l1.getA() << ", B = " << l1.getB() << ", C = " << l1.getC() << endl;
	cout << "Prosta2: A = " << l2.getA() << ", B = " << l2.getB() << ", C = " << l2.getC() << endl;
	cout << "Prosta3: A = " << l3.getA() << ", B = " << l3.getB() << ", C = " << l3.getC() << endl;

	cout << "Punkt p1 jest oddalony od l1 o " << l1.how_far(p1) << endl;
	cout << "Czy v2 jest prostopadły do l2?: " << l2.is_prep(v2) << endl; 

	cout << "Punkt przecięcia l1 i l3: (" << inter(l1, l3).x << ", " << inter(l1, l3).y << ")\n";
	cout << "Złożenie wektora v1 i v3: [" << two_vec(v1, v3).dx << ", " << two_vec(v1, v3).dy << "]\n";
	
	cout << "\n\nTrudniejsze testy:\n";

	Point P1((-1)*sqrt(34.12), log10(732.11));
	Point P2(627.11, pow(-2.137, 3));
	Point P3(-91826611.21, 1.1010101);
	Point P4(P1);
	cout << "Punkt1:(" << P1.x << ", " << P1.y << ")\n";
	cout << "Punkt2:(" << P2.x << ", " << P2.y << ")\n";
	cout << "Punkt3:(" << P3.x << ", " << P3.y << ")\n";
	cout << "Punkt4:(" << P4.x << ", " << P4.y << ")\n";

	Vector V1(log(412), -421.11);
	Vector V2(pow(-51, 3), 43.12222);
	Vector V3(V1);
	cout << "Wektor1:[" << V1.dx << ", " << V1.dy <<"]\n";
	cout << "Wektor2:[" << V2.dx << ", " << V2.dy <<"]\n";
	cout << "Wektor3:[" << V3.dx << ", " << V3.dy <<"]\n";

	Point P5(V3, P2);
	cout << "Punkt5:(" << P5.x << ", " << P5.y << ")\n";

	Line L1(sqrt(4281), -631.33, log(918291));
	Line L2(V3);
	Line L3(P1, P5);
	Line L4(L1, V2);

	cout << "Prosta1: A = " << L1.getA() << ", B = " << L1.getB() << ", C = " << L1.getC() << endl;
	cout << "Prosta2: A = " << L2.getA() << ", B = " << L2.getB() << ", C = " << L2.getC() << endl;
	cout << "Prosta3: A = " << L3.getA() << ", B = " << L3.getB() << ", C = " << L3.getC() << endl;
	cout << "Prosta4: A = " << L4.getA() << ", B = " << L4.getB() << ", C = " << L4.getC() << endl;

	cout << "Punkt P1 jest oddalony od L1 o " << L1.how_far(P1) << endl;
	cout << "Czy V3 jest prostopadły do L4?: " << L4.is_prep(V3) << endl; 


	return 0;
}