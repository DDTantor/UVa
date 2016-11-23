#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
	double h, m;
	while (cin >> h, h)
	{
		cin.ignore();
		cin >> m;
		h += (m / 60.0);
		double alfa = m/60.0 * 360;
		double beta = h/12.0 * 360;
		double angle = abs(alfa - beta);
		if (angle > 180)
			angle = 360.0 - angle;
		printf("%.3f\n", angle);
	}
}
