#include <stdio.h>

struct No{
	int n;
	struct No *prox;
}*inicio= NULL;

int empilhar(int x);
int desempilhar();
int listar();

int main(){ //por ser first in-last out, a pilha eh feita de uma lista simplesmente encadeada. 
	int res, n, op=1;
	
	while(op!=0){
		printf("\n0- Sair\n1- Empilhar\n2- Desempilhar\n3- Listar\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				scanf("%d", &n);
				res= empilhar(n); 
				printf("Empilhou: %d\n", res);
				
				break;
			
			case 2:
				res= desempilhar();
				if(res==NULL)
					printf("Pilha Vazia!\n");
				else
					printf("Desempilhou: %d", res);
				
				break;
				
			case 3: 
				listar();
				
				break;
				
			default:
				printf("Invalido!");
		}
	}
	
	return 0;
}

int empilhar(int x){
	struct No *novo = new struct No;
	novo->n= x;
	
	if(inicio==NULL){
		inicio= novo;
		novo->prox= NULL;
	}
	else{
		novo->prox= inicio;
		inicio=novo;
	}
	
	return x;
}

int desempilhar(){
	struct No *aux= inicio;
	int x;
	
	if(inicio==NULL)
		return NULL;
	else if(inicio->prox==NULL){
		x= inicio->n;
		inicio= NULL;
		delete(aux);
	}
	else{
		x= inicio->n;
		inicio= aux->prox;
		delete(aux);
	}

	return x;
}

int listar(){
	struct No *aux= inicio;
	
	if(inicio==NULL)
		printf("Pilha Vazia!\n");
	else{
		for(; aux->prox != NULL; aux= aux->prox)
			printf("%d| ", aux->n);
			
		printf("%d| \n", aux->n);
	}
	
	return 0;
}