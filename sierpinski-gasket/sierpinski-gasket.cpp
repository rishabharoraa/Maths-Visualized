// I didnt include .ppm output file as filesize was very large
// Even uncompressed png file is around 300mb

#include <fstream>
#include <vector>
#define LIMIT 500000000

const int side = 10000;
bool graph[side][side] = { 0 };


struct point {
	int x;
	int y;

	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

void plot(const point& p) {
	graph[abs(p.y - side)][p.x] = 1;
}

int main() {
	point a(0,650);
	point b(10000,650);
	point c(5000,9310);
	std::vector<point> p{a,b,c};
	point temp1 = p[rand() % 3];
	point temp2 = p[rand() % 3];

	plot(a);
	plot(b);
	plot(c);
	// image buffer
	for(unsigned long i = 0; i < LIMIT; i++) {
		temp2.x = (int)(temp2.x + temp1.x) / 2;
		temp2.y = (int)(temp2.y + temp1.y) / 2;
		plot(temp2);
		temp1 = p[rand() % 3];
	}	

	std::ofstream img ("gasket.ppm");
	img << "P3" << std::endl;
	img << side << ' ' << side << std::endl;
	img << "255" << std::endl;

	for(int i = 0; i < side; i++) {
		for(int j = 0; j < side; j++) {
			if(graph[i][j] == 1) {
				img << (int) (j * 255 / side) % 255 << ' '<< (int) (i * 255 / side) % 255 << ' ' << (int) (j*i*255 / side) % 255 << std::endl;
			}
			else {
				img << "0 0 0" << std::endl;
			}
		}
	}
	//writing to file
}