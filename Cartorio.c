#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar cadastrar os usu�rios no sistema
{
	//Inicio cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
    fprintf(file,",\n"); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
    scanf("%s",nome); //%s Salva o conte�do que est� na string
    
    file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
    fprintf(file,nome); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
    fprintf(file,",\n"); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
    scanf("%s",sobrenome); //%s Salva o conte�do que est� na string
    
    file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
    fprintf(file,sobrenome); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
    fprintf(file,",\n"); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
    scanf("%s",cargo); //%s Salva o conte�do que est� na string
    
    file = fopen(arquivo, "a"); //Abre o arquivo e o "a" significa atualizar
    fprintf(file,cargo); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    system("pause"); //Mostra a informa��o para o usu�rio
    
}

int consulta() //Fun��o responsavel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); //%s Salva o conte�do que est� na string
	
	FILE *file;	//Consultar o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e o "r" significa consultar
	
	if(file == NULL) 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //Mostrando a informa��o para o usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //Mostrando as informa��es do usu�rio
		printf("%s", conteudo); //%s Salva o conte�do que est� na string
		printf("\n\n"); //Pular duas linhas
	}
	
	system("pause"); //Mostra a informa��o para o usu�rio
}
int deletar() //Fun��o responsavel por deletar os usu�rios no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando dados do usu�rio 
	scanf("%s",cpf); //%s Salva o conte�do que est� na string
	
	remove(cpf); //Acessa a pasta principal e deleta o numero do arquivo 
	
	FILE *file; //Consultar o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo e o "r" significa consultar
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); // Informa��o do usu�rio 
		system("pause"); //Mostra a informa��o para o usu�rio
	}
	
}
int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //Definindo vari�veis
	
	for(laco=1;laco=1;)
	{
		
	  system("cls"); //responsavel por limpar a tela	
	
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	  printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	  printf("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n");
	  printf("\t4 - Sair do sistema\n\n"); 
	  printf("Op��o: "); //Fim do menu
	
	  scanf("%d", &opcao); //Armazenando a escolha do usu�rio 
	
	  system("cls"); //responsavel por limpar a tela
	  
	  switch(opcao) //Inicio da sele��o do menu
	  {
	  	case 1:
	    registro(); //chamada de fun��es
		break; //Fecha a chave
		
		case 2:
		consulta(); //chamada de fun��es
		break; //Fecha a chave
		
		case 3:
		deletar(); //chamada de fun��es
		break; //Fecha a chave
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		default:
		printf("Essa op��o n�o est� disponivel!\n"); //Informa��o para o usu�rio
		system("pause"); //Mostra a informa��o para o usu�rio
		break; //Fecha a chave	
	  } //Fim da sele��o
	
	
	}
}
