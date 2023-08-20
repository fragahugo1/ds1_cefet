#include <stdio.h>
#include <math.h>

int expo(int a, int b);
float expo(float a, int b);

int main(){
	int d1, d2, f2;
	float f1;
	
	scanf("%d\n%d\n%f\n%d", &d1, &d2, &f1, &f2);
	
	printf("%d\n", expo(d1, d2));
	printf("%.2f", expo(f1, f2));
	
	return 0;
}

int expo(int a, int b){
	return pow(a, b);
}

float expo(float a, int b){
	return pow(a, b);
}
