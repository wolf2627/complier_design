#include <stdio.h>
#include <ctype.h>
#include <string.h>
struct instruction
{
    char op[2];
    char arg1[10];
    char arg2[10];
    char result[10];
};
int main()
{
    int n, i;
    struct instruction inst[10];
    char reg[5][5] = {"AX", "BX", "CX", "DX", "EX"};
    int r = 0;
    printf("Enter number of code instructions: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter instruction %d : ", i + 1);
        scanf("%s = %s %s %s", inst[i].result, inst[i].arg1, inst[i].op, inst[i].arg2);
    }
    printf("\nGenerated Assembly Code:\n");
    for (i = 0; i < n; i++)
    {
        if (isalpha(inst[i].arg1[0]))
        {
            printf("MOV %s, %s\n", reg[r], inst[i].arg1);
        }
        else
        {
            printf("MOV %s, %s\n", reg[r], inst[i].arg1);
        }
        if (strcmp(inst[i].op, "+") == 0)
        {
            printf("ADD %s, %s\n", reg[r], inst[i].arg2);
        }
        else if (strcmp(inst[i].op, "-") == 0)
        {
            printf("SUB %s, %s\n", reg[r], inst[i].arg2);
        }
        else if (strcmp(inst[i].op, "*") == 0)
        {
            printf("MUL %s, %s\n", reg[r], inst[i].arg2);
        }
        else if (strcmp(inst[i].op, "/") == 0)
        {
            printf("DIV %s, %s\n", reg[r], inst[i].arg2);
        }
        printf("MOV %s, %s\n", inst[i].result, reg[r]);
        r = (r + 1) % 5;
    }
    return 0;
}