#ifndef _ARITH_N_H
#define _ARITH_N_H
#include <array>
#include <initializer_list>

template<int N>
class arg
{
	std::array<double,N>	x;
public:

	arg() {}
	template <typename...T> arg(T...init) : x{init...} {}
	arg(const arg& y) {
		for(int i=0; i < N; ++i) x[i]=y[i];
	}
	arg& operator=(const arg& y) {
		for(int i=0; i < N; ++i) x[i]=y[i];
		return *this;
	}

	double& operator[](int n) { return x[n]; }
	double const& operator[](int n) const { return x[n]; }

	arg operator+(arg const& y) const {
		arg r;
		for(int i=0; i < N; ++i) r[i]=x[i]+y[i];
		return r;
	}
	arg operator-(arg const& y) const {
		arg r;
		for(int i=0; i < N; ++i) r[i]=x[i]-y[i];
		return r;
	}
	arg operator*(double k) const {
		arg r;
		for(int i=0; i < N; ++i) r[i]=x[i]*k;
		return r;
	}
	arg operator/(double k) const {
		arg r;
		for(int i=0; i < N; ++i) r[i]=x[i]/k;
		return r;
	}
	arg& operator+=(arg const& y) {
		for(int i=0; i < N; ++i) x[i]+=y[i];
		return *this;
	}
	arg& operator-=(arg const& y) {
		for(int i=0; i < N; ++i) x[i]-=y[i];
		return *this;
	}
	arg& operator*=(double k) {
		for(int i=0; i < N; ++i) x[i]*=k;
		return *this;
	}
	arg& operator/=(double k) {
		for(int i=0; i < N; ++i) x[i]/=k;
		return *this;
	}
	friend arg operator*(double k, arg const& y) { return y*k; }
};

#endif
