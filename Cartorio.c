#include <stdio.h>	//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>	//biblioteca respons�vel por aloca��o de mem�ria
#include <locale.h>	//biblioteca de aloca��es de texto por regi�o
#include <string.h>	//biblioteca respons�vel por cuidas das string's

int registro(){	//fun��o respons�vel por cadastrar os usu�rios
	
	char arquivo[11];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string's
	
	FILE *file;	//cria o arquivo no banco de dados
	file = fopen(arquivo, "w");	//abre o arquivo e "w" pede para escrever
	fprintf(file,cpf);	//salva o valor da vari�vel
	fclose(file);	//fecha o arquivo
	
	file = fopen(arquivo, "a");	//abre o arquivo e altera o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fprintf(file, ",");
	fprintf(file, sobrenome);
	fprintf(file, ",");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta(){	//fun��o respons�vel por consultar os usu�rios
	
	char cpf[11];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");	//abre o arquivo e le 
	
	if(file == NULL){
		printf("CPF n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deleta(){	//fun��o respons�vel por remover os usu�rios
	
	char cpf[11];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	//remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");	

	
	if (file){
		fclose(file);	
		remove(cpf);	//remove o cpf solicitado e manda uma mensagem para o usu�rio
		printf("O usu�rio foi excluido com sucesso!\n");
		system("pause");
	}else {
		printf("CPF do usu�rio n�o encontrado.\n");	//se o arquivo for NULO, ou seja, n�o encontrado, responde para o usu�rio que n�o foi encontrado
		system("pause");
	}
	
}

int main(){		//fun��o principal do sistema *MENU*
	
	int opcao = 0;	//defini��o da variavel de escolha
	int laco = 1;
	
	for (laco = 1 ;laco =1 ;){
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Op��o de colocar a lingua portuguesa.
	
	//Menu do cart�rio:
	printf("\t--- Cart�rio da Paula ---\n\n");	//inicio do menu
	printf("Escolha a op��o desejada no menu: \n\n");
	printf("\t1- Registrar nomes\n");
	printf("\t2- Consultar nomes\n");
	printf("\t3- Deletar nomes\n");
	printf("\t4- Sair do sistema\n\n");
	printf("Op��o: ");	//final do menu
	
	scanf("%d", &opcao);	//armazenando a escolha do usu�rio
	
	system("cls");	//limpando a tela
	
	
	switch(opcao){	//inicio da sele��o
		
		case 1:
		registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deleta();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		printf("\n\n\nEsse sistema foi desenvolvido por Paula Rabelo, aluna de TI da EBAC.\n");
		return 0;
		break;
		
		default:
		printf("Opc�o inv�lida.\n");
		system("pause");
		break;	//final da sele��o
			
	}
	}
}
