#include <iostream>
#include <fstream>
#include <vector>
#include "../src/complex.cpp"

// z(n+1) = z^2 + c

struct rgb {
	unsigned char r;
	unsigned char g;
	unsigned char b;	
};

vector<vector<rgb>> graph(500, vector<rgb>(500));

void plot(const complex& c) {
	//int y = (int)im(c) + 500;
	//int x = (int)re(c) + 500;
	//std::cout << "x: " << x << " y: " << y << std::endl; 
	//graph[y][x] = 1;
}

int main() {
	plot(z);
	for(double y = -2; y <= 2; y = y + 0.001) {
		for(double x = -2; x <= 2; x = x + 0.001) {
			complex z(0,0);
			complex c(x,y);
			bool flag = 0;
			while(true) {
				int iters = 0;
				if(distanceFromOrigin(z) < 2 && iters < 20) {
					z = (z*z) + c;
				}
				else {
					flag = 1;
					break;
				}
				iters++;
			}
			if(flag == 1) {}
		}
	}
}