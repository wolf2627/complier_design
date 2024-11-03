#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct st
{
    char op;
    char op1[3];
    char op2[3];
    char op3;
} t[10];
int main()
{
    int i, d, k = 0, n;
    char cc;
    printf("Enter the number of codes: ");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        printf("Enter operation: ");
        scanf(" %c %s %s %c", &t[i].op3, t[i].op2, t[i].op1, &t[i].op);
    }
    for (i = 0; i < n; i++)
    {
        if (t[i].op1[0] == '#' && t[i].op2[0] == '#')
        {
            cc = t[i].op3;
            if (t[i].op == '+')
            {
                d = (t[i].op1[1] - '0') + (t[i].op2[1] - '0');
            }
            else if (t[i].op == '-')
            {
                d = (t[i].op1[1] - '0') - (t[i].op2[1] - '0');
            }
            for (k = i + 1; k < n; k++)
            {
                if (t[k].op1[0] == cc)
                {
                    t[k].op1[0] = '#';
                    t[k].op1[1] = d + '0';
                }
            }
            for (k = i; k < n - 1; k++)
            {
                t[k] = t[k + 1];
            }
            n--;
            i--;
        }
    }
    printf("\nFinal operations:\n");
    for (i = 0; i < n; i++)
    {
        printf("%c %s %s %c\n", t[i].op3, t[i].op1, t[i].op2, t[i].op);
    }
    return 0;
}