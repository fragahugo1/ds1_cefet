#include <stdio.h>
#define MENU "\nEscolha------\n0-Encerrar; \n1-Inserir Inicio; \n2-Inserir Fim; \n3-Listar; \n4-Buscar; \n5-Alterar; \n6-Excluir um elemento; \n7-Excluir TODA lista; \nOpcao: "

struct No{
	int num;
	struct No *ant, *prox;
}*inicio=NULL, *fim=NULL;

int menu(){
	int op;
	printf (MENU);
	scanf("%d",&op);return op;
}

int inserirIni(int numero);
int inserirFim(int numero);
int listar();
struct No * buscar(int busca);
int alterar(struct No *end, int outro);
int excluir_one(struct No *end);
int excluir_all();

int main(){

	int num=0;
	int op;

	struct No *pos;
	op = menu();
		
	while (op != 0){
		switch (op){
			case 1:
				printf("Informe um numero:");
				scanf("%d*C",&num);
				inserirIni(num);
				
				break;
			
			case 2:
				printf("Informe um numero:");
				scanf("%d*C",&num);
				inserirFim(num);
			
				break;
		
			case 3:
				printf("\nlistar:\n");
				listar();
			
				break;
		
			case 4:
				printf("Informe um numero para buscar:");
				scanf("%d*C",&num);pos = buscar(num);
		
				if (pos==NULL)
					printf("NAO achei!\n");
				else
					printf("\nEND: %p\n\n", pos);
		
				break;
			
			case 5:
				printf("Informe um numero para alterar:");
				scanf("%d*C",&num);
				pos = buscar(num);
				
				if (pos==NULL)
					printf("NAO achei!");
				else{
					printf("Informe um novo numero:");
					scanf("%d*C",&num);alterar(pos, num);
				}
			
				break;
				
			case 6:
				printf("Informe um numero para excluir:");
				scanf("%d*C",&num);
				pos = buscar(num);
				
				if(pos==NULL)
					printf("NAO achei!");
				else
					excluir_one (pos);
				
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
	novo->ant= NULL;
	
	if(inicio==NULL){
		inicio= novo;
		fim= novo;
		novo->prox= NULL;
	}
	else{
		novo->prox= inicio;
		novo->prox->ant= novo;
		inicio= novo;
	}
	
	return 0;
}

int inserirFim(int numero){
	struct No *novo= new struct No;
	novo->num= numero;
	novo->prox= NULL;
	
	if(fim==NULL){
		inicio= novo;
		fim= novo;
		novo->ant= NULL;
	}
	else{
		novo->ant= fim;
		novo->ant->prox= novo;
		fim= novo;
	}
	
	return 0;
}

int listar(){
	struct No *aux;
	
	if(inicio==NULL){
		printf("Lista VAZIA!\n");
		return 0;
	}
	else{
		for(aux= inicio; aux != fim; aux=aux->prox)
			printf("%d| ", aux->num);
	}

	printf("%d", aux->num);
	
	return 0;
}

struct No * buscar(int busca){
	struct No *aux= inicio, *aux2= fim;
	
	if (inicio == NULL){
		printf("Lista vazia");
		return NULL;
	}
	
		for(aux=inicio, aux2=fim; aux != aux2 && aux->ant != aux2 && aux2->prox != aux; aux=aux->prox, aux2=aux2->ant){
			if(aux->num == busca)
				return aux;
			else if(aux2->num == busca)
				return aux2;
		}
		if (aux->num == busca){
			return aux;	
		}
		else{
			printf ("Nao esta na lista");
			return NULL;
		}	
}

int alterar(struct No *end, int outro){
	end->num= outro;
	
	return 0;
}

int excluir_one(struct No *end){
	struct No *del = end;
	
	if(inicio==fim){
		inicio= NULL;
		fim= NULL;
		delete(del);
	}
	else if(del==inicio){
		inicio=del->prox;
		inicio->ant= NULL;
		delete(del);
	}
	else if(del==fim){
		fim=del->ant;
		fim->prox= NULL;
		delete(del);
	}
	else{
		del->prox->ant= del->ant;
		del->ant->prox= del->prox;
		delete(del);
	}
	
	return 0;
}

int excluir_all(){
	struct No *aux= inicio, *aux2= fim, *temp;
	
	if(inicio==NULL && fim==NULL){
			printf("Lista VAZIA!");
			return 1;
	}
		
	else	
	for(; inicio!=fim && aux->prox != fim && aux2->ant != inicio; aux= aux->prox, aux2= aux2->ant){
		inicio= aux->prox;
		inicio->ant= NULL;
		temp= aux;
		delete(temp);
		
		fim= aux2->ant;
		fim->prox= NULL;
		temp= aux2;
		delete(temp);
	}
	if (aux != NULL){
		temp = aux;
		inicio = NULL;
		fim = NULL;
		delete (temp);
	}
	
	delete(aux);
	delete(aux2);
	
	return 0;
}
