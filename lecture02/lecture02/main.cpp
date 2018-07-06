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
	// �p�x���P�x���ς����Ƃ��̂��C���̒l�����߂�
	// �O�x����R�U�O�x�܂�
	// �z��ɓ����D
	r = 1.0;
	for (int i = 0; i < N; i++) {
		th = M_PI * (double)i/N;
		x[i] = r * cos(th);
		y[i] = r * sin(th);
	}

	// �Q�_�Ԃ̒��������߂�֐������߂�
	// 0,1 1,2 ... 359,360 �̒��������߁A���Z�����l�����߂�
	pi = 0.0;
	for (int i = 0; i < N-1; i++)
	{
		pi += length(x[i], y[i], x[i + 1], y[i + 1]);
	}
	//pi += length(x[N - 1], y[N - 1], x[0], y[0]);
	// ���̒l����/r*2�������Ƃ��̒l��pi�ɋ߂��Ȃ邱�Ƃ𓚂���
	pi = pi / r;
	printf("%d", pi);

	// �p�x���P���ς��Ă������A�R�U�O�x���R�U�O�������Ă����Ƃ��āA
	// N�����ł���悤��define���ŕ\�킹

	return 0;
}