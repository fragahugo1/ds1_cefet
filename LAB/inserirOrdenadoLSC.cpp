#include <stdio.h>

struct No{
	int n;
	struct No *prox;
}*inicio= NULL;

int inserirOrdenado(int n); //lista simplesmente circular
int listar();

int main(){
	int n, op=1;
	
	while(op!=0){
		printf("\n0- Sair\n1- Inserir Ordenado\n2- Listar\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				scanf("%d", &n);
				inserirOrdenado(n);
				
				break;
			
			case 2:
				listar();
				
				break;
			
			default:
				printf("Invalido!");
		}
	}
	
	return 0;
}

int inserirOrdenado(int y){
	struct No *novo= new struct No;
	struct No *aux= inicio;
	novo->n= y;
	
	if(inicio==NULL){
		inicio= novo;
		novo->prox= inicio;
	}
	else if(novo->n < inicio->n){ //se é menor que o primeiro
		novo->prox= inicio;
	
		for(; aux->prox != inicio; aux= aux->prox);
		
		inicio= novo;
		aux->prox= inicio;
	}
	else{ //se é maior que os seguintes
		for(; aux->prox != inicio && novo->n > aux->prox->n; aux= aux->prox);
		
		if(aux->prox == inicio){
			aux->prox= novo;
			novo->prox= inicio;
		}
		else{
			novo->prox= aux->prox;
			aux->prox= novo;
		}
	}
		
	return 0;
}

int listar(){
	struct No *aux= inicio;
	
	if(inicio==NULL)
		printf("Lista Vazia!\n");
	else{
		for(; aux->prox != inicio; aux= aux->prox)	
			printf("%d| ", aux->n);
		
		printf("%d|\n", aux->n);
	}
	
	return 0;
}