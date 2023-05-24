#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

//DECLARAÇÃO STRUCT
typedef struct {
        char titulo[200] ;
		char nomeAutor[200] ;
        int preco ;  
        int numPaginas ;
        char generoLivro[200];
        int idadeLivro;
        
} Dados;

//DECLARAÇÃO DAS FUNÇÕES 
 int main(); 	
void insere(void);
void exibe(void);
void aluga(void);
void exit(void);
void menu(void);
void saudacao (void);

Dados livro[10];
char escolha;
int i = 0, quantidade = 0;


//FUNÇÃO PRINCIPAL
int main(){
 saudacao();
 menu();

 
 system("pause");

}
//FUNÇÃO DO MENU

void menu(void){
		
	printf("|-----------PAGINA PRINCIPAL-----------|\n");
	printf("|--------------------------------------|\n");
	printf("Digite o numero do atendimento desejado\n\n");
    printf("|1 -> Cadastrar Livros                 |\n");
    printf("|2 -> Exibir Dados                     |\n");
    printf("|3 -> Alugar Livros                    |\n");
    printf("|4 -> Sair                             |\n");
    printf("|--------------------------------------|\n");
    
    	
		scanf("%c",&escolha);
		system ("cls");
	switch(escolha) {
                        case '1':
                                insere();
                                break;

                        case '2':
                                exibe();
                                break;
 						case '3':
                                aluga();
                                break;
                        case '4':
                                exit();
                                break;

                        default:
                                printf("Digite uma opcao valida!\n");
                                system ("cls");
                                menu();
                                break;
                }
	
}

void saudacao(void){
//	int tempo=clock();

    char email[50] = "raamab";
    char email1[50];
    char senha[15] = "1234";
    char senha1[15];        
	printf("|-----------------BEM VINDO(A) A LIBOFLY--------------|\n");
	printf("|-----------------------------------------------------|\n");
	printf("|-----------------------------------------------------|\n");
	printf("| Aqui voce pode cadastrar livros e/ou alugar         |\n");
	printf("| Valor Maximo de preco: R$10.00                      |\n");
	printf("|-----------------------------------------------------|\n");
	printf("|-----------------------------------------------------|\n");
	printf("| Digite o Email: ");
    scanf("%s", email1);
    printf("|-----------------------------------------------------|\n");
	printf("| Digite a Senha: ");
    scanf("%s", senha1);
	printf("|-----------------------------------------------------|\n");

 
    if (strcmp(email, email1) == 0 && strcmp(senha, senha1) == 0){
    	printf("logado");
    	system("cls");
    	getchar(); // aguarda a entrada de um caractere do usuário antes de continuar.
    	menu(); 	
}else{
	printf("erro");
	system("cls");
	saudacao();
}
	
}
	
//FUNÇÃO CADASTRAMENTO DE LIVROS

void insere (void){


	printf("|---------------CADASTRO DE LIVROS------------------|\n");
	printf("|---------------------------------------------------|\n");
	printf("|Quantidade maxima: 10 livros                       |\n");
	printf("|Digite o numero de livros que voce deseja registrar|\n");
	printf("|---------------------------------------------------|\n");
	printf("|---------------------------------------------------|\n");
	printf("|Quantidade:                                        |\n");
	scanf("%i", &quantidade);
    system("cls");
	livro[quantidade];

	for(i; i < quantidade; i++){
			
		printf("-------------CADASTRO-------------------------\n\n");
		int posicao = i + 1;
		printf("|->Digite o titulo do %i livro:                 \n ", posicao);
		setbuf(stdin, 0);
		fgets(livro[i].titulo, 200, stdin);
		printf(" |---------------------------------------------------\n");
		printf("|->Digite o nome do autor:                            \n ");
		setbuf(stdin, 0);
		fgets(livro[i].nomeAutor, 200, stdin);
		printf(" |--------------------------------------------------\n ");
		printf("|->Digite o preco do livro:                         \n ");
		scanf("%i", &livro[i].preco);
	    printf(" |---------------------------------------------------\n ");
		printf("|->Digite o numero de paginas:                      \n " );
		scanf("%i", &livro[i].numPaginas);
		printf(" |---------------------------------------------------\n ");
		printf("|->Digite o genero do livro:                      \n " );
		setbuf(stdin, 0);
		fgets(livro[i].generoLivro, 200, stdin);
		printf(" |---------------------------------------------------\n ");
		printf("|->Digite a faixa etaria do livro:                      \n " );
		scanf("%i", &livro[i].idadeLivro);
		printf("\n\n");
		printf("Livro Registrado!");
			int tempo = clock();
			tempo = clock();

while(clock() - tempo < 3000){ 
	}
	system ("cls");
}
menu();
}

//FUNÇÃO DE EXIBIR OS LIVROS CADASTRADOS

void exibe(void){
	int tempo = clock();
	int menorPreco = livro[0].preco;
	int menorNumPaginas = livro[0].numPaginas;

	for(int index = 0; index < quantidade; index++){
		if(livro[index].preco < menorPreco){
			menorPreco = livro[index].preco;
		}
		if(livro[index].numPaginas < menorNumPaginas){
			menorNumPaginas = livro[index].numPaginas;
		}
	}

        for(int index = 0; index < quantidade; index++){
		if(menorPreco == livro[index].preco){
			printf("|---------------------------------------------------\n");
			printf("Livro com o menor preco: \n\n");
			printf("Titulo: %s", livro[index].titulo);
			printf("Nome do autor: %s\n", livro[index].nomeAutor);
			printf("Preco: %i\n", livro[index].preco);
			printf("Numero de paginas: %i\n\n", livro[index].numPaginas);
			printf("Genero do Livro:%s ", livro[index].generoLivro);
			printf("Faixa Etaria do Livro:%i\n", livro[index].idadeLivro);
			printf("|---------------------------------------------------\n");
		}
		if(menorNumPaginas == livro[index].numPaginas){
			printf("|---------------------------------------------------\n");
			printf("Livro com o menor numero de paginas: \n\n");
			printf("Titulo: %s", livro[index].titulo);
			printf("Nome do autor: %s\n", livro[index].nomeAutor);
			printf("Preco: %i \n", livro[index].preco);
			printf("Numero de paginas: %i\n\n", menorNumPaginas);
			printf("Genero do Livro:%s ", livro[index].generoLivro);
			printf("Faixa Etaria do Livro:%i\n", livro[index].idadeLivro);
			printf("|---------------------------------------------------\n");
			printf("|---------------------------------------------------\n");
		}

	}
		
	tempo = clock();
	while(clock() - tempo < 6000){ 
	}
	menu();
}

//FUNÇÃO DE ALUGUEL DE LIVROS

void aluga(){
int tempo = clock();
char genero [100];
printf("|-------------ALUGUEL DE LIVROS-----------------------|\n");
	printf("|----------------------------------------------------|\n");		
	printf("\nInforme o genero do livro: ");
	setbuf(stdin, 0);
	scanf("%s",genero);
	printf("\n\n");
	printf("|----------------------------------------------------|\n");	


for (int index=0; index<quantidade; index++){

if(strcspn(livro[index].generoLivro,genero)==0){//é usada para determinar o comprimento do segmento inicial de uma string que contém apenas caracteres que não estão presentes em outra string.

	printf("GENERO ENCONTRADO:\n");
	getchar();
	printf("|----------------------------------------------------|\n");	
	printf("\nTitulo: %s\n", livro[index].titulo);
	printf("Nome do autor: %s\n", livro[index].nomeAutor);
	printf("Preco: %i \n\n", livro[index].preco);
	printf("Genero do Livro:%s ", livro[index].generoLivro);
	printf("\n\n");
	printf("|----------------------------------------------------|\n");	
	

}else{
		printf("Genero Não Encontrado :(");

}

}
}
//FUNÇÃO DE SÁIDA

void exit(void){
	
		int tempo = clock();
	printf("|-------------SAIR DO PROGRAMA-----------------------|\n");
	printf("|----------------------------------------------------|\n");
	printf("|Aguarde...                                          |\n");
	printf("|Encerrando programa em  3 segundos                  |\n");
	printf("|----------------------------------------------------|\n");

tempo = clock();

while(clock() - tempo < 3000){ 


}
exit(0);
}


