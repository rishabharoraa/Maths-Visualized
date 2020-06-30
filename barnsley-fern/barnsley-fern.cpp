#include <fstream>
#include <math.h>

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
	res.y = (-0.04 * p.x) + (0.85 * p.y) + (1.6);
	return res;
}

point f3(const point& p) {
	point res;
	res.x = 
}

int main() {
	bool mesh[1024][1024] = { 0 };

	double p[4] = {0.01,0.85,0.07,0.07};


}