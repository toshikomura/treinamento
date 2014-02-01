#include<stdio.h>
#include<stdlib.h>

void preenche_matriz ( int **matriz, int linhas, int colunas) {

    int i, j;

    printf ("preencher matriz\n");

    for ( i = 0; i < linhas; i++) {
        for ( j = 0; j < colunas; j++) {
            printf ("Digite o valor de %d %d\n", i, j);
            scanf ("%d", &matriz[i][j]);
        }
    }

}

int **criar_matriz ( int linhas, int colunas) {

    int **matriz;
    int i, j;

    matriz = malloc(sizeof (int ) * linhas);

    for ( i = 0; i < linhas; i++)
        matriz[i] = malloc (sizeof (int) * colunas);

    return matriz;

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

void editar_matriz ( int **matriz, int linhas, int colunas) {

    int l, c, novo_valor;

    printf ("Editar matriz\n");
    printf ("Digite a linha para editar\n");
    scanf ("%d", &l);
    printf ("Digite a coluna para editar\n");
    scanf ("%d", &c);
    printf ("Valor de %d %d é %d\n", l, c, matriz[l][c]);
    printf ("Digite o novo valor de %d %d\n", l, c);
    scanf ("%d", &matriz[l][c]);

    printf ("Edição completa\n");
}

int **calcular_transposta ( int **matriz, int linhas, int colunas) {

    int **matriz_transposta;
    int i, j;

    matriz_transposta = criar_matriz ( linhas, colunas);

    printf ("tranformando matriz\n");

    for ( i = 0; i < linhas; i++) {
        for ( j = 0; j < colunas; j++) {
            matriz_transposta[i][j] = matriz[j][i];
            printf ("mt %d m %d", matriz_transposta[i][j], matriz[j][i]);
        }
    }

    return matriz_transposta;
}

void imprime_matriz ( int **matriz, int linhas, int colunas) {

    int i, j;

    printf ("Imprimindo matriz\n");
    printf ("Endereço matriz %p\n", matriz);
    for ( i = 0; i < linhas; i++) {
        printf ("|");
        for ( j = 0; j < colunas; j++) {
            printf ("| %d %p |", matriz[i][j], &matriz[i][j]);
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

            case 1: matriz = criar_matriz( linhas, colunas);
                    preenche_matriz ( matriz, linhas, colunas);
                    break;

            case 2: editar_matriz( matriz, linhas, colunas);
                   break;

            case 3: matriz = calcular_transposta( matriz, linhas, colunas);
                   break;

            case 4: imprime_matriz( matriz, linhas, colunas);
                    break;

            default: printf ("'%d' não existe nas opções\n", escolha);
                    break;

        }
    }
}
