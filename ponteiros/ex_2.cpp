#include <stdio.h>

int main(){
	
	float var[10], *p;
	int count=0;
	
	for(count; count<10; p++, count++){
		p= &var[count];
		
		scanf("%f", p);
	}
	
	printf("------------------\n");
	
	for(count, p--; count>0; p--, count--){
		printf("%.2f\n", *p);
		printf("%d\n", p);
	}
	
	return 0;
}
