#ifndef RUNGE_KUTTA_H
#define RUNGE_KUTTA_H
#if 0
template<typename X, typename Y, typename F>
class RK
{
public:
	RK(const X& _x, const Y& _y, const F& _f) : x(_x), y(_y), f(_f) {}
	void inc(const X& h) {
		Y k1=h*f(x, y);
		Y k2=h*f(x+h/2, y+k1/2);
		Y k3=h*f(x+h/2, y+k2/2);
		Y k4=h*f(x+h, y+k3);
	
		x+=h;
		y+=(k1+2*k2+2*k3+k4)/6;
	}
	
	const X& arg() const { return x; }
	const Y& val() const { return y; }
	
private:
	X	x;
	Y	y;
	F	f;
};
#endif

namespace RK {

template<typename X, typename Y, typename U>
Y step(X x, Y y, U f, X h)
{
		Y k1=h*f(x, y);
		Y k2=h*f(x+h/2, y+k1/2);
		Y k3=h*f(x+h/2, y+k2/2);
		Y k4=h*f(x+h, y+k3);
	
		return (k1+2*k2+2*k3+k4)/6;
}

}//namespace

#endif

