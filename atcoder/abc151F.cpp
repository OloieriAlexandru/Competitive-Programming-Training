#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#define ld long double
#define MAX_REPS 40000
using namespace std;

int n, wh;
ld x[1005], y[1005];
ld v1, v2;
ld d, e;
ld p = 0.1;

ld d2(ld a, ld b) {
	return a*a + b*b;
}

int main() {
	cin>>n;
	for (int i = 1; i <= n; i++){
		cin>>x[i]>>y[i];
		v1 += x[i];
        v2 += y[i];
	}
	v1 /= n;
	v2 /= n;
	for (int i = 1; i <= MAX_REPS; i++) {
		wh = 1;
		d = d2(v1 - x[wh], v2 - y[wh]);
		for (int j = 2; j <= n; j++) {
			e = d2(v1 - x[j], v2 - y[j]);
			if (d < e)
				d = e, wh = j;
		}
		v1 += (x[wh] - v1)*p;
		v2 += (y[wh] - v2)*p;
		p *= 0.999;
	}
	cout<<setprecision(15)<<fixed<<sqrt(d)<<'\n';
	return 0;
}
