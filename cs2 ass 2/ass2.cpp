//yousef abbas 900225244
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class point {
private:
	float x;
	float y;
public:
	point() {
		x = 0;
		y = 0;
	}
	point(float X, float Y) {
		x = X;
		y = Y;
	}
	void Setx(float X) {
		x = X;
	}
	void Sety(float Y) {
		y = Y;
	}
	float Getx() {
		return x;
	}
	float Gety() {
		return y;
	}
	void Display() {
		cout << "(" << x << "," << y << ")"<<endl;
	}
	float Distance(point p) {
		return sqrt(pow(this->x - p.Getx(), 2) + pow(this->y - p.Gety(), 2));
	}
};
point Center(point* C, int n) {
	float sumx=0;
	float sumy=0;
	for (int i = 0; i < n; i++) {
		sumx += C[i].Getx();
	}
	float avgx = sumx / n;
	for (int i = 0; i < n; i++) {
		sumy += C[i].Gety();
	}
	float avgy = sumy / n;
	return point(avgx, avgy);
}
point ClosestCluster(point* A, point* B, int n, point p) {
	float distanceA = Center(A, n).Distance(p);
	float distanceB = Center(B, n).Distance(p);
	if (distanceA < distanceB)
		return Center(A, n);
	else
		return Center(B, n);
}


int main() {
	int n,m;
	m = 20;
	cout << "enter the number of points in each cluster";
	cin >> n;
	point* A = new point[n];
	point* B = new point[n];
	point* pts = new point[m];
	srand(time(0));
	//filling cluster A
	for (int i = 0; i < n; i++) {
		A[i].Setx((rand() % 210 + 700) / 10.0)  ;
		A[i].Sety((rand() % 210 + 700) / 10.0)  ;
	}
	//filling cluster B
	for (int i = 0; i < n; i++) {
		B[i].Setx((rand() % 210 + 200) / 10.0);
		B[i].Sety((rand() % 210 + 200) / 10.0);
	}
	//Generating m points
	for (int i = 0; i < m; i++) {
		pts[i].Setx((rand() %  960+50) / 10.0);
		pts[i].Sety((rand() %  960+50) / 10.0);
	}
	for (int i = 0; i < m; i++) {
		//for checking
		Center(A,n).Display();
		cout<<"distance between center A: "<<Center(A, n).Distance(pts[i]) << endl;
		Center(B, n).Display();
		cout <<"distance between center B: "<<Center(B, n).Distance(pts[i])<<endl;
		pts[i].Display();
		//output
		if (ClosestCluster(A, B, n, pts[i]).Getx() == Center(A, n).Getx() && ClosestCluster(A, B, n, pts[i]).Gety() == Center(A, n).Gety()){
			cout << "A is closer "<<endl;
		}
		else
			cout << "B is closer "<<endl;
	}

	return 0;
}