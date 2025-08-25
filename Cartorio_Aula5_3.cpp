#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
	// início da criação de variáveos / string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveos / string
	
	printf("Digite o CPF a ser cadastrado:  "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; // FILE é uma função do sistema, ela diz acesse file
	file = fopen(arquivo, "w"); //cria o arquivo fopen abrir arquivo, arquivo novo pois é W write
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");  //  a é para acessar a informação, write é para gravar
	fprintf(file,","); // incluir uma vírgula
	fclose(file);
	
	printf("Digite um nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");  //  a é para acessar a informação, write é para gravar
	fprintf(file,","); // incluir uma vírgula
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");  //  a é para acessar a informação, write é para gravar
	fprintf(file,","); // incluir uma vírgula
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");  //  a é para acessar a informação, write é para gravar
	fprintf(file,","); // incluir uma vírgula
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r é de read
	
	if(file == NULL) // == comparação, file == NULL é se o aquivo é nulo
	{
		printf("Não foi possível abrir o aquivo, não localizado!.\n");
		
	}	
	
	while(fgets(conteudo, 200, file) != NULL) // Salvando na variável conteúdo, os 200 caracteres, dentro do arquivo(file), quando não achar é nulo   While=enquanto
	{
		printf("Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n"); //pulou duas linhas
}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; // entrar na bivlioteca que fala sobre a função FILE e dentro dela puxar os arquivos file
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
	
	
}

int main()
{
	int opcao=0; //Atribução de informação, Defininindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
	
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("Opção:"); //Fim do Menu
	
		scanf("%d", &opcao); //%d variavel inteira, armazena na variavel opcao o valor digitado, scanf pausa até a tomada de decisão, armazenando a escolha do usuário
	
		system("cls"); //cls, limpa a tela após a tomada de decisão
		
			switch(opcao) // início da seleção do menu
		{
			case 1:
			registro(); // chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
						
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
				
		}
	

}
}
