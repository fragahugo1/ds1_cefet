#include <stdio.h>
#include <string.h>

int main(){
	char matriz[3][3], *p;
	int count;
	
	for(count=0, p= &matriz[0][0]; count<2; count++, p++){	
		scanf("%s", p);	
	}
	
	for(count=0, p= &matriz[0][0]; count<2; count++, p++){
		printf("%c |", *p);
	}
	
	return 0;
}
