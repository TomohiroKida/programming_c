#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define N 10

double length(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(fabs(x2 - x1), 2) + pow(fabs(y2 - y1), 2));
}

int main()
{
	// lecture01.sln
	// x^2*y*2=r*2
	// x=r*cos(th)
	// y=r*sin(th)
	double x[N], y[N];
	double r, th, pi;
	// 角度を１度ずつ変えたときのｘ，ｙの値を求める
	// ０度から３６０度まで
	// 配列に入れる．
	r = 1.0;
	for (int i = 0; i < N; i++) {
		th = M_PI * (double)i/N;
		x[i] = r * cos(th);
		y[i] = r * sin(th);
	}

	// ２点間の長さを求める関数を求めよ
	// 0,1 1,2 ... 359,360 の長さを求め、加算した値を求める
	pi = 0.0;
	for (int i = 0; i < N-1; i++)
	{
		pi += length(x[i], y[i], x[i + 1], y[i + 1]);
	}
	//pi += length(x[N - 1], y[N - 1], x[0], y[0]);
	// その値から/r*2をしたときの値がpiに近くなることを答えよ
	pi = pi / r;
	printf("%d", pi);

	// 角度を１ずつ変えていたが、３６０度を３６０等分していたとして、
	// N等分できるようにdefine文で表わせ

	return 0;
}