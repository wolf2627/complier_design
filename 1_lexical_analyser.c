#include<stdio.h>
#include<string.h>
#include<ctype.h>

int i, f;

void main() {
    int k = 0, k1 = 0, k2 = 0, k3 = 0, k4 = 0, cno = 0;
    int line1 = 1;
    char a[100], c, b[100], ch;
    char key[50][50], op[10][10], p[10][10];
    char var[10][10], con[10][10];
    int keyline[50], opline[50], pline[50];
    int varline[50], conline[50];
    int kflag = 0;
    FILE *fp1, *fp;
    
    // Open file for writing tokens
    fp = fopen("token1.txt", "w");
    
    // Input characters until '$' is encountered
    c = getchar();
    while (c != '$') {
        putc(c, fp);
        c = getchar();
    }
    
    fclose(fp);
    
    // Open file for reading tokens
    fp1 = fopen("token1.txt", "r");
    
    // Lexical analysis starts here
    while (1) {
        ch = fgetc(fp1);
        if (ch == EOF)
            break;
        
        a[cno] = ch;
        cno++;
        
        if (ch == ' ' || ch == '\n') {
            kflag = 0;
            a[cno - 1] = '\0';
            cno = 0;
            
            // Check for operators
            if (strncmp(a, "<", 1) == 0 || strncmp(a, ">", 1) == 0 || strncmp(a, "<=", 2) == 0 || 
                strncmp(a, ">=", 2) == 0 || strncmp(a, "=", 1) == 0 || strncmp(a, "!=", 2) == 0 || 
                strncmp(a, "&&", 2) == 0 || strncmp(a, "||", 2) == 0) {
                
                strcpy(op[k], a);
                opline[k] = line1;
                k++;
            }
            
            // Check for keywords
            if (strncmp(a, "void", 4) == 0 || strncmp(a, "main", 4) == 0 || strncmp(a, "printf", 6) == 0 ||
                strncmp(a, "scanf", 5) == 0 || strncmp(a, "if", 2) == 0 || strncmp(a, "else", 4) == 0 || 
                strncmp(a, "while", 5) == 0 || strncmp(a, "for", 3) == 0 || strncmp(a, "int", 3) == 0 || 
                strncmp(a, "char", 4) == 0 || strncmp(a, "float", 4) == 0) {
                
                strcpy(key[k1], a);
                keyline[k1] = line1;
                k1++;
                kflag = 1;
            }
            
            // Check for punctuations
            if (strncmp(a, "(", 1) == 0 || strncmp(a, ")", 1) == 0 || strncmp(a, "{", 1) == 0 || 
                strncmp(a, "}", 1) == 0 || strncmp(a, ",", 1) == 0 || strncmp(a, ";", 1) == 0) {
                
                strcpy(p[k2], a);
                pline[k2] = line1;
                k2++;
            }
            
            // Check for constants
            if (isdigit(a[0])) {
                strcpy(con[k4], a);
                conline[k4] = line1;
                k4++;
            }
            
            // Check for variables
            if (isalpha(a[0]) && (kflag == 0)) {
                strcpy(var[k3], a);
                varline[k3] = line1;
                k3++;
            }
        }
        
        // Increment line number on encountering new line
        if (ch == '\n')
            line1++;
    }
    
    fclose(fp1);
    
    // Output analysis results
    printf("\nThe keywords are:\n");
    for (i = 0; i < k1; i++)
        printf("%d\t%s\n", keyline[i], key[i]);
    
    printf("\nOperators are:\n");
    for (i = 0; i < k; i++)
        printf("%d\t%s\n", opline[i], op[i]);
    
    printf("\nPunctuations are:\n");
    for (i = 0; i < k2; i++)
        printf("%d\t%s\n", pline[i], p[i]);
    
    printf("\nVariables are:\n");
    for (i = 0; i < k3; i++)
        printf("%d\t%s\n", varline[i], var[i]);
    
    printf("\nConstants are:\n");
    for (i = 0; i < k4; i++)
        printf("%d\t%s\n", conline[i], con[i]);
}
