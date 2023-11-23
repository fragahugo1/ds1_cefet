#include <stdio.h>
#include <stdlib.h>

#define MENU "\nEscolha------\n0-Encerrar; \n1-Inserir Inicio; \n2-Inserir Fim; \n3-Imprimir; \n4-Buscar; \n5-Alterar; \n6-Excluir um elemento; \n7-Excluir TODA lista; \nOpcao: "

struct No {
    int num;
    struct No *ant, *prox;
} *inicio = NULL, *fim = NULL;

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
	novo->num= numero;
	
	if(inicio==NULL){
		inicio= novo;
		fim= novo;
		
		novo->prox= inicio;
		novo->ant= fim;
	}
	else{
		inicio->ant= novo;
		novo->prox= inicio;
		
		inicio= novo;
		
		novo->ant= fim;
		fim->prox= novo;
	}
	
	return 0;
}

int inserirFim(int numero){
	struct No *novo = new struct No;
	novo->num= numero;
	
	if(inicio==NULL){
		inicio= novo;
		fim= novo;
		
		novo->prox= inicio;
		novo->ant= fim;
	}
	else{
		fim->prox= novo;
		inicio->ant= novo;
		
		novo->ant= fim;
		fim= novo;
		
		novo->prox= inicio;
	}
	
	return 0;
}

int imprimir(){
	struct No *aux= inicio;
	
	if(inicio == NULL)
		printf("Lista Vazia!");
	else{
		for(; aux->prox != inicio; aux= aux->prox)
			printf("%d| ", aux->num);
			
		printf("%d|", aux->num);
	}
	
	return 0;
}

struct No *buscar(int busca){
	struct No *aux= inicio, *aux2= fim;
	
	if(inicio == NULL)
		return NULL;
	else{
		if(aux==aux2){
			if(aux->num == busca)
				return aux;
			else
				return NULL;
		}
		else{
			if(aux->num == busca)
				return aux;
			else
				aux= aux->prox;
			
			
			if(aux2->num == busca)
				return aux2;
			else
				aux2= aux2->ant;
			
			for(; aux != aux2 && aux->ant != aux2 && aux2->prox != aux; aux= aux->prox, aux2= aux2->ant){ //para quando estiverem no mesmo ou se cruzarem. 
				if(aux->num == busca)
					return aux;
				else if(aux2->num == busca)
					return aux2;
			}
			
			if(aux->num == busca)
				return aux;
			else
				return NULL;
		}
	}
}

int alterar(struct No *end, int outro){
	end->num= outro;
	
	return 0;
}

int excluir_one(struct No *end){ //verificar se eh unico, esta no inicio ou esta no final.
	struct No *aux= inicio, *temp= end;
	
	if(inicio == fim){
		inicio= NULL;
		fim= NULL;
		
		delete(temp); aux= NULL; delete(aux);
	}
	else if(temp == inicio){
		inicio= inicio->prox;
		inicio->ant= fim;
		fim->prox= inicio;
		
		delete(temp); aux= NULL; delete(aux);
	}
	else if(temp == fim){
		fim= fim->ant;
		fim->prox= inicio;
		inicio->ant= fim;
		
		delete(temp); aux= NULL; delete(aux);
	}
	else{
		temp->prox->ant= temp->ant;
		temp->ant->prox= temp->prox;
	}
	
	return 0;
}

int excluir_all(){
	struct No *aux=inicio, *aux2= fim, *temp, *temp2;
	
	if(inicio==NULL)
		printf("Lista Vazia!");
	else{
		for(; aux != aux2 && aux->prox != aux2;){
			aux->prox->ant = aux2->ant;
			aux2->ant->prox = aux->prox;
			
			inicio= inicio->prox;
			fim= fim->ant;
			
			temp= aux;
			temp2= aux2;
			
			aux= aux->prox;
			aux2= aux2->ant;
			
			delete(temp); delete(temp2);
		}
		
		if(inicio == fim){
			inicio= NULL; fim= NULL;
			delete(aux); aux2= NULL; delete(aux2); temp= NULL; delete(temp); temp2= NULL; delete(temp2);
		}
		else{
			inicio= NULL; fim= NULL;
			delete(aux); delete(aux2); temp= NULL; delete(temp); temp2= NULL; delete(temp2);
		}
	}
	
	return 0;
}