/*
 * result
 *
 * 20
 * 10
 * 20
 * 10
 * 20
 * 10
 * 0
 *
 */

#include <iostream>
using namespace std;

class CPolygon {
protected:
	int width, height;
public:
	void set_values(int a, int b) {
		width = a;
		height = b;
	}
	
	// virtual member
	// after added to the father class,
	// the pointer of father class can use
	// the area function
	virtual int area(void) {
		return 0;
	}
};

class COutput {
public:
	void output(int i);
};

void COutput::output(int i) {
	cout << i << endl;
}

class CRectangle : public CPolygon, public COutput {
public:
	int area(void) {
		return width * height;
	}
};

class CTriangle : public CPolygon, public COutput {
public:
	int area(void) {
		return width * height / 2;
	}
};

int main() {
	CRectangle rect;
	CTriangle trgl;
	rect.set_values(4, 5);
	trgl.set_values(4, 5);
	rect.output(rect.area());
	trgl.output(trgl.area());
	
	CRectangle rect2;
	CTriangle trgl2;
	CPolygon* ppoly1 = &rect2;
	CPolygon* ppoly2 = &trgl2;
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	cout << rect2.area() << endl;
	cout << trgl2.area() << endl;
	
	CRectangle rect3;
	CTriangle trgl3;
	CPolygon poly;
	ppoly1 = &rect3;
	ppoly2 = &trgl3;
	CPolygon* ppoly3 = &poly;
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	ppoly3->set_values(4, 5);
	cout << ppoly1->area() << endl;
	cout << ppoly2->area() << endl;
	cout << ppoly3->area() << endl;
	
	return 0;
}
