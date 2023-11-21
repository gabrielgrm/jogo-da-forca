#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "desenho.h"

typedef struct{
    char palavra[100];
    struct Palavra *prox;
}Palavra;

Palavra *primeiraPalavra;
Palavra *ultimaPalavra;
int tamanho;

void chances(int contador);
void vitoria(char tentativa);
void desenho(int contador,int flagInicio);
void letrasErradas(int erro1,int erro2,int erro3,int erro4,int erro5,char tentativa,int contador);
void verificaTentativa(char qtdCaracter,char tentativa,int *certo,int *contador,char resposta[]);
void caracter(char *tentativa);
void verificaErro(char frase[],int qtdCaracter,int *contador,char tentativa,int *erro1,int *erro2,int *erro3,int *erro4,int *erro5,int *n);
int menu();
char* buscar(char nomeArquivo[]);
void listaVazia();
void inserirLista(Palavra palavra);
int sorteio(int faixa);
void limparLista();
int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int i, contador, n, qtdCaracter, erro1, erro2, erro3, erro4, erro5, certo,opcao;
    char frase[100], resposta[100], tentativa, confirmar, continuar;
    do
    {
        MENU:
        system("cls");
        desenho(contador,1);

        opcao=menu();
        if(opcao==0)
        {
        exit(0);
        }
        else if(opcao==1)
        {
            strcpy(frase,buscar("animais.txt"));
        }
        else if(opcao==2)
        {
            strcpy(frase,buscar("marcas.txt"));
        }
        else if(opcao==3)
        {
            strcpy(frase,buscar("paises.txt"));
        }
        else if(opcao==4)
        {
            strcpy(frase,buscar("famosos.txt"));
        }
        else if(opcao==5)
        {
            strcpy(frase,buscar("profissoes.txt"));
        }else{
            printf("\nOpção Invalida tente Novamente");
            goto MENU;
        }

        confirmar = 'n';
        while(confirmar != 'S')
        {
            certo = 0;
            qtdCaracter=0;
            n = 0;
            i=0;
            contador = 0;
            erro1 = ' ';
            erro2 = ' ';
            erro3 = ' ';
            erro4 = ' ';
            erro5 = ' ';
            tentativa=' ';
            printf("O jogo sera iniciado...\n");
            system("PAUSE");
            system("CLS");
            for(i = 0; i < 100; i++)
            {
                resposta[i]='_';
            }
            while(contador < 6)
            {
                n=0;
                certo=0;
                desenho(contador,0);

                for(i=0; i < 100; i++)
                {
                    if(frase[i]=='\0')
                    {
                        qtdCaracter = i;
                        break;
                    }
                    else
                    {
                        if(frase[i]==' ')
                        {
                            resposta[i]=' ';
                            printf("%c", resposta[i]);
                        }
                        else
                        {
                            if(frase[i]==tentativa)
                            {
                                resposta[i]=frase[i];
                            }
                        }
                    }
                    printf("%c ", resposta[i]);
                }

                letrasErradas(erro1,erro2,erro3,erro4,erro5,tentativa,contador);
                chances(contador);
                verificaTentativa(qtdCaracter,tentativa,&certo,&contador,resposta);
                if(certo!=qtdCaracter)
                {
                    caracter(&tentativa);

                }
                verificaErro(frase,qtdCaracter,&contador,tentativa,&erro1,&erro2,&erro3,&erro4,&erro5,&n);

                system("cls");
            }


            if(contador==6)
            {
                desenho(contador,0);
                for(i = 0; i < qtdCaracter; i++)
                {
                    if(resposta[i]==frase[i])
                    {
                        printf("%c ", resposta[i]);
                    }
                    else
                    {
                        printf("(%c) ", frase[i]);
                    }
                }
                letrasErradas(erro1,erro2,erro3,erro4,erro5,tentativa,contador);
                printf("\n\n\nVoçê Morreu !!!!\n");
                system("PAUSE");
            }
            if(contador==7)
            {
               vitoria(tentativa);
            }
            confirmar = 'S';
            printf("Deseja jogar novamente (S/N)? ");
            fflush(stdin);
            continuar = toupper(getchar());
        }
    }
    while(continuar=='S');
    system("PAUSE");
    return 0;
}

int menu()
{
    int opcao;
	printf("+--------------------------------------------------------+");
	printf("\n|                    JOGO DA FORCA                       |");
	printf("\n+--------------------------------------------------------+");
	printf("\n|   Escolha uma categoria e teste seus conhecimentos!    |");
	printf("\n|--------------------------------------------------------|");
	printf("\n|   1 – Animais          |   4 – Famosos                 |");
	printf("\n|   2 – Marcas           |   5 – Profissões              |");
	printf("\n|   3 – Países           |   0 – Sair do Jogo            |");
	printf("\n+--------------------------------------------------------+");
	printf("\n|   Digite o número da opção desejada:                   |");
	printf("\n+--------------------------------------------------------+\n");
    scanf("%d",&opcao);
    return opcao;
}
void chances(int contador) {


    switch(contador)
    {
    case 0:
        puts("\n\nVoce pode errar 5 vezes");
        break;
    case 1:
        puts("\n\nVoce pode errar 4 vezes");
        break;
    case 2:
        puts("\n\nVoce pode errar 3 vezes");
        break;
    case 3:
        puts("\n\nVoce pode errar 2 vezes");
        break;
    case 4:
        puts("\n\nVoce pode errar apenas mais uma vez");
        break;
    case 5:
        puts("\n\nSe errar agora você morre!!!!");
    }

}
void vitoria(char tentativa)
{
printf("\n===========================================================");
printf("\n||                                                       ||");
printf("\n||             PARABÉNS! VOCÊ ACERTOU A PALAVRA!!        ||");
printf("\n||                                                       ||");
printf("\n===========================================================\n");


    tentativa='_';
}
void letrasErradas(int erro1,int erro2,int erro3,int erro4,int erro5,char tentativa, int contador)
{
    if(contador==6)
    {
        printf("\n\n%c %c %c %c %c %c\n", erro1, erro2, erro3, erro4, erro5, tentativa);
    }
    else
    {
        printf("\n\n%c %c %c %c %c\n", erro1, erro2, erro3, erro4, erro5);
    }

}

void verificaTentativa(char qtdCaracter,char tentativa,int *certo,int *contador,char resposta[])
{
    int i;
    for(i = 0; i <= qtdCaracter; i++)
    {
        if(tentativa!=' ')
        {
            if(resposta[i]!='_')
            {
                *certo=*certo+1;
                if(*certo==qtdCaracter)
                {
                    *contador=7;
                    break;
                }
            }
        }
    }

}
void caracter(char *tentativa)
{
    char tecla;
    printf("\n\nDigite uma letra: ");
    fflush(stdin);
    scanf("%c",&tecla);
    *tentativa=tecla;
    *tentativa = tolower(*tentativa);
}

void verificaErro(char frase[],int qtdCaracter,int *contador,char tentativa,int *erro1,int *erro2,int *erro3,int *erro4,int *erro5,int *n)
{
    int i;
    for(i = 0; i < qtdCaracter; i++)
    {
        if(tentativa!=frase[i])
        {
            *n=*n+1;
            if(*n==qtdCaracter)
            {
                *contador=*contador+1;
                if(*contador==1)
                {
                    *erro1 = tentativa;
                }
                if(*contador==2)
                {
                    *erro2 = tentativa;
                }
                if(*contador==3)
                {
                    *erro3 = tentativa;
                }
                if(*contador==4)
                {
                    *erro4 = tentativa;
                }
                if(*contador==5)
                {
                    *erro5 = tentativa;
                }
            }
        }
    }

}
char* buscar(char nomeArquivo[])
{
    FILE *pont_arq;
    char linha[1024];
    char palavraSorteada[100];
    Palavra palavra;
    pont_arq = fopen(nomeArquivo, "r");
    if(pont_arq == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    int i=0;
    tamanho=0;
    listaVazia();
    while(fscanf(pont_arq, " %[^\n]s",linha)!=EOF)
    {
        char *ptr;
        ptr=strtok(linha,";");
        strcpy(palavra.palavra,ptr);
        ptr=strtok(NULL,";");
        inserirLista(palavra);
        tamanho++;

    }
    fclose(pont_arq);

    Palavra lista[tamanho-1];
    Palavra *palavraAux;
    palavraAux=primeiraPalavra->prox;
    i=0;
    int numero=sorteio(tamanho-1);
    while(palavraAux!= NULL){
        if(i==numero){
             strcpy( palavraSorteada,palavraAux->palavra);
        }
        palavraAux=palavraAux->prox;
        i++;
    }
    limparLista();
    return palavraSorteada;
}
void listaVazia(){
    primeiraPalavra=(Palavra *)malloc(sizeof(Palavra));
    ultimaPalavra=primeiraPalavra;
}
void inserirLista(Palavra palavra){
    Palavra *palavraAux;
    palavraAux = (Palavra *)malloc(sizeof(Palavra));

    strcpy( palavraAux->palavra,palavra.palavra);

    ultimaPalavra->prox=palavraAux;
    ultimaPalavra=ultimaPalavra->prox;
    palavraAux->prox=NULL;
}
int sorteio(int faixa){
    srand( (unsigned)time(NULL) );
    return  rand() % faixa;
}

void limparLista()
{
    Palavra *no = primeiraPalavra, *aux;
    while (no != NULL)
    {
        aux = no;
        no = no->prox;
        free (aux);
    }
    primeiraPalavra = NULL;
    ultimaPalavra=NULL;
}
