#include <stdio.h>

struct No{
	int n;
	struct No *prox, *ant;
}*inicio= NULL, *fim= NULL;

int enfileirar(int x);
int desenfileirar();
int listar();

int main(){ //por ser first in-first out, a fila eh feita de uma lista duplamente encadeada. As estruturas entram no fim e saem no inicio.
	int res, n, op=1;
	
	while(op!=0){
		printf("\n0- Sair\n1- Emfileirar\n2- Desenfileirar\n3- Listar\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				scanf("%d", &n);
				res= enfileirar(n);
				printf("Entrou na fila: %d\n", res);
				
				break;
			
			case 2:
				res= desenfileirar();
				if(res==NULL)
					printf("Fila Vazia!\n");
				else
					printf("Saiu da fila: %d\n", res);
				
				break;
			
			case 3:
				listar();
				
				break;
			
			default:
				printf("Invalido!\n");
		}
	}
	
	return 0;
}

int enfileirar(int x){ //entra no FIM
	struct No *novo = new struct No;
	novo->n= x;
	
	if(inicio==NULL){
		inicio= novo; fim= novo;
		novo->prox= NULL; novo->ant= NULL;
	}
	else{
		novo->prox= NULL; novo->ant= fim;
		fim->prox= novo; 
		fim= novo;
	}
	
	return x;
}

int desenfileirar(){ //sai no INICIO
	struct No *aux= inicio;
	int x;
	
	if(inicio==NULL)
		return NULL;
	else if(inicio==fim){
		x= inicio->n;
		inicio= NULL; fim= NULL;
		delete(aux);
	}
	else{
		x= inicio->n;
		inicio->prox->ant= NULL;
		inicio= inicio->prox;
		delete(aux);
	}
	
	return x;
}

int listar(){
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