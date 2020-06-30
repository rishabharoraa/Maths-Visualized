#include <fstream>

bool graph[1024][1024] = { 0 };

struct point {
	double x;
	double y;

	point(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

int main() {
	point a(0,0);
}