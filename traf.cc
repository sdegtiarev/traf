#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include <math.h>
#include "runge_kutta.h"
#include "arithn.h"

enum class mode { ALL, X, V, A, Y, Z };

mode mod=mode::ALL;
double y0=10, v0=0, alpha=0, omega=.1;
arg<2> y{y0,-.1};
double tau=0;
double t=0, T=200;
constexpr double dt=.01;

void echo(mode m, double tau, double t, arg<2> y)
{
	double a=y[1]*y[1]/2/(y[0]+tau*y[1]);
	switch(m) {
		case mode::ALL: printf("%-6.3lf %-8.4lf %-8.4lf %-8.4lf\n", t, y[0], (y[1]+v0), a); break;
		case mode::Z:   printf("%-6.3lf %-8.4lf\n", t, v0*t); break;
		case mode::Y:   printf("%-6.3lf %-8.4lf\n", t, y[0]); break;
		case mode::X:   printf("%-6.3lf %-8.4lf\n", t, y[0]+v0*t); break;
		case mode::V:   printf("%-6.3lf %-8.4lf\n", t, y[1]+v0); break;
		case mode::A:   printf("%-6.3lf %-8.4lf\n", t, a*1000); break;
	}
}



int main(int argc, char**argv)
{
	
	int opt;
	while((opt=getopt(argc,argv,"x:v:u:t:a:w:T:XYZVAh")) != -1)
	switch(opt) {
		case 'x': y[0]=y0=atof(optarg); break;
		case 'v': y[1]=-atof(optarg); break;
		case 'u': v0=-atof(optarg); break;
		case 't': tau=atof(optarg); break;
		case 'T': T=atof(optarg); break;
		//case 'a': alpha=atof(optarg); break;
		//case 'w': omega=atof(optarg); break;
		case 'X': mod=mode::X; break;
		case 'Y': mod=mode::Y; break;
		case 'Z': mod=mode::Z; break;
		case 'V': mod=mode::V; break;
		case 'A': mod=mode::A; break;
		case 'h':
		default : return 1;
	}
	
	echo(mod, tau, t, y);
	//while(t < T && y[0] > 0 && y[0] < y0*10) {
	while(t < T && y[0] < y0*50) {
		arg<2> h=RK::step(t, y,
			[=](double, arg<2> _y) {
				arg<2> r;
				r[0]=_y[1];
				r[1]=(_y[1]+v0)*(_y[1]+v0)/2/(_y[0]+tau*(_y[1]+v0));
				//if(r[1] > 1) r[1]=1;
				//else if(r[1] < -1) r[1]=-1;
				return r;
			}, dt);
		
		t+=dt;
		y+=h;
		//y[0]+=alpha*sin(t*omega);
		echo(mod, tau, t, y);
	}	
	
	return 0;
}


