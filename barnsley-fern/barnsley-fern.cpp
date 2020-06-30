#include <fstream>
#include <math.h>

// -2.1820 < x < 2.6558 
// 0 <= y <9.9983
// p = 0.01,0.85,0.07,0.07

struct point {
	double x;
	double y;
	point(x,y) {
		this->x = x;
		this->y = y;
	}
	point(){
		this->x = 0;
		this->y = 0;
	}
};

point f1(const point& p) {
	point res;
	res.x = 0;
	res.y = 0.16 * p.y;
}

point f2(const point& p) {
	point res;
	res.x = (0.85 * p.x) + (0.04 * p.y);
	res.y = (-0.04 * p.x) + (0.85 * p.y) + 1.6;
	return res;
}

point f3(const point& p) {
	point res;
	res.x = (0.2 * p.x) - (0.26 * y);
	res.y = (0.23 * p.x) + (0.22 * p.y) + 1.6;
	return res;
}

point f4(const point& p) {
	point res;
	res.x = (-0.15 * p.x) + (0.28 * p.y);
	res.y = (0.26 * p.x) + (0.24 * p.y) + 0.44;
}

int main() {
	bool plot[1024][1024] = { 0 };
	point a;
	plot[a.x][a.y] = 1;
	for(int i = 0; i < 100; i++) {
		int p = rand() % 100;
		if(p == 1) {
			a = f1(a);
			plot[a.x][a.y] = 1;
		}
		else if(p < 86) {
			a = f2(a);
			plot[a.x][a.y] = 1;
		}
		else if(p < 94) {
			a = f3(a);
			plot[a.x][a.y] = 1;
		}
		else {
			a = f4(a);
			plot[a.x][a.y] = 1;
		}
	}
}