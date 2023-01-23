#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o na memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registrar(){
	char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("\n---Registrar nomes---\n\n");	//fun��o de registrar nomes
	printf("\nDigite o CPF: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);        //copiar valores das strings
	
	FILE *file;					//cria um arquivo no banco de dados
	file=fopen(arquivo,"w");	//comando para escrever no arquivo
	fprintf(file,cpf);			//salva os dados no arquivo
	fclose(file);				//fecha o arquivo
		
	file=fopen(arquivo,"a");
	fprintf(file,",_nome:");		
	fclose(file);
	
	printf("\nDigite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file=fopen(arquivo,"a");
	fprintf(file,nome);			//insere o nome no arquivo	
	fclose(file);
		
	file=fopen(arquivo,"a");
	fprintf(file,",_sobrenome:");
	fclose(file);	
		
	printf("\nDigite o sobrenome: ");
	scanf("%s",sobrenome);
	
	file=fopen(arquivo, "a");	//insere o sobrenome no arquivo
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",_cargo:");
	fclose(file);
	
	printf("\nDigite o cargo: ");
	scanf("%s",cargo);
	
	file=fopen(arquivo,"a");	//insere o cargo no arquivo
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}
int consultar(){		//fun��o de consultar nomes
	
	char cpf[40], conteudo[200];
	
	setlocale(LC_ALL,"Portuguese");	
	
	printf("\n---Consultar nomes---\n\n");   //titulo da pagina
	
	printf("\nDigite um CPF para consultar: ");
	scanf("%s",cpf);
	
	
	FILE *file;					//localiza o arquivo com o cpf e faz a leitura
	file = fopen(cpf,"r");
	
	if(file==NULL){
		printf("\nO CPF n�o foi localizado!\n");	//caso de n�o ser um cpz valido
	}
	
	while(fgets(conteudo,200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");	//mostrar na tela as informa��es do arquivo
		printf("%s\n\n",conteudo);
		
	}
	
	system("pause");
}

int deletar(){
	
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	
	printf("\n---Deletar nomes---\n\n");    //fun��o de deletar nomes     (ainda n�o completa)
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL){
		printf("\nO CPF inserido n�o se encontra no sistema!\n");
		system("pause");
	}

	
}
int main(){
	
	int opcao=0,laco=1;       //variavel "opcao" � para a escolha das a��es, e varialvel "laco" � apenas para o la�o de repeti��o
	
	setlocale(LC_ALL,"Portuguese");      //selecionando a linguiagem para poder ter acentua��o
	
	for(laco=1;laco=1;){      //la�o de repeti��o para ficar mostrando o menu novamente
	
		
		system("cls");		//limpar a tela 
		
		
		printf("\n---Cart�rio da EBAC---\n\n");	 //titulo do software
	
	
		printf("Escolha a op��o desejada do menu:\n\n");                      //eu prefiro deixar os printf em linhas separadas para melhor organiza��o do c�digo
		printf("\t1- Registrar nomes\n"); 		 //menu com as op��es
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n");
		printf("\nOp��o: ");
	
		scanf("%d",&opcao);   //escaneando a escolha
	
		system("cls");     //limpando a tela
	
		
		switch(opcao){
			
			case 1:                                  //escolha de registrar nomes
			registrar();
			break;
			
			case 2:									//escolha de consultar
			consultar();			
			break;
					
			case 3:									//escolha de deletar nomes
			deletar();				
			break;
			
			default:
			printf("\n---Essa op��o n�o esta disponivel!---\n\n");   //caso n�o ser uma op��o valida, aviso na tela e retorno para o menu
			system("pause");
			break;
		} 												// no final de todas as op��es voltar para o menu
	} //fim do la�o de repeti��o
	
} //fim do c�digo
