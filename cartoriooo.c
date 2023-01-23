#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço na memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registrar(){
	char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("\n---Registrar nomes---\n\n");	//função de registrar nomes
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
int consultar(){		//função de consultar nomes
	
	char cpf[40], conteudo[200];
	
	setlocale(LC_ALL,"Portuguese");	
	
	printf("\n---Consultar nomes---\n\n");   //titulo da pagina
	
	printf("\nDigite um CPF para consultar: ");
	scanf("%s",cpf);
	
	
	FILE *file;					//localiza o arquivo com o cpf e faz a leitura
	file = fopen(cpf,"r");
	
	if(file==NULL){
		printf("\nO CPF não foi localizado!\n");	//caso de não ser um cpz valido
	}
	
	while(fgets(conteudo,200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");	//mostrar na tela as informações do arquivo
		printf("%s\n\n",conteudo);
		
	}
	
	system("pause");
}

int deletar(){
	
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	
	printf("\n---Deletar nomes---\n\n");    //função de deletar nomes     (ainda não completa)
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL){
		printf("\nO CPF inserido não se encontra no sistema!\n");
		system("pause");
	}

	
}
int main(){
	
	int opcao=0,laco=1;       //variavel "opcao" é para a escolha das ações, e varialvel "laco" é apenas para o laço de repetição
	
	setlocale(LC_ALL,"Portuguese");      //selecionando a linguiagem para poder ter acentuação
	
	for(laco=1;laco=1;){      //laço de repetição para ficar mostrando o menu novamente
	
		
		system("cls");		//limpar a tela 
		
		
		printf("\n---Cartório da EBAC---\n\n");	 //titulo do software
	
	
		printf("Escolha a opção desejada do menu:\n\n");                      //eu prefiro deixar os printf em linhas separadas para melhor organização do código
		printf("\t1- Registrar nomes\n"); 		 //menu com as opções
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n");
		printf("\nOpção: ");
	
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
			printf("\n---Essa opção não esta disponivel!---\n\n");   //caso não ser uma opção valida, aviso na tela e retorno para o menu
			system("pause");
			break;
		} 												// no final de todas as opções voltar para o menu
	} //fim do laço de repetição
	
} //fim do código
