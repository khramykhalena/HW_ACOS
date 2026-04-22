#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int **a = (int **)malloc(N * sizeof(int *));
    int **t = (int **)malloc(M * sizeof(int *));
    if (a == NULL || t == NULL) return 1;

    for (int i = 0; i < N; i++) {
        a[i] = (int *)malloc(M * sizeof(int));
    }

    for (int i = 0; i < M; i++) {
        t[i] = (int *)malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            t[j][i] = a[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", t[i][j]);
            if (j < N - 1) printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) free(a[i]);
    free(a);

    for (int i = 0; i < M; i++) free(t[i]);
    free(t);

    return 0;
}
