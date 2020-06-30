#include <iostream>
#include <fstream>


// -2.1820 < x < 2.6558 
// 0 <= y <9.9983
// p = 0.01,0.85,0.07,0.07

// graph here is a graph in a mathematical sense.
const int height = 10000, width = 5000;
bool graph[10000][5000] = { 0 };

struct point {
	double x;
	double y;
	point(double x,double y) {
		this->x = x;
		this->y = y;
	}
	point(){
		this->x = 0;
		this->y = 0;
	}
};

void plot(const point& p) {
	int x = (int) (p.x * 1000) + 2182;
	int y = abs((int) (p.y * 1000) - 10000);
	graph[y][x] = 1;
}

point f1(const point& p) {
	point res;
	res.x = 0;
	res.y = 0.16 * p.y;
	return res;
}

point f2(const point& p) {
	point res;
	res.x = (0.85 * p.x) + (0.04 * p.y);
	res.y = (-0.04 * p.x) + (0.85 * p.y) + 1.6;
	return res;
}

point f3(const point& p) {
	point res;
	res.x = (0.2 * p.x) - (0.26 * p.y);
	res.y = (0.23 * p.x) + (0.22 * p.y) + 1.6;
	return res;
}

point f4(const point& p) {
	point res;
	res.x = (-0.15 * p.x) + (0.28 * p.y);
	res.y = (0.26 * p.x) + (0.24 * p.y) + 0.44;
	return res;
}

int main() {
	point a;
	graph[0][0] = 1;
	for(int i = 0; i < 500000; i++) {
		int p = rand() % 100;
		if(p == 1) {
			a = f1(a);
			plot(a);
		}
		else if(p < 86) {
			a = f2(a);
			plot(a);
		}
		else if(p < 94) {
			a = f3(a);
			plot(a);
		}
		else {
			a = f4(a);
			plot(a);
		}
	}

	std::ofstream img("fern.ppm");
	img << "P3" << std::endl;					//specification identifier
	img << width << " " << height << std::endl;  //height and width
	img << "255" << std::endl;					//max value of color components

	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if(graph[i][j] == 1) {
				img << "0 255 0" << std::endl;
			}
			else {
				img << "255 255 255" << std::endl;
			} 
		}
	} 

	return 0;
}