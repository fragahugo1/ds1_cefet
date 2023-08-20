#include <stdio.h>
#include <string.h>

float IMC(float a, float b);

struct sPessoa{
	char nome[20];
	float altura, peso, imc;
};

int main(){
	struct sPessoa pessoas[10];
	int count;
	float resultado=0, maior=0, menor=0;
	bool primeiro= true;
	
	for(count=0; count<10; count++){
		scanf("%s", &pessoas[count].nome);
		scanf("%f", &pessoas[count].altura);
		scanf("%f", &pessoas[count].peso);
		
		resultado= IMC(pessoas[count].peso, pessoas[count].altura);
		pessoas[count].imc= resultado;
		
		if(primeiro){
			maior= resultado;
			menor= resultado;
			primeiro= false;
		}
		else{
			if(resultado>maior)
				maior= resultado;
			else if(resultado<menor)
				menor= resultado;
		}
		
		printf("%s - IMC: %.2f\n", pessoas[count].nome, resultado);
		
		resultado=0;
	}
	
	printf("Maior IMC: %.2f\nMenor IMC: %.2f", maior, menor);
	
	return 0;
}

float IMC(float a, float b){
	return a/(b*b);
}
