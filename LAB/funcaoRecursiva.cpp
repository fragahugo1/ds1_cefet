#include <stdio.h>

int fatorial(int x);

int main(){
	int n, res=0;
	
	scanf("%d", &n);
	res= fatorial(n);
	printf("%d", res);
	
	return 0;
}

int fatorial(int x){
	if(x==1 || x==0)
		return 1;
	else
		return x * fatorial(x-1);	
}