#include <stdio.h>

int fatorialSem(int a);
int fatorialCom(int a); //recursividade

int main(){
	int num;
	
	scanf("%d", &num);
	
	printf("%d\n", fatorialSem(num));
	printf("%d", fatorialCom(num));

	return 0;
}

int fatorialSem(int a){
	if(a == 0 || a == 1)
		return 1;
	else{
		int count=0, resultado=1;
		
		for(count= a; count> 1; count--)
			resultado*=count;
		
		return resultado;
	}
}

int fatorialCom(int a){
	if(a == 0 || a == 1)
		return 1;
	else
		return a * fatorialCom(a-1);
}
