#include <stdio.h>

struct No {
	int n;
	struct No *prox, *ant;
}*inicio= NULL, *fim= NULL;

struct No *buscar(int x); //lista duplamente circular

int main() {
	int n, x=0;

	while(x==0) {
		scanf("%d", &n);
		buscar(n);
		
		printf("Para continuar digite 0: ");
		scanf("%d", &x);
	}

	return 0;
}

struct No *buscar(int x) {
	struct No *aux= inicio, *aux2= fim;

	if(inicio==NULL) {
		printf("Lista Vazia!"); return NULL;
	}
	else{
		if(aux->n==x)
			return aux;
		else if(aux2->n==x)
			return aux2;
		
		for(aux= aux->prox, aux2= aux2->ant; aux != aux2 && aux->ant != aux2 && aux2->prox != aux; aux= aux->prox, aux2= aux2->ant){
			if(aux->n==x)
				return aux;
			else if(aux2->n==x)
				return aux2;
		}
		
		if(aux->n==x)
			return aux;
		else 
			return NULL;
	}	
}