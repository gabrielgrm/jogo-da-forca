# Jogo da Forca

## Apresentação do Jogo

O Jogo da Forca é um clássico jogo de adivinhação de palavras em que o jogador tenta adivinhar uma palavra oculta, revelando letras uma de cada vez. O jogador tem um número limitado de tentativas erradas antes de perder o jogo.

Este jogo da forca foi desenvolvido em C e apresenta várias categorias de palavras para escolher. O jogador deve adivinhar a palavra escolhida aleatoriamente da categoria selecionada.

## Instruções de Compilação e Uso

Siga estas instruções para compilar e executar o jogo:

1. Certifique-se de ter sistema Linux ou MacOS com um compilador GCC instalado em seu sistema.

2. Baixe os arquivos `main.c`, `keyboard.c`, `keyboard.h` e os arquivos de texto com as palavras para as categorias (por exemplo, `animais.txt`, `famosos.txt`, etc.) no mesmo diretório.

3. Abra um terminal e navegue até o diretório onde os arquivos estão localizados.

4. Compile o jogo usando o seguinte comando:

    ```bash
    gcc main.c keyboard.c -o jogo_da_forca
    ```

    Isso criará um arquivo executável chamado `jogo_da_forca`.

5. Execute o jogo com o seguinte comando:

    ```bash
    ./jogo_da_forca
    ```

6. Siga as instruções na tela para escolher uma categoria e jogar o Jogo da Forca.

## Detalhes de Implementação

O código do Jogo da Forca é implementado em linguagem C e utiliza uma lista encadeada para rastrear letras já tentadas.

- O jogo permite que o jogador escolha entre várias categorias de palavras.

- A palavra a ser adivinhada é escolhida aleatoriamente da categoria selecionada.

- As letras já tentadas são exibidas na tela para que o jogador não tente a mesma letra novamente.
  
- O jogo verifica se a letra já foi tentada e se a letra está na palavra a ser adivinhada.

## Dificuldades Encontradas

Durante o desenvolvimento do jogo, algumas das principais dificuldades encontradas incluíram:

- Lidar com a entrada do teclado e controlar a leitura de teclas sem esperar por Enter.

- Implementar a lógica de escolher palavras aleatórias de diferentes categorias.

- Gerenciar corretamente a alocação e liberação de memória para evitar vazamentos de memória.

- Exibir gráficos de representação da forca de forma adequada.

- Tratar casos de entrada inválida.

  > Caso não possua um sistema Linux ou MacOs, poderá utilizar um ambiente online como o replit.com e adicionar os arquivos no ambiente e executar a forca

Divirta-se jogando o Jogo da Forca e não deixe de dar feedback sobre sua experiência! Se tiver sugestões ou melhorias, estamos abertos a ouvi-las.

Aproveite o jogo e boa sorte!
<br>

```
Antonio Valença                               Gabriel Rodrigues                              Mirna Lustosa
```
