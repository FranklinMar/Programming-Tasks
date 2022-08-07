#include <stdio.h>
#define S 20
int main(){
	double a[S] = {0.228952, 0.568418, 0.820277, 0.117099, 0.755212,
				   0.509299, 0.572073, 0.224526, 0.852861, 0.0612133,
				   0.175636, 0.568243, 0.0100543, 0.702012, 0.0345108,
				   0.146549, 0.189951, 0.144139, 0.261263, 0.474034};
	double average;
	for(int i=0;i<S;i++)
		average += *(a+i);
	printf("Sum:%lf\n",average);
	average = average / S;
	printf("Average number:%lf",average);
	return 0;
}