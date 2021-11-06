#include <stdio.h>
#define MAX 10

struct poly
{
    int coeff;
    int exp;
} p1[MAX], p2[MAX];

void getPoly(struct poly p[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient and power of %dth term:", i + 1);
        scanf("%d%d", &p[i].coeff, &p[i].exp);
    }
}

void add(int m, int n)
{
    int i = 0, j = 0, k = 0;
    struct poly sum[2 * MAX];

    while (1)
    {
        if (p1[i].exp > p2[j].exp)
        {
            sum[k] = p1[i];
            i++, k++;
        }
        else if (p1[i].exp < p2[j].exp)
        {
            sum[k] = p2[j];
            j++, k++;
        }
        else
        {
            sum[k].coeff = p1[i].coeff + p2[j].coeff;
            sum[k].exp = p1[i].exp;
            i++, j++, k++;
        }
        //If first poly is over
        if (i >= m)
        {
            //copying second polynomial
            while (j < n)
            {
                sum[k++] = p2[j++];
            }
            break;
        }

        //If second poly is over
        if (j >= n)
        {
            //copying first polynomial
            while (i < m)
            {
                sum[k++] = p2[i++];
            }
            break;
        }
    }

    printf("Final Polynomial : ");
    for (i = 0; i < k; i++)
    {
        printf("%dx^%d  ", sum[i].coeff, sum[i].exp);
    }
}

int main()
{
    int m, n, i, opt;
    char ch;
    do
    {
        printf("How many terms in the first polynomial ? : ");
        scanf("%d", &m);
        printf("Enter terms:\n");
        getPoly(p1, m);

        printf("How many terms in the second polynomial ? : ");
        scanf("%d", &n);
        printf("Enter terms:\n");
        getPoly(p2, n);

        printf("Choose an option :\n1. Add polynomial\n2.Multiply polynomial\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            add(m, n);
            break;
        case 2:
            /* code */
            break;

        default:
            break;
        }
        printf("\nWould you like to continue ? (y/n) : ");
        scanf(" %c", &ch);

    } while (ch == 'y');
    return 0;
}