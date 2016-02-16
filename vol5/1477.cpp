#include <cstdio>
int main()
{
	int N, H[50], sum, average;
	scanf("%d",&N);
	for(int i = 1; N != 0; i++){
		for(int k = 0; k < N; k++) scanf("%d",&H[k]);
		sum = 0;
		for(int k = 0; k < N; k++) sum += H[k];
		average = sum / N, sum = 0;
		for(int k = 0; k < N; k++) sum += (H[k] > average) ? (H[k]- average) : 0;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", i, sum);
		scanf("%d", &N);
	}
	putchar('\n');
	return 0;
}