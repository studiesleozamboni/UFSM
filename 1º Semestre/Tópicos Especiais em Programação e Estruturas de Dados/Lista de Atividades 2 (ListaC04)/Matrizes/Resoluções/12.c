#include <stdio.h>
#include <stdlib.h>

void twelve_calc(int **matrix) {
    int total = 0;

    for (int line = 0; line < 3; line++) {
        for (int column = 0; column < 3; column++) {
                total += matrix[line][column];
        }
    }

    for(int pline = 0; pline < 3; pline++) {
        for (int pcolumn = 0; pcolumn < 3; pcolumn++) {
            //printf("%d ", matrix[pline][pcolumn]); // subscribed
            printf("%d ", *(*(matrix + pline) + pcolumn)); // pointer
        }
        printf("\n");
    }

    puts("\ntransposed:\n");

    int pline2 = 0;
    for (int pcolumn2 = 0; pcolumn2 < 3; pcolumn2++) {
        //printf("%d ", matrix[pline][pcolumn]); // subscribed
        printf("%d ", *(*(matrix + pline2) + pcolumn2)); // pointer
        printf("%d ", matrix[1][pcolumn2]);
        printf("%d", matrix[2][pcolumn2]);
        printf("\n");
    }

    printf("The total of the transpose is: %d\n", total);
    system("pause");
}

void main() {
    int **m;

    m = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; ++i) {
        m[i] = malloc(3 * sizeof(int));
    }

    for (int line = 0; line < 3; line++) {
        for (int column = 0; column < 3; column++) {
            printf("line %d column %d:\n", line + 1, column + 1);
            scanf("%d", &m[line][column]);
        }
        system("cls");
    }

    twelve_calc(m);
}
