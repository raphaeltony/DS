#include <stdio.h>
#define MAX 10

void printSparse(int a[][3]) {
    int m = a[0][0];
    int n = a[0][1];
    int i, j, k;
    printf("\nFinal Matrix : \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int found = 0;
            for (k = 1; k <= a[0][2]; k++) {
                if (i == a[k][0] && j == a[k][1]) {
                    printf("%d ", a[k][2]);
                    found = 1;
                    break;
                }
            }
            if (!found) printf("0 ");
        }
        printf("\n");
    }
}

void transpose(int a[][3]) {
    int b[MAX][3];
    int n = a[0][2];
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];

    if (n > 0) {
        int i, j, k = 1;
        for (i = 0; i < a[0][1]; i++) {
            for (j = 1; j <= n; j++) {
                if (a[j][1] == i) {
                    b[k][0] = a[j][1];
                    b[k][1] = a[j][0];
                    b[k][2] = a[j][2];
                    k++;
                }
            }
        }
        printSparse(b);
    }
}

void addition(int a[][3], int b[][3]) {
    int i = 1, j = 1, k = 1, z;
    int c[MAX][3];

    if ((a[0][0] == b[0][0]) && a[0][1] == b[0][1]) {
        c[0][0] = a[0][0];
        c[0][1] = a[0][1];

        while (i <= a[0][2] && j <= b[0][2]) {
            if (a[i][0] == b[j][0]) {
                // if both row and column is equal
                if (a[i][1] == b[j][1]) {
                    c[k][0] = a[i][0];
                    c[k][1] = a[i][1];
                    c[k][2] = a[i][2] + b[j][2];
                    i++, j++, k++;
                }
                // if only row is equal
                else {
                    if (a[i][1] < b[j][1]) {
                        for (z = 0; z < 3; z++) {
                            c[k][z] = a[i][z];
                        }
                        i++, k++;
                    } else {
                        for (z = 0; z < 3; z++) {
                            c[k][z] = b[j][z];
                        }
                        j++, k++;
                    }
                }
            }
            // row not equal
            else {
                if (a[i][0] < b[j][0]) {
                    for (z = 0; z < 3; z++) {
                        c[k][z] = a[i][z];
                    }
                    i++, k++;
                } else {
                    for (z = 0; z < 3; z++) {
                        c[k][z] = b[j][z];
                    }
                    j++, k++;
                }
            }
        }
        while (i <= a[0][2]) {
            for (z = 0; z < 3; z++) {
                c[k][z] = a[i][z];
            }
            i++, k++;
        }
        while (j <= b[0][2]) {
            for (z = 0; z < 3; z++) {
                c[k][z] = b[j][z];
            }
            j++, k++;
        }
        c[0][2] = --k;
        printSparse(c);
    } else
        printf("\nAddition Not Possible\n");
}

int main() {
    int a[MAX][MAX], m, n, i, j;
    int b[MAX][3];
    int p, q, ele;
    int s[MAX][3];
    char opt;

    do {
        printf("Enter number of rows and columns for 2D matrix :\n");
        scanf("%d%d", &m, &n);
        printf("Enter elements for 2D matrix :\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        // converting to sparse
        s[0][0] = m;
        s[0][1] = n;
        int k = 1;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] != 0) {
                    s[k][0] = i;
                    s[k][1] = j;
                    s[k][2] = a[i][j];
                    k++;
                }
            }
        }
        s[0][2] = --k;

        printf("Enter Option:\n1.Transpose\n2.Add to another matrix\n");
        scanf(" %c", &opt);
        switch (opt) {
            case '1':
                transpose(s);
                break;
            case '2':
                k = 1;
                printf("Enter number of rows and columns for 2D matrix :\n");
                scanf("%d%d", &p, &q);
                b[0][0] = p;
                b[0][1] = q;
                printf("Enter elements for 2D matrix :\n");
                for (i = 0; i < p; i++) {
                    for (j = 0; j < q; j++) {
                        scanf("%d", &ele);
                        if (ele != 0) {
                            b[k][0] = i;
                            b[k][1] = j;
                            b[k][2] = ele;
                            k++;
                        }
                    }
                }
                b[0][2] = --k;
                addition(s, b);
                break;

            default:
                break;
        }
        printf("Would you like to continue? (y/n) : ");
        scanf(" %c", &opt);

    } while (opt == 'y');

    return 0;
}
