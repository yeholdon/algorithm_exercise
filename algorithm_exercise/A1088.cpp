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

	if (a.up < 0) {
		printf("(");
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

	if (a.up < 0) {
		printf(")");
	}
	
}
int main() {
	Fraction a, b;
	char op[4] = { '+','-', '*', '/' };
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	a = reduction(a);
	b = reduction(b);
	Fraction res;
	for (int i = 0; i < 4; i++)
	{
		switch (i) {
		case 0:
			res = add(a, b); break;
		case 1:
			res = sub(a, b); break;
		case 2:
			res = multi(a, b); break;
		case 3:
			res = div(a, b); break;
		default:
			break;
		}
		transPrint(a);
		printf(" %c ", op[i]);
		transPrint(b);
		printf(" = ");
		transPrint(res);
		printf("\n");
	}
	
	return 0;
}