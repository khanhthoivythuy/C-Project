#define _CRT_SECURE_NO_WARNINGS_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>



double fun1(double t, double theta1, double theta2, double omega1, double omega2, double m1, double m2, double L1, double L2);
double fun2(double t, double theta1, double theta2, double omega1, double omega2, double m1, double m2, double L1, double L2);


int main()
{
	//initial value
	double theta1 = 0, theta2 = 0, omega1 = 2, omega2 = 3;
	//RK4
	double dt = 0.01;
	double h = 0.1;
	double m1 = 1, m2 = 1;
	double L1 = 1, L2 = 1;



	//case 1 : mass ratio = 1
	//length ratio decreases from 1 to 0.2
	for (int j = 10; j >= 2; j--)
	{
		// j is ( the length ratio * 10 ) 
		L2 = L1 * (j / 10.0);
		int i;
		for (i = 1; i < 10; i++)
		{
			//find angular velocity of m1
			double K1_1 = h * fun1(dt, theta1, theta2, omega1, omega2, m1, m2, L1, L2);
			double K2_1 = h * fun1(dt + h / 2, theta1, theta2, omega1 + K1_1 / 2, omega2, m1, m2, L1, L2);
			double K3_1 = h * fun1(dt + h / 2, theta1, theta2, omega1 + K2_1 / 2, omega2, m1, m2, L1, L2);
			double K4_1 = h * fun1(dt + h, theta1, theta2, omega1 + K3_1, omega2, m1, m2, L1, L2);
			double omega_next_1 = omega1 + K1_1 / 6 + K2_1 / 3 + K3_1 / 3 + K4_1 / 6;
			//find angular velocity of m2
			double K1_2 = h * fun2(dt, theta1, theta2, omega1, omega2, m1, m2, L1, L2);
			double K2_2 = h * fun2(dt + h / 2, theta1, theta2, omega1 + K1_2 / 2, omega2, m1, m2, L1, L2);
			double K3_2 = h * fun2(dt + h / 2, theta1, theta2, omega1 + K2_2 / 2, omega2, m1, m2, L1, L2);
			double K4_2 = h * fun2(dt + h, theta1, theta2, omega1 + K3_2, omega2, m1, m2, L1, L2);
			double omega_next_2 = omega2 + K1_2 / 6 + K2_2 / 3 + K3_2 / 3 + K4_2 / 6;

			//change the initial value 
			omega1 = omega_next_1;
			theta1 = theta1 + omega1 * dt;
			omega2 = omega_next_2;
			theta2 = theta2 + omega2 * dt;

			//c1 and c2 are counting variable, if we find the period of one of two pendulums, the counting will be set to 1 and the computer wont run the "if" statement in the next step i. 
			// when both c1 and c2 are set to 1, which means that we found the periods of both pendulums, then we will leave the loop. 
			int c1 = 0, c2 = 0;
			if (theta1 == 0.0 && omega1 == 2.0 && c1 == 0)
			{
				printf(" the period of m1 in case mass ratio = 1 and length ration = %lf is %lf ", j / 10.0, dt * i);
				c1 = 1;
			}

			if (theta2 == 0.0 && omega2 == 3.0 && c2 == 0)
			{
				printf(" the period of m2 in case mass ratio = 1 and length ration = %lf is %lf ", j / 10.0, dt * i);
				c2 = 1;
			}
			if (c1 == 1 && c2 == 1) break;
		}

	}
	//length ratio increases from 1 to 2
	//initial value
	theta1 = 0, theta2 = 0, omega1 = 2, omega2 = 3;
	m1 = 1, m2 = 1;
	L1 = 1, L2 = 1;
	for (int j = 10; j <= 20; j++)
	{
		// j is ( the length ratio * 10 ) 
		L2 = L1 * (j / 10.0);
		int i;
		for (i = 1; i < 10; i++)
		{
			//find angular velocity of m1
			double K1_1 = h * fun1(dt, theta1, theta2, omega1, omega2, m1, m2, L1, L2);
			double K2_1 = h * fun1(dt + h / 2, theta1, theta2, omega1 + K1_1 / 2, omega2, m1, m2, L1, L2);
			double K3_1 = h * fun1(dt + h / 2, theta1, theta2, omega1 + K2_1 / 2, omega2, m1, m2, L1, L2);
			double K4_1 = h * fun1(dt + h, theta1, theta2, omega1 + K3_1, omega2, m1, m2, L1, L2);
			double omega_next_1 = omega1 + K1_1 / 6 + K2_1 / 3 + K3_1 / 3 + K4_1 / 6;
			//find angular velocity of m2
			double K1_2 = h * fun2(dt, theta1, theta2, omega1, omega2, m1, m2, L1, L2);
			double K2_2 = h * fun2(dt + h / 2, theta1, theta2, omega1 + K1_2 / 2, omega2, m1, m2, L1, L2);
			double K3_2 = h * fun2(dt + h / 2, theta1, theta2, omega1 + K2_2 / 2, omega2, m1, m2, L1, L2);
			double K4_2 = h * fun2(dt + h, theta1, theta2, omega1 + K3_2, omega2, m1, m2, L1, L2);
			double omega_next_2 = omega2 + K1_2 / 6 + K2_2 / 3 + K3_2 / 3 + K4_2 / 6;

			//change the initial value 
			omega1 = omega_next_1;
			theta1 = theta1 + omega1 * dt;
			omega2 = omega_next_2;
			theta2 = theta2 + omega2 * dt;
			//c1 and c2 are counting variable, if we find the period of one of two pendulums, the counting will be set to 1 and the computer wont run the "if" statement in the next step i. 
			// when both c1 and c2 are set to 1, which means that we found the periods of both pendulums, then we will leave the loop. 
			int c1 = 0, c2 = 0;
			if (theta1 == 0.0 && omega1 == 2.0 && c1 == 0)
			{
				printf(" the period of m1 in case mass ratio = 1 and length ration = %lf is %lf ", j / 10.0, dt * i);
				c1 = 1;
			}

			if (theta2 == 0.0 && omega2 == 3.0 && c2 == 0)
			{
				printf(" the period of m2 in case mass ratio = 1 and length ration = %lf is %lf ", j / 10.0, dt * i);
				c2 = 1;
			}
			if (c1 == 1 && c2 == 1) break;
		}

	}




	//case 2 : length ratio = 1
	//mass ratio decreases from 1 to 0.2
	//initial value
	theta1 = 0, theta2 = 0, omega1 = 2, omega2 = 3;
	m1 = 1, m2 = 1;
	L1 = 1, L2 = 1;
	for (int j = 10; j >= 2; j--)
	{
		// j is ( the mass ratio * 10 ) 
		m2 = m1 * (j / 10.0);
		int i;
		for (i = 1; i < 10; i++)
		{
			//find angular velocity of m1
			double K1_1 = h * fun1(dt, theta1, theta2, omega1, omega2, m1, m2, L1, L2);
			double K2_1 = h * fun1(dt + h / 2, theta1, theta2, omega1 + K1_1 / 2, omega2, m1, m2, L1, L2);
			double K3_1 = h * fun1(dt + h / 2, theta1, theta2, omega1 + K2_1 / 2, omega2, m1, m2, L1, L2);
			double K4_1 = h * fun1(dt + h, theta1, theta2, omega1 + K3_1, omega2, m1, m2, L1, L2);
			double omega_next_1 = omega1 + K1_1 / 6 + K2_1 / 3 + K3_1 / 3 + K4_1 / 6;
			//find angular velocity of m1
			double K1_2 = h * fun2(dt, theta1, theta2, omega1, omega2, m1, m2, L1, L2);
			double K2_2 = h * fun2(dt + h / 2, theta1, theta2, omega1 + K1_2 / 2, omega2, m1, m2, L1, L2);
			double K3_2 = h * fun2(dt + h / 2, theta1, theta2, omega1 + K2_2 / 2, omega2, m1, m2, L1, L2);
			double K4_2 = h * fun2(dt + h, theta1, theta2, omega1 + K3_2, omega2, m1, m2, L1, L2);
			double omega_next_2 = omega2 + K1_2 / 6 + K2_2 / 3 + K3_2 / 3 + K4_2 / 6;

			//change the initial value 
			omega1 = omega_next_1;
			theta1 = theta1 + omega1 * dt;
			omega2 = omega_next_2;
			theta2 = theta2 + omega2 * dt;
			//c1 and c2 are counting variable, if we find the period of one of two pendulums, the counting will be set to 1 and the computer wont run the "if" statement in the next step i. 
			// when both c1 and c2 are set to 1, which means that we found the periods of both pendulums, then we will leave the loop. 
			int c1 = 0, c2 = 0;
			if (theta1 == 0.0 && omega1 == 2.0 && c1 == 0)
			{
				printf(" the period of m1 in case mass ratio = 1 and length ration = %lf is %lf ", j / 10.0, dt * i);
				c1 = 1;
			}

			if (theta2 == 0.0 && omega2 == 3.0 && c2 == 0)
			{
				printf(" the period of m2 in case mass ratio = 1 and length ration = %lf is %lf ", j / 10.0, dt * i);
				c2 = 1;
			}
			if (c1 == 1 && c2 == 1) break;
		}

	}
	//mass ratio increases from 1 to 2
	//initial value
	theta1 = 0, theta2 = 0, omega1 = 2, omega2 = 3;
	m1 = 1, m2 = 1;
	L1 = 1, L2 = 1;
	for (int j = 10; j <= 20; j++)
	{
		// j is ( the mass ratio * 10 ) 
		m2 = m1 * (j / 10.0);
		int i;
		for (i = 1; i < 10; i++)
		{
			//find angular velocity of m1
			double K1_1 = h * fun1(dt, theta1, theta2, omega1, omega2, m1, m2, L1, L2);
			double K2_1 = h * fun1(dt + h / 2, theta1, theta2, omega1 + K1_1 / 2, omega2, m1, m2, L1, L2);
			double K3_1 = h * fun1(dt + h / 2, theta1, theta2, omega1 + K2_1 / 2, omega2, m1, m2, L1, L2);
			double K4_1 = h * fun1(dt + h, theta1, theta2, omega1 + K3_1, omega2, m1, m2, L1, L2);
			double omega_next_1 = omega1 + K1_1 / 6 + K2_1 / 3 + K3_1 / 3 + K4_1 / 6;
			//find angular velocity of m1
			double K1_2 = h * fun2(dt, theta1, theta2, omega1, omega2, m1, m2, L1, L2);
			double K2_2 = h * fun2(dt + h / 2, theta1, theta2, omega1 + K1_2 / 2, omega2, m1, m2, L1, L2);
			double K3_2 = h * fun2(dt + h / 2, theta1, theta2, omega1 + K2_2 / 2, omega2, m1, m2, L1, L2);
			double K4_2 = h * fun2(dt + h, theta1, theta2, omega1 + K3_2, omega2, m1, m2, L1, L2);
			double omega_next_2 = omega2 + K1_2 / 6 + K2_2 / 3 + K3_2 / 3 + K4_2 / 6;

			//change the initial value 
			omega1 = omega_next_1;
			theta1 = theta1 + omega1 * dt;
			omega2 = omega_next_2;
			theta2 = theta2 + omega2 * dt;
			//c1 and c2 are counting variable, if we find the period of one of two pendulums, the counting will be set to 1 and the computer wont run the "if" statement in the next step i. 
			// when both c1 and c2 are set to 1, which means that we found the periods of both pendulums, then we will leave the loop. 
			int c1 = 0, c2 = 0;
			if (theta1 == 0.0 && omega1 == 2.0 && c1 == 0)
			{
				printf(" the period of m1 in case mass ratio = 1 and length ration = %lf is %lf ", j / 10.0, dt * i);
				c1 = 1;
			}

			if (theta2 == 0.0 && omega2 == 3.0 && c2 == 0)
			{
				printf(" the period of m2 in case mass ratio = 1 and length ration = %lf is %lf ", j / 10.0, dt * i);
				c2 = 1;
			}
			if (c1 == 1 && c2 == 1) break;
		}

	}

}

double fun1(double t, double theta1, double theta2, double omega1, double omega2, double m1, double m2, double L1, double L2)
{
	double acc_1 = (-10.0 * (2 * m1 + m2) * sin(theta1) - m2 * 10 * sin(theta1 - 2 * theta2) - 2 * sin(theta1 - theta2) * m2 * (pow(omega2, 2) * L2 + pow(omega1, 2) * L1 * cos(theta1 - theta2))) / (L1 * (2 * m1 + m2 - m2 * cos(2 * theta1 - 2 * theta2)));
	return acc_1;
}

double fun2(double t, double theta1, double theta2, double omega1, double omega2, double m1, double m2, double L1, double L2)
{
	double acc_2 = 2 * sin(theta1 - theta2) * (pow(omega1, 2) * L1 * (m1 + m2) + 10 * (m1 + m2) * cos(theta1) + pow(omega2, 2) * L2 * m2 * cos(theta1 - theta2)) / (L2 * (2 * m1 + m2 - m2 * cos(2 * theta1 - 2 * theta2)));
	return acc_2;
}
