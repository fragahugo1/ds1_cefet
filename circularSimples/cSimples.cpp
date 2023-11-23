#include <stdio.h>
#include <stdlib.h>

#define MENU "\nEscolha------\n0-Encerrar; \n1-Inserir Inicio; \n2-Inserir Fim; \n3-Imprimir; \n4-Buscar; \n5-Alterar; \n6-Excluir um elemento; \n7-Excluir TODA lista; \nOpcao: "

struct No {
    int num;
    struct No *prox;
} *inicio = NULL;

int menu() {
    int op;
    printf(MENU);
    scanf("%d", &op);
    return op;
}

int inserirIni(int numero);
int inserirFim(int numero);
int imprimir();
struct No *buscar(int busca);
int alterar(struct No *end, int outro);
int excluir_one(struct No *end);
int excluir_all();

int main() {
    int num = 0;
    int op;
    struct No *pos;

    op = menu();
    while (op != 0) {
        switch (op) {
            case 1:
                printf("Informe um numero: ");
                scanf("%d", &num);
                inserirIni(num);
                break;
            case 2:
                printf("Informe um numero: ");
                scanf("%d", &num);
                inserirFim(num);
                break;
            case 3:
                printf("\nImprimir:\n");
                imprimir();
                break;
            case 4:
                printf("\nBuscar:\n");
                printf("Informe um numero para buscar: ");
                scanf("%d", &num);
                pos = buscar(num);
                if (pos == NULL)
                    printf("NAO achei!\n");
                else
                    printf("\nEND: %p\n\n", pos);
                break;
            case 5:
                printf("Informe um numero para alterar: ");
                scanf("%d", &num);
                pos = buscar(num);
                if (pos == NULL)
                    printf("NAO achei!");
                else {
                    printf("Informe um novo numero: ");
                    scanf("%d", &num);
                    alterar(pos, num);
                }
                break;
            case 6:
                printf("Informe um numero para excluir: ");
                scanf("%d", &num);
                pos = buscar(num);
                if (pos == NULL)
                    printf("NAO achei!");
                else
                    excluir_one(pos);
                break;
            case 7:
                excluir_all();
                break;
            default:
                printf("Opcao invalida.... Tente novamente!\n");
        }
        op = menu();
    }

    return 0;
}

int inserirIni(int numero){
	struct No *novo = new struct No;
	struct No *aux = inicio;
	novo->num= numero;
	
	if(inicio==NULL){
		inicio= novo;
		novo->prox= inicio;
	}
	else{
		for(; aux->prox != inicio; aux= aux->prox);
		
		aux->prox= novo;
		novo->prox= inicio;
		inicio=novo;
	}
	
	return 0;
}

int inserirFim(int numero){
	struct No *novo= new struct No;
	struct No *aux= inicio;
	novo->num= numero;

	if(inicio==NULL){
		inicio= novo;
		novo->prox= inicio;
	}	
	else{
		for(; aux->prox != inicio; aux= aux->prox);
		
		aux->prox= novo;
		novo->prox= inicio;
	}
	
	return 0;
}

int imprimir(){
	struct No *aux= inicio;
	
	if(inicio == NULL) //condicao de erro
		printf("Lista Vazia!");
	else{
		for(; aux->prox != inicio; aux= aux->prox)
			printf("%d| ", aux->num);
		
		printf("%d|", aux->num);
	}
	
	return 0;
}

struct No *buscar(int busca){ 
	struct No *aux= inicio;
	
	if(inicio == NULL) //condicao de erro
		return NULL;
	else{
		for(; aux->prox != inicio; aux= aux->prox){
			if(aux->num == busca)
				return aux;
		}
		
		if(aux->num == busca)
			return aux;
		else
			return NULL;
	}
}

int alterar(struct No *end, int outro){
	end->num= outro;
	
	return 0;
}

int excluir_one(struct No *end){ //1 elemento, 2 elementos e resto.
	struct No *aux= inicio, *temp= end; 
	
	if(temp == inicio && temp->prox == inicio){
		inicio= NULL;
		delete(temp);
	}
	else if(temp == inicio){
		for(; aux->prox != inicio; aux= aux->prox);
		
		inicio= temp->prox;
		aux->prox= inicio;
		
		delete(temp);
	}
	else{
		for(; aux->prox != temp; aux= aux->prox);
		
		aux->prox= temp->prox;
		delete(temp);
	}

	return 0;
}

int excluir_all(){ //1 elemento, 2 elementos e resto.
	struct No *aux= inicio, *temp= inicio->prox;
	
	if(inicio == NULL)
		printf("Lista Vazia!");
	else{
		if(aux->prox == inicio){
			inicio= NULL; delete(temp); aux= NULL; delete(aux);
		}
		else if(temp->prox == inicio){
			inicio->prox= inicio;
			delete(temp);
			
			inicio= NULL;
			delete(aux);
		}
		else{ 
			for(aux= aux->prox; aux->prox != inicio;){ //na circular 3+ elementos, o ponteiro aux tem que iniciar um elemento depois do inicio.
				inicio->prox= aux->prox;
				
				temp= aux;
				aux= aux->prox;
				
				delete(temp);
			}
			
			inicio->prox= inicio;
			
			temp= aux;
			aux= aux->prox;
			delete(temp);
			
			inicio= NULL;
			delete(aux);
		}
	}
	
	return 0;
}