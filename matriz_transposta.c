#include<stdio.h>
#include<stdlib.h>

void criar_matriz ( int ***matriz, int linhas, int colunas) {

    int **matriz_resultante;
    int i, j;

    matriz_resultante = malloc(sizeof (int ) * linhas);

    for ( i = 0; i < linhas; i++)
        matriz_resultante[i] = malloc (sizeof (int) * colunas);

    printf ("preencher matriz\n");

    for ( i = 0; i < linhas; i++) {
        for ( j = 0; j < colunas; j++) {
            printf ("Digite o valor de %d %d\n", i, j);
            scanf ("%d", &matriz_resultante[i][j]);
        }
    }

    *matriz = matriz_resultante;
}

void menu( int *escolha) {
    printf ("\nEscolha uma das seguinte opções\n");
    printf ("Digite 1 para criar a matriz\n");
    printf ("Digite 2 para editar a matriz\n");
    printf ("Digite 3 para calcular a transposta da matriz\n");
    printf ("Digite 4 para imprimir a matriz\n");
    printf ("\nDigite sua escolha\n");
    scanf ("%d", escolha);
}

void editar_matriz ( int ***matriz, int linhas, int colunas) {

    int l, c, novo_valor;

    printf ("Editar matriz\n");
    printf ("Digite a linha para editar\n");
    scanf ("%d", &l);
    printf ("Digite a coluna para editar\n");
    scanf ("%d", &c);
    printf ("Digite o novo valor de %d %d\n", l, c);
    scanf ("%d", matriz[l][c]);
    printf ("Edição completa\n");
}

void imprime_matriz ( int **matriz, int linhas, int colunas) {

    int i, j;

    printf ("Imprimindo matriz\n");

    for ( i = 0; i < linhas; i++) {
        printf ("|");
        for ( j = 0; j < colunas; j++) {
            printf ("| %d |", matriz[i][j]);
        }
        printf ("|\n");
    }

}

main () {

    int **matriz, linhas, colunas;
    int escolha;

    printf ("Digite o tamanho da matriz\n");
    printf ("Digite as linhas\n");
    scanf ("%d", &linhas);
    printf ("Digite as colunas\n");
    scanf ("%d", &colunas);

    while (1) {
        menu(&escolha);
        switch (escolha) {
            case 1: criar_matriz( &matriz, linhas, colunas);
                    break;
            case 2: editar_matriz( &matriz, linhas, colunas);
                    break;
            case 4: imprime_matriz( matriz, linhas, colunas);
                    break;
            default: printf ("'%d' não existe nas opções\n", escolha);
                    break;
        }
    }
}
