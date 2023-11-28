#include <stdio.h>

struct No{
	int n;
	struct No *prox;
}*inicio= NULL;

int inserir(int x);
int imprimir();
int inverter();

int main(){
	int n, op=1, vetor[10]={1,2,3,4,5,6,7,8,9,10};
	
	while(op!=0){
		printf("\n0- Sair\n1- Inserir Vetor Inteiro\n2- Imprimirr\n3- Inverter\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				for(int count=0; count<10; count++)
					inserir(vetor[count]);
				
				break;
			
			case 2:
				imprimir();
				
				break;
				
			case 3:
				inverter();
				
				break;
				
			default: 
				printf("Invalido!");
		}
	}
	
	
	return 0;
}

int inserir(int x){
	struct No *novo = new struct No;
	struct No *aux = inicio;
	novo->n= x;
	
	if(inicio==NULL){
		inicio= novo;
		novo->prox= NULL;
	}
	else{
		for(; aux->prox != NULL; aux= aux->prox);
		
		aux->prox= novo;
		novo->prox= NULL;
	}
	
	return 0;
}

int imprimir(){
	struct No *aux= inicio;
	
	if(inicio==NULL)
		printf("Lista Vazia!\n");
	else{
		for(; aux->prox != NULL; aux= aux->prox)
			printf("%d| ", aux->n);
		
		printf("%d|\n", aux->n);
	}

	return 0;
}

int inverter(){
	struct No *aux= inicio, *nova= NULL;
	
	if(inicio==NULL)
		printf("Lista Vazia!\n");
	else{
		for(; inicio->prox != NULL;){
			inicio= inicio->prox;
			aux->prox= nova;
			
			nova= aux;
			aux=inicio;
		}
		
		inicio->prox= nova;
		
		nova= NULL; delete(nova); aux= NULL; delete(aux);
	}
	
	return 0;
}