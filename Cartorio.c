#include <stdio.h>	//biblioteca de comunicação com o usuário
#include <stdlib.h>	//biblioteca responsável por alocação de memória
#include <locale.h>	//biblioteca de alocações de texto por região
#include <string.h>	//biblioteca responsável por cuidas das string's

int registro(){	//função responsável por cadastrar os usuários
	
	char arquivo[11];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string's
	
	FILE *file;	//cria o arquivo no banco de dados
	file = fopen(arquivo, "w");	//abre o arquivo e "w" pede para escrever
	fprintf(file,cpf);	//salva o valor da variável
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

int consulta(){	//função responsável por consultar os usuários
	
	char cpf[11];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");	//abre o arquivo e le 
	
	if(file == NULL){
		printf("CPF não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deleta(){	//função responsável por remover os usuários
	
	char cpf[11];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	//remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");	

	
	if (file){
		fclose(file);	
		remove(cpf);	//remove o cpf solicitado e manda uma mensagem para o usuário
		printf("O usuário foi excluido com sucesso!\n");
		system("pause");
	}else {
		printf("CPF do usuário não encontrado.\n");	//se o arquivo for NULO, ou seja, não encontrado, responde para o usuário que não foi encontrado
		system("pause");
	}
	
}

int main(){		//função principal do sistema *MENU*
	
	int opcao = 0;	//definição da variavel de escolha
	int laco = 1;
	
	for (laco = 1 ;laco =1 ;){
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Opção de colocar a lingua portuguesa.
	
	//Menu do cartório:
	printf("\t--- Cartório da Paula ---\n\n");	//inicio do menu
	printf("Escolha a opção desejada no menu: \n\n");
	printf("\t1- Registrar nomes\n");
	printf("\t2- Consultar nomes\n");
	printf("\t3- Deletar nomes\n");
	printf("\t4- Sair do sistema\n\n");
	printf("Opção: ");	//final do menu
	
	scanf("%d", &opcao);	//armazenando a escolha do usuário
	
	system("cls");	//limpando a tela
	
	
	switch(opcao){	//inicio da seleção
		
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
		printf("Opcão inválida.\n");
		system("pause");
		break;	//final da seleção
			
	}
	}
}
