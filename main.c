#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "keyboard.h"
#include <unistd.h>
// Defini��o da estrutura de n� da lista encadeada
struct Node {
    char letter;
    struct Node* next;
};

typedef struct Node Node;

// Declara��o de fun��es
void mostrarForca(int escolha);
char* escolherPalavra(const char* nomeArquivo);
Node* criarNode(char letter);
void inserirNode(Node** head, char letter);
int verificarTentativa(Node* head, char letter);

int main(void) {
    char saidaForca[100];
    int tentativasErradas = 7;
    int iguais = 0;
    int contador = 0, posicao = 0, vencedor, comprimento, i;
    char alfabetoUsuario;
    char* palavraForca;
    Node* letrasTentadas = NULL; // Lista encadeada para rastrear letras j� tentadas

    mostrarForca(tentativasErradas);
    printf("+--------------------------------------------------------+\n");
    printf("|                    JOGO DA FORCA                       |\n");
    printf("+--------------------------------------------------------+\n");
    printf("|   Escolha uma categoria e teste seus conhecimentos!    |\n");
    printf("|--------------------------------------------------------|\n");
    printf("|   1 � Animais          |   4 � Famosos                 |\n");
    printf("|   2 � Marcas           |   5 � Profiss�es              |\n");
    printf("|   3 � Pa�ses           |   0 � Sair do Jogo            |\n");
    printf("+--------------------------------------------------------+\n");
    printf("|   Digite o n�mero da op��o desejada:                   |\n");
    printf("+--------------------------------------------------------+\n");

    int opcao;
    scanf("%d", &opcao);
    getchar(); // Consome o '\n' deixado pelo scanf

    const char* nomeArquivo = NULL;
    switch (opcao) {
        case 1: nomeArquivo = "animais.txt"; break;
        case 2: nomeArquivo = "marcas.txt"; break;
        case 3: nomeArquivo = "paises.txt"; break;
        case 4: nomeArquivo = "famosos.txt"; break;
        case 5: nomeArquivo = "profissoes.txt"; break;
        case 0: printf("Saindo do jogo...\n"); return 0;
        default: printf("Op��o inv�lida!\n"); return 1;
    }

    // Escolhe uma palavra aleat�ria da categoria selecionada
    palavraForca = escolherPalavra(nomeArquivo);
    if (palavraForca == NULL) {
        printf("N�o foi poss�vel carregar uma palavra da categoria.\n");
        return 1;
    }

    comprimento = strlen(palavraForca);
    for (i = 0; i < comprimento; i++) {
        saidaForca[i] = '_';
    }
    saidaForca[comprimento] = '\0';
    tentativasErradas = 6;
    // In�cio do jogo
    system("clear");
    keyboardInit(); // Inicializar a leitura de teclado sem esperar Enter
    while (tentativasErradas > 0) {
        iguais = 0;
        system("clear");
        mostrarForca(tentativasErradas);
        printf("\n%s", saidaForca);
        printf("\n\nLetras j� tentadas: ");
        // Imprimir letras j� tentadas
        Node* temp = letrasTentadas;
        while (temp != NULL) {
            printf("%c ", temp->letter);
            temp = temp->next;
        }
        printf("\n\nDigite uma letra: ");

        if (keyhit()) {
            alfabetoUsuario = tolower(readch()); // Ler uma letra sem pressionar Enter

            if (alfabetoUsuario < 'a' || alfabetoUsuario > 'z') {
                printf("\nEntrada inv�lida, tente novamente.\n");
                usleep(500000);
                continue;
            }

            // Verificar se a letra j� foi tentada
            if (verificarTentativa(letrasTentadas, alfabetoUsuario)) {
                printf("\nVoc� j� tentou essa letra. Tente outra.\n");
                usleep(500000);
                continue;
            }

            // Inserir a letra na lista de letras tentadas
            inserirNode(&letrasTentadas, alfabetoUsuario);

            for (contador = 0; contador < comprimento; contador++) {
                if (alfabetoUsuario == palavraForca[contador]) {
                    saidaForca[contador] = alfabetoUsuario;
                    iguais = 1;
                }
            }

            if (!iguais) {
                tentativasErradas--;
            }

            if (strcmp(saidaForca, palavraForca) == 0) {
                system("clear");
                keyboardDestroy();
                printf("\nParab�ns! Voc� adivinhou a palavra correta: %s\n", palavraForca);
                break;
            }
        }

        usleep(250000); // Pausa de 0.25 segundo
    }

    keyboardDestroy();

    if (tentativasErradas <= 0) {
        system("clear");
        mostrarForca(tentativasErradas);
        printf("\nVoc� perdeu. A palavra era: %s\n", palavraForca);
    }

    // Libere a mem�ria da lista de letras tentadas
    Node* temp = letrasTentadas;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    free(palavraForca);
    return 0;
}

char* escolherPalavra(const char* nomeArquivo) {
    FILE* file = fopen(nomeArquivo, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    int qtdPalavras = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), file)) {
        qtdPalavras++;
    }

    srand(time(NULL)); // Semente para o gerador de n�meros aleat�rios
    int escolhaPalavra = rand() % qtdPalavras;

    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < escolhaPalavra; i++) {
        fgets(linha, sizeof(linha), file);
    }

    linha[strcspn(linha, "\n")] = 0;

    // Remover espa�os em branco extras no final da palavra
    int length = strlen(linha);
    while (length > 0 && isspace(linha[length - 1])) {
        linha[length - 1] = '\0';
        length--;
    }

    char* palavra = (char*)malloc(strlen(linha) + 1);
    strcpy(palavra, linha);

    fclose(file);
    return palavra;
}


// Fun��o para criar um n� da lista encadeada
Node* criarNode(char letter) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->letter = letter;
    newNode->next = NULL;
    return newNode;
}

// Fun��o para inserir um n� na lista encadeada
void inserirNode(Node** head, char letter) {
    Node* newNode = criarNode(letter);
    newNode->next = *head;
    *head = newNode;
}

// Fun��o para verificar se uma letra j� foi tentada
int verificarTentativa(Node* head, char letter) {
    Node* current = head;
    while (current != NULL) {
        if (current->letter == letter) {
            return 1; // A letra j� foi tentada
        }
        current = current->next;
    }
    return 0; // A letra ainda n�o foi tentada
}

// Fun��o para mostrar a forca
void mostrarForca(int tentativasErradas) {
    switch(tentativasErradas) {
      case 7:
      printf("\n||===== ");
      printf("\n||    | ");
      printf("\n||    O                           +----------------------+");
      printf("\n||   /|\\                          |    Antonio Valen�a   |");
      printf("\n||   / \\                          |   Gabriel Rodrigues  |");
      printf("\n||                                |     Mirna Lustosa    |");
      break;
        case 6:
        printf("\n||===== ");
        printf("\n||    | ");
        printf("\n||      ");
        printf("\n||      ");
        printf("\n||      ");
        printf("\n||      ");
        break;
        case 5:
            printf("\n||===== ");
            printf("\n||    | ");
            printf("\n||    O ");
            printf("\n||      ");
            printf("\n||      ");
            printf("\n||      ");
            break;
        case 4:
            printf("\n||===== ");
            printf("\n||    | ");
            printf("\n||    O ");
            printf("\n||    | ");
            printf("\n||      ");
            printf("\n||      ");
            break;
        case 3:
            printf("\n||===== ");
            printf("\n||    | ");
            printf("\n||    O ");
            printf("\n||   /| ");
            printf("\n||      ");
            printf("\n||      ");
            break;
        case 2:
            printf("\n||===== ");
            printf("\n||    | ");
            printf("\n||    O ");
            printf("\n||   /|\\ ");
            printf("\n||      ");
            printf("\n||      ");
            break;
        case 1:
            printf("\n||===== ");
            printf("\n||    | ");
            printf("\n||    O ");
            printf("\n||   /|\\ ");
            printf("\n||   /  ");
            printf("\n||      ");
            break;
        case 0:
            printf("\n||===== ");
            printf("\n||    | ");
            printf("\n||    O ");
            printf("\n||   /|\\ ");
            printf("\n||   / \\ ");
            printf("\n||      ");
            break;
    }
    printf("\n");
}
