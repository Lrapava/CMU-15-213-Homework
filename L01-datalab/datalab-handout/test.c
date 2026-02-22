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

	int x_isnt_minus_one = (!(~x)+ ~0);
	int x_is_minus_one = ~x_isnt_minus_one;

	printf("is-1 %d | isnt-1 %d\n", x_is_minus_one, x_isnt_minus_one);
/*
	int ifposx = ~(x >> 31);
	int ifnegx = ~ifposx;
	printf("ipx: %d | inx: %d\n", ifposx, ifnegx);
	
	x = (ifnegx&(~x <<)) | (ifposx&x);
	printf("new_x: %d\n", x);
*/

	// let's try to do a binary search
	int l = 0, r = 32, m, shift;
	int bust_state = x >> 31;
	int isbust, ifbust, elnbust;
	
	// find m
	shift = 16;
	m = l + shift;
	// check if is bust
	isbust = !((x >> m) ^ bust_state);
	// matrix
	ifbust = (!isbust + ~0);
	elnbust = ~ifbust;

	printf("l: %d | r: %d | m: %d\n", l, r, m);
	printf("isbust: %d | ifbust: %d | elnbust: %d \n", isbust, ifbust, elnbust);
	
	l = (ifbust&l) | (elnbust&m);
	r = (ifbust&m) | (elnbust&r);

	// find m
	shift = 8;
	m = l + shift;
	// check if is bust
	isbust = !((x >> m) ^ bust_state);
	// matrix
	ifbust = (!isbust + ~0);
	elnbust = ~ifbust;

	printf("l: %d | r: %d | m: %d\n", l, r, m);
	printf("isbust: %d | ifbust: %d | elnbust: %d \n", isbust, ifbust, elnbust);
	
	l = (ifbust&l) | (elnbust&m);
	r = (ifbust&m) | (elnbust&r);

	// find m
	shift = 4;
	m = l + shift;
	// check if is bust
	isbust = !((x >> m) ^ bust_state);
	// matrix
	ifbust = (!isbust + ~0);
	elnbust = ~ifbust;

	printf("l: %d | r: %d | m: %d\n", l, r, m);
	printf("isbust: %d | ifbust: %d | elnbust: %d \n", isbust, ifbust, elnbust);
	
	l = (ifbust&l) | (elnbust&m);
	r = (ifbust&m) | (elnbust&r);

	// find m
	shift = 2;
	m = l + shift;
	// check if is bust
	isbust = !((x >> m) ^ bust_state);
	// matrix
	ifbust = (!isbust + ~0);
	elnbust = ~ifbust;

	printf("l: %d | r: %d | m: %d\n", l, r, m);
	printf("isbust: %d | ifbust: %d | elnbust: %d \n", isbust, ifbust, elnbust);
	
	l = (ifbust&l) | (elnbust&m);
	r = (ifbust&m) | (elnbust&r);

	// find m
	shift = 1;
	m = l + shift;
	// check if is bust
	isbust = !((x >> m) ^ bust_state);
	// matrix
	ifbust = (!isbust + ~0);
	elnbust = ~ifbust;

	printf("l: %d | r: %d | m: %d\n", l, r, m);
	printf("isbust: %d | ifbust: %d | elnbust: %d \n", isbust, ifbust, elnbust);
	
	l = (ifbust&l) | (elnbust&m);
	r = (ifbust&m) | (elnbust&r);
	
	printf("l: %d | r: %d | m: %d\n", l, r, m);
	
	// int res = (ifposx&r) | (ifnegx&(r+1));
	// res = (x_isnt_minus_one & res) | (x_is_minus_one & 1);
	// printf("res: %d\n", res);
}
