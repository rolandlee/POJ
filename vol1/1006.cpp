#include <cstdio>
/*
Chinese Remining Theory:
Solving the modulation system
	X = a1 (mod m1)
	X = a2 (mod m2)
	X = a3 (mod m3)

	M  = m1 * m2 * m3
	M1 = m2 * m3
	M2 = m1 * m3
	M3 = m1 * m2

	t1 is that t1 * M1 = 1 (mod m1)

	X = a1 * t1 * M1 + a2 * t2 * M2 + a3 * t3 * M3 + K * M 

*/
const int fact1 = 5544;
const int fact2 = -6831;
const int fact3 = 1288;
const int M = 21252;

int main()
{
	int a1, a2, a3, D, idx = 1;
	int ret;

    scanf("%d %d %d %d", &a1, &a2, &a3, &D);
	while(a1 != -1){
		ret = (a1 * fact1 + a2 * fact2 + a3 * fact3 - D) % M;
		if (ret <= 0)
			ret = M + ret;
        printf("Case %d: the next triple peak occurs in %d days.\n", idx++, ret);
        scanf("%d %d %d %d", &a1, &a2, &a3, &D);
	}
	return 0;
}