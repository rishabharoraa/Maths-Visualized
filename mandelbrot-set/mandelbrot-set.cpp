#include <iostream>
#include <fstream>
#include <vector>
#include "../src/complex.cpp"

// z(n+1) = z^2 + c
const int side = 100;

unsigned char graph[side][side] = { 0 };

void plot(const complex& c, unsigned char value) {
	int y = (int)(im(c)*(side/2))+(side/2);
	int x = (int)(re(c)*(side/2))+(side/2);
	graph[y][x] = value;
}


int main() {
	for(double y = -2; y < 2; y = y + 0.1) {
		for(double x = -2; x < 2; x = x + 0.1) {
			complex c(x,y);
			if(distanceFromOrigin(c) <= 2) {
				plot(c,1);
				//if(distanceFromOrigin((z*z) + c) <= 2) {
				//	z = (z*z) + c;
				//	plot(c,2);
				//}
			}
			c.~complex();
		}
	}
	std::ofstream img ("test.ppm");
	img << "P3" << std::endl;
	img << side << ' ' << side << std::endl;
	img << "255" << std::endl;
	for(int y = 0; y < side; y++) {
		for(int x = 0; x < side; x++) {
			if(graph[y][x] == 1) {
				img << "255 255 255" << std::endl;
			}
			else if(graph[y][x] == 2) {
				img << "0 255 0" << std::endl;
			}
			else if(graph[y][x] == 3) {
				img << "0 0 255" << std::endl;
			}
			else {
				img << "255 0 0" << std::endl;
			}
		}
	}
}