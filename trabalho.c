#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
/*
Este programa tem como objetivo ser um metodo de cadastro em arquivo de alunos em 
em uma universadade. 
O programa utiliza de um menu simples para direcionar o usuario
atraves das ações desejadas.
Utilizando de uma struct, o programa salva em um arquivo de texto os dados dos alunos (nome,
idade, nome, matricula, curso e o turno) e retorna a consulta quando desejado. 
Podemos manipular os dados salvos dados da maneira que quisermos, bastando selecionar a ação
no menu.
*/

char nomeArquivo[] = "Alunos.csv";
char arquivoTemp[] = "ArqTemp.csv";

typedef struct aluno{
	char idade[200];
	char nome[200];
	char matricula[200];
	char curso[200];
	char turno[20];
}aluno;

void printarDadosTela(aluno a){

    printf("Nome: %s", a.nome);
	printf("Idade: %s", a.idade);
	printf("Matricula: %s", a.matricula);
	printf("Curso: %s", a.curso);
	printf("Turno: %s", a.turno);
	printf("\n------------------------------------------\n");
}

void vizualiza(){
	FILE *arq;
	arq = fopen(nomeArquivo,"r");
	aluno a;
	rewind(arq); 

    int cont = 0;

	while(fgets(a.nome, 200, arq) != NULL){
		fgets(a.idade, 200, arq);
        fgets(a.matricula, 200, arq);
        fgets(a.curso, 200, arq);
        fgets(a.turno, 200, arq);
        printarDadosTela(a);
	}

	fclose(arq);
}


void adiciona(){
	FILE *arq;
	arq = fopen(nomeArquivo,"a");
	aluno a;
	printf("Digite o nome do aluno: \n:>");
	gets(a.nome);
	printf("Digite a idade do aluno: \n:>");
	gets(a.idade);
	printf("Digite o matricula do aluno: \n:>");
	gets(a.matricula);
	printf("Digite o curso do aluno: \n:>");
	gets(a.curso);
	printf("Digite o turno do aluno: \n:>");
	gets(a.turno);
	fprintf(arq, "%s\n%s\n%s\n%s\n%s\n", a.nome, a.idade, a.matricula, a.curso, a.turno);
	fclose(arq);
}

	void modifica() {
    aluno a;
    aluno b;
    FILE *arq;
    FILE *arqtemp;
    arq = fopen(nomeArquivo, "a+");
    arqtemp = fopen(arquivoTemp, "a+");
    rewind(arq);
    char novoNome[200];
    char nomeBusca[200];
    int encontrado = 0;
    do {
        printf("Digite o nome buscado ou digite \"sair\": \n:>");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);

        

        nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; 
        if (strcmp(nomeBusca, "sair") == 0) {
            break; 
        }
        encontrado = 0; 

        strcat(nomeBusca, "\n");
        while(fgets(a.nome, 200, arq) != NULL){
            fgets(a.idade, 200, arq);
            fgets(a.matricula, 200, arq);
            fgets(a.curso, 200, arq);
            fgets(a.turno, 200, arq);

            if (strcmp(a.nome, nomeBusca) == 0) {
                printf("Digite o novo nome: \n:>");
                fgets(b.nome, sizeof(b.nome), stdin);
                b.nome[strcspn(b.nome, "\n")] = '\0'; 
                
                printf("Digite a idade: \n:>");
                fgets(b.idade, sizeof(b.idade), stdin);
                b.idade[strcspn(b.idade, "\n")] = '\0'; 
                
                printf("Digite a matricula: \n:>");
                fgets(b.matricula, sizeof(b.matricula), stdin);
                b.matricula[strcspn(b.matricula, "\n")] = '\0'; 
                
                printf("Digite o novo curso: \n:>");
                fgets(b.curso, sizeof(b.curso), stdin);
                b.curso[strcspn(b.curso, "\n")] = '\0'; 
                
                printf("Digite o novo turno: \n:>");
                fgets(b.turno, sizeof(b.turno), stdin);
                b.turno[strcspn(b.turno, "\n")] = '\0'; 
                
                encontrado = 1;
                break;
            }
	}
        rewind(arq); 
    } while (encontrado == 0 && strcmp(nomeBusca, "sair") != 0);

    while(fgets(a.nome, 200, arq) != NULL){
		fgets(a.idade, 200, arq);
        fgets(a.matricula, 200, arq);
        fgets(a.curso, 200, arq);
        fgets(a.turno, 200, arq);
        if (strcmp(a.nome, nomeBusca) == 0) {
            fprintf(arqtemp, "%s\n%s\n%s\n%s\n%s\n", b.nome, b.idade, b.matricula, b.curso, b.turno);
        } else {
            fprintf(arqtemp, "%s\n%s\n%s\n%s\n%s\n", a.nome, a.idade, a.matricula, a.curso, a.turno);
        }
    }

    fclose(arqtemp);
    fclose(arq);

    if (encontrado == 0) {
        if (remove(arquivoTemp) == 0) {
            printf("Aluno não encontrado.\n");
        }
    } else {
        if (remove(nomeArquivo) == 0 && rename(arquivoTemp, nomeArquivo) == 0) {
            printf("Registro alterado com sucesso.\n");
        }
    }
}	
void exclui() {
    aluno a;
    FILE *arq;
    FILE *arqtemp;
    arq = fopen(nomeArquivo, "a+");
    arqtemp = fopen(arquivoTemp, "w");
    rewind(arq);
    char nomeBusca[200];
    int encontrado = 0;
    printf("Digite o nome buscado para exclui-lo: \n:>");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; 

    strcat(nomeBusca, "\n");

    while(fgets(a.nome, 200, arq) != NULL){
		fgets(a.idade, 200, arq);
        fgets(a.matricula, 200, arq);
        fgets(a.curso, 200, arq);
        fgets(a.turno, 200, arq);
            
        if (strcmp(a.nome, nomeBusca) == 0) {
            printf("A nome é: %s\n", a.nome);
            printf("A idade é: %s\n", a.idade);
            printf("A matricula é: %s\n", a.matricula);
            printf("A curso é: %s\n", a.curso);
            printf("A turno é: %s\n", a.turno);
            printf("\n------------------------------------------\n");
            printf("Deseja excluir este nome? (s/n) \n:>");
            char resposta[3];
            fgets(resposta, sizeof(resposta), stdin);
            resposta[strcspn(resposta, "\n")] = '\0'; 
            
            if (strcmp(resposta, "s") == 0) {
                encontrado = 1;
                continue; 
            }
        }
        fprintf(arqtemp, "%s %s %s %s %s\n", a.nome, a.idade, a.matricula, a.curso, a.turno);
        }

    fclose(arq);
    fclose(arqtemp);
    if (encontrado) {
        remove(nomeArquivo);
        rename(arquivoTemp, nomeArquivo);
        printf("Registro excluído com sucesso!\n");
    } else {
        printf("Nome nao encontrado e nenhum registro foi excluido.\n");
    }
}
int main(){
	int entrada;
	setlocale(LC_ALL,"Portuguese");
	FILE *arq;
	arq = fopen(nomeArquivo,"r");
	if(arq == NULL){
		fopen(nomeArquivo,"w");
	}
	fclose(arq);
    do{
    	printf("\n------------------------------------------\n");
        printf("\tAlterador de registro\n");
        printf("\tEscolha uma opção:");
        printf("\n1. Adicionar registro");
        printf("\n2. Visualizar registro");
        printf("\n3. Modificar registro");
        printf("\n4. Excluir registro");
        printf("\n5. Sair\n");
        printf("\n------------------------------------------\n:>");
        scanf("%i", &entrada);
        getchar();
		if(entrada == 1){
			adiciona();
		}else if(entrada == 2){
			vizualiza();
		}else if(entrada == 3){
			modifica();
		}else if(entrada == 4){
			exclui();
		}else if(entrada == 5){
			return 0;
		}else{
			printf("Valor Inválido\n");
		}
    }while (1);
    if (fopen(arquivoTemp,"r")!=NULL){
		if (remove(arquivoTemp)==0);
	return 0;
	}
}