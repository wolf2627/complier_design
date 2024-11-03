#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SYMBOLS 100

typedef struct
{
    char name[50];
    char type[20];
    char value[50];
} Symbol;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

int isDelimiter(char ch)
{
    return (ch == ' ' || ch == ',' || ch == ';' || ch == '(' ||
            ch == ')' || ch == '[' || ch == ']' || ch == '{' ||
            ch == '}' || ch == '<' || ch == '>' || ch == '+' ||
            ch == '-' || ch == '*' || ch == '/' || ch == '=');
}

int isKeyword(char *str)
{
    char *keywords[] = {"int", "float", "return", "if", "else",
                        "while", "do", "break", "continue",
                        "char", "double", "for", "void", "switch",
                        "case", "default", "sizeof", "short", "long"};
    int n_keywords = sizeof(keywords) / sizeof(char *);
    int i;
    for (i = 0; i < n_keywords; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int isInteger(char *str)
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

int isFloat(char *str)
{
    int hasDecimal = 0;
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
        {
            if (hasDecimal)
                return 0;
            hasDecimal = 1;
        }
        else if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return hasDecimal;
}

int isIdentifier(char *str)
{
    if (!isalpha(str[0]) && str[0] != '_')
    {
        return 0;
    }
    int i;
    for (i = 1; i < strlen(str); i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            return 0;
        }
    }
    return 1;
}

void addSymbol(char *name, char *type, char *value)
{
    if (symbolCount < MAX_SYMBOLS)
    {
        strcpy(symbolTable[symbolCount].name, name);
        strcpy(symbolTable[symbolCount].type, type);
        strcpy(symbolTable[symbolCount].value, value);
        symbolCount++;
    }
    else
    {
        printf("Error: Symbol table is full.\n");
    }
}

void printSymbolTable()
{
    printf("\nSymbol Table:\n");
    printf("Name\t\tType\t\tValue\n");
    int i;
    for (i = 0; i < symbolCount; i++)
    {
        printf("%s\t\t%s\t\t%s\n", symbolTable[i].name, symbolTable[i].type,
               symbolTable[i].value);
    }
}

void printTokenType(char *token)
{
    if (isKeyword(token))
    {
        printf("%s : Keyword\n", token);
    }
    else if (isInteger(token))
    {
        printf("%s : Integer\n", token);
        addSymbol(token, "Integer", token);
    }
    else if (isFloat(token))
    {
        printf("%s : Floating-point number\n", token);
        addSymbol(token, "Float", token);
    }
    else if (isIdentifier(token))
    {
        printf("%s : Identifier\n", token);
        addSymbol(token, "Identifier", "undefined");
    }
    else
    {
        printf(" %s : Symbol\n", token);
    }
}

int main()
{
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        printTokenType(token);
        token = strtok(NULL, " ");
    }
    printSymbolTable();
    return 0;
}