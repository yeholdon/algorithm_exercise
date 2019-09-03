#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
struct Fraction
{
	LL up;
	LL down;
};

LL gcd(LL a, LL b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

Fraction reduction(Fraction a) {
	if (a.down < 0) {
		a.up = -a.up;
		a.down = -a.down;

	}
	if (a.up == 0) {
		a.down = 1;
	}
	else {
		LL d = abs(gcd(a.up, a.down));
		a.up /= d;
		a.down /= d;
	}
	return a;
}

Fraction add(Fraction& a, Fraction& b) {
	Fraction res;
	res.up = a.up * b.down + a.down * b.up;
	res.down = a.down * b.down;
	return reduction(res);
}

Fraction sub(Fraction& a, Fraction& b) {
	Fraction res;
	res.up = a.up * b.down - a.down * b.up;
	res.down = a.down * b.down;
	return reduction(res);
}

Fraction multi(Fraction& a, Fraction& b) {
	Fraction res;
	res.up = a.up * b.up;
	res.down = a.down * b.down;
	return reduction(res);
}

Fraction div(Fraction& a, Fraction& b) {
	Fraction res;
	if (b.up == 0) {
		res.down = 0;
		res.up = 1;
		return res;
	}
	res.up = a.up * b.down;
	res.down = a.down * b.up;
	return reduction(res);
}

void transPrint(Fraction& a) {
	if (a.down == 0) {
		printf("Inf");
		return;
	}

	if (a.down == 1) {
		printf("%lld", a.up);
	}
	else if (abs(a.up) > a.down)
	{
		printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % a.down, a.down);
	}
	else {
		printf("%lld/%lld", a.up, a.down);
	}


}

int main() {
	int n;
	scanf("%d", &n);
	Fraction a, ans;
	ans.up = 0;
	ans.down = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &a.up, &a.down);
		a = reduction(a);
		ans = add(ans, a);
	}
	transPrint(ans);
	return 0;

}