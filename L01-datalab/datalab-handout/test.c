#include <stdio.h>
// #include "bits.h"


// int isTmax(int x) {
  // return (!((x+x+1) ^ (~0))) & !!(x^~0);
// }

int isTmax(int x) {
  int a = x & (x>>8) & (x>>16) & (x>>23) & 255;
  printf("%d\n", a);
  return !(a ^ 255);
}


void crazy() {
	int x = 2147483647;
	int y =  ((x+x+1)^(~0));
	int z = !((x+x+1)^(~0));
	
	printf("%d %d %d\n", y, !y, z);	
}

int main() {
	int x; scanf("%d", &x);

	// invert if needed (7 operations). 
	// Makes x positive
	{
		int ifxneg = (x >> 31);
		int ifxpos = ~ifxneg;
		x = (ifxpos&x) | (ifxneg&(~x));
	}

	// Task: find least significat 0 not superceded by 1
	// Its position (0-based)+1 will be the answer.
	// using binary to achieve this goal.
	int l = 0, r = 32, s = 32, m;
	// binary search step
	{
		s >>= 1;
		m = l + s;
		int isbust = !(x >> m);
		int ifnobust = isbust + ~0;
		int ifisbust = ~ifnobust;
		l = (ifisbust&l) | (ifnobust&m);
		r = (ifisbust&m) | (ifnobust&r);
		printf("x, x>>m, ib, iib, inb | %d %d %d %d %d\n", x, x>>m, isbust, ifisbust, ifnobust);
		printf("l, r, s, m | %d %d %d %d\n", l, r, s, m);
	}
	// binary search step
	{
		s >>= 1;
		m = l + s;
		int isbust = !(x >> m);
		int ifnobust = isbust + ~0;
		int ifisbust = ~ifnobust;
		l = (ifisbust&l) | (ifnobust&m);
		r = (ifisbust&m) | (ifnobust&r);
		printf("x, x>>m, ib, iib, inb | %d %d %d %d %d\n", x, x>>m, isbust, ifisbust, ifnobust);
		printf("l, r, s, m | %d %d %d %d\n", l, r, s, m);
	}
	// binary search step
	{
		s >>= 1;
		m = l + s;
		int isbust = !(x >> m);
		int ifnobust = isbust + ~0;
		int ifisbust = ~ifnobust;
		l = (ifisbust&l) | (ifnobust&m);
		r = (ifisbust&m) | (ifnobust&r);
		printf("x, x>>m, ib, iib, inb | %d %d %d %d %d\n", x, x>>m, isbust, ifisbust, ifnobust);
		printf("l, r, s, m | %d %d %d %d\n", l, r, s, m);
	}
	// binary search step
	{
		s >>= 1;
		m = l + s;
		int isbust = !(x >> m);
		int ifnobust = isbust + ~0;
		int ifisbust = ~ifnobust;
		l = (ifisbust&l) | (ifnobust&m);
		r = (ifisbust&m) | (ifnobust&r);
		printf("x, x>>m, ib, iib, inb | %d %d %d %d %d\n", x, x>>m, isbust, ifisbust, ifnobust);
		printf("l, r, s, m | %d %d %d %d\n", l, r, s, m);
	}
	// binary search step
	{
		s >>= 1;
		m = l + s;
		int isbust = !(x >> m);
		int ifnobust = isbust + ~0;
		int ifisbust = ~ifnobust;
		l = (ifisbust&l) | (ifnobust&m);
		r = (ifisbust&m) | (ifnobust&r);
		printf("x, x>>m, ib, iib, inb | %d %d %d %d %d\n", x, x>>m, isbust, ifisbust, ifnobust);
		printf("l, r, s, m | %d %d %d %d\n", l, r, s, m);
	}
	// binary search step
	{
		s >>= 1;
		m = l + s;
		int isbust = !(x >> m);
		int ifnobust = isbust + ~0;
		int ifisbust = ~ifnobust;
		l = (ifisbust&l) | (ifnobust&m);
		r = (ifisbust&m) | (ifnobust&r);
		printf("x, x>>m, ib, iib, inb | %d %d %d %d %d\n", x, x>>m, isbust, ifisbust, ifnobust);
		printf("l, r, s, m | %d %d %d %d\n", l, r, s, m);
	}
	int res = r+1;
	printf("res: %d\n", res);
}
