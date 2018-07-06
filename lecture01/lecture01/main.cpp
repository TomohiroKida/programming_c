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
	// Šp“x‚ğ‚P“x‚¸‚Â•Ï‚¦‚½‚Æ‚«‚Ì‚˜C‚™‚Ì’l‚ğ‹‚ß‚é
	// ‚O“x‚©‚ç‚R‚U‚O“x‚Ü‚Å
	// ”z—ñ‚É“ü‚ê‚éD
	r = 1.0;
	for (int i = 0; i < N; i++) {
		th = M_PI * (double)i/N;
		x[i] = r * cos(th);
		y[i] = r * sin(th);
	}

	// ‚Q“_ŠÔ‚Ì’·‚³‚ğ‹‚ß‚éŠÖ”‚ğ‹‚ß‚æ
	// 0,1 1,2 ... 359,360 ‚Ì’·‚³‚ğ‹‚ßA‰ÁZ‚µ‚½’l‚ğ‹‚ß‚é
	pi = 0.0;
	for (int i = 0; i < N-1; i++)
	{
		pi += length(x[i], y[i], x[i + 1], y[i + 1]);
	}
	//pi += length(x[N - 1], y[N - 1], x[0], y[0]);
	// ‚»‚Ì’l‚©‚ç/r*2‚ğ‚µ‚½‚Æ‚«‚Ì’l‚ªpi‚É‹ß‚­‚È‚é‚±‚Æ‚ğ“š‚¦‚æ
	pi = pi / r;
	printf("%d", pi);

	// Šp“x‚ğ‚P‚¸‚Â•Ï‚¦‚Ä‚¢‚½‚ªA‚R‚U‚O“x‚ğ‚R‚U‚O“™•ª‚µ‚Ä‚¢‚½‚Æ‚µ‚ÄA
	// N“™•ª‚Å‚«‚é‚æ‚¤‚Édefine•¶‚Å•\‚í‚¹

	return 0;
}