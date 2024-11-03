#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int isDelimiter(char ch)
{
    return (ch == ' ' || ch == ',' || ch == ';' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' ||
            ch == '}' || ch == '<' || ch == '>' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=');
}
int isKeyword(char *str)
{
    char *keywords[] = {"int", "float", "return", "if", "else", "while", "do", "break", "continue",
                        "char", "double", "for", "void", "switch", "case", "default", "sizeof", "short", "long"};
    int n_keywords = sizeof(keywords) / sizeof(char *);
    for (int i = 0; i < n_keywords; i++)
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
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}
int isIdentifier(char *str)
{
    if (!isalpha(str[0]) && str[0] != '_')
    {
        return 0;
    }
    for (int i = 1; i < strlen(str); i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            return 0;
        }
    }
    return 1;
}

int isFloat(char *token)
{
    // Implementation for checking if the token is a float
    // For example:
    char *end;
    strtod(token, &end);
    return *end == '\0'; // Returns true if the entire token is a valid float
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
    }
    else if (isFloat(token))
    {
        printf("%s : Floating-point number\n", token);
    }
    else if (isIdentifier(token))
    {
        printf("%s : Identifier\n", token);
    }
    else
    {
        printf("%s : Symbol\n", token);
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
    return 0;
}