#include <bits/stdc++.h>

#define PI (3.14159265359)
#define DEG_TO_RAD(x) ((x)*(PI/180.0))
#define RAD_TO_DEG(x) ((x)*(180.0/PI))

using namespace std;

// epsilon
const int EPS = 1e-9;

// avoid doubles if possible
struct point_i {
	int x, y;
	point_i() { x = y = 0; }
	point_i(int _x, int _y) : x(_x), y(_y) {}
};

struct point {
	double x,y;
	point() { x = y = 0.0; }
	point(int _x, int _y) : x(_x), y(_y) {}

	bool operator < (point other) const {
		if( fabs(other.x - x) > EPS ) return x < other.x;
		else return y < other.y;
	}

	bool operator == (point other) const {
		return fabs(other.x-x) < EPS && fabs(other.y-y) < EPS;
	}
};

// get the hypotenuse of a right-angled triangle
double hypot(double dx, double dy){
	return sqrt(dx*dx + dy*dy);
}

// distance between two points
double dist(point p1, point p2){
	return hypot(p1.x-p2.x, p2.y-p1.y);
}

// rotation - with rotation matrix
point rotate(point p, double theta){
	double rad = DEG_TO_RAD(theta);
	return point(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
}

struct line { double a,b,c; };

// get the equation of a line connecting p1 and p2
void pointsToLine(point p1, point p2, line & l){
	if( fabs(p1.x-p2.x) < EPS ){
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;
	} else {
		l.a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a*p1.x) - p1.y;
	}
}

bool areParallel(line l1, line l2){
	return (fabs(l1.a-l2.a)<EPS && fabs(l1.b-l2.b)<EPS);
}

bool areSame(line l1, line l2){
	return (areParallel(l1,l2) && fabs(l1.c-l2.c)<EPS);
}

int main(){
}
