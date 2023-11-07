#include <stdio.h>
#define MENU "\n0-Encerrar\n1-Inserir Inicio\n2-Inserir Fim\n3-Listar\n4-Buscar\n5-Alterar\nOpcao:"

struct No{
	int num;
	struct No *prox;
}*inicio=NULL;

int menu();

int inserirIni(int numero);
	
int inserirFim(int numero);

int listar();

struct No * buscar(int busca);

int alterar(struct No *end, int outro);

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
				printf("\nlistar:\n");
				listar();
				printf("\nInforme um numero para buscar: ");
				scanf("%d*C",&num);
				pos = buscar(num);
				
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
					scanf("%d*C",&num);
					alterar(pos, num);
				}
				
				break;
		}
		op = menu();
	}
	
	return 0;
}

int menu(){
	int op;
	printf (MENU);
	scanf("%d",&op);
	return op;
}

int inserirIni(int numero){
	struct No *novo; //= malloc(sizeof(No));
	novo= new struct No;
	novo->prox= inicio;
	novo->num= numero;
	inicio= novo;
}

int inserirFim(int numero){
	struct No *novo;
	novo= new struct No;
	struct No *aux;
	
	if(inicio==NULL){
		inicio= novo;
		novo->num= numero;
		novo->prox= NULL;
	}
	else{
		aux= inicio;
		novo->num= numero;
		
		while(aux->prox)
			aux= aux->prox;
		
		aux->prox= novo;
		novo->prox= NULL;
	}
}

int listar(){
	struct No *aux= inicio;
	
	if(aux==NULL)
		printf("Lista Vazia!\n");
	
	while(aux!=NULL){
		printf("%d| ", aux->num);
		aux= aux->prox;
	}
}

struct No * buscar(int busca){
	struct No *aux;
	aux= inicio;
	
	while(aux){
		if(busca==aux->num)
			return aux;
		
		aux= aux->prox;
	}
}

int alterar(struct No *end, int outro){
	struct No *aux;
	
	aux= end;
	aux->num= outro;
}
