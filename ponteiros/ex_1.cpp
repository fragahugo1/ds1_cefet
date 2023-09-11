#include <stdio.h>

int main(){
	
	int var, *p;
	
	p= &var;
	
	scanf("%d", p);
		
	printf("%d\n", *p);
	printf("%d", p);
	
	return 0;
}
