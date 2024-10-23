#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define the structure to hold an operation
struct st {
    char op, op1[3], op2[3], op3;
};

void main() {
    int i, j, d, k = 0, n, l;
    char cc;
    struct st t[10];  // Correct declaration of array of structs

    printf("Enter number of codes: ");
    scanf("%d", &n);

    // Input for operations
    for (i = 0; i < n; i++) {
        printf("Enter operation %d: ", i + 1);
        scanf(" %c %s %s %c", &t[i].op3, t[i].op1, t[i].op2, &t[i].op);
    }

    // Process the operations
    for (i = 0; i < n; i++) {
        if (t[i].op1[0] == '#' && t[i].op2[0] == '#') {
            cc = t[i].op3;
            
            // Perform the operation based on the operator
            if (t[i].op == '+') {
                d = (t[i].op1[1] - '0') + (t[i].op2[1] - '0');  // Convert char to int
            }
            else if (t[i].op == '-') {
                d = (t[i].op1[1] - '0') - (t[i].op2[1] - '0');
            }

            // Replace the computed result in the subsequent operations
            for (k = i + 1; k < n; k++) {
                if (t[k].op1[0] == cc) {
                    t[k].op1[0] = '#';
                    t[k].op1[1] = d + '0';  // Convert int to char
                    t[k].op1[2] = '\0';     // Terminate string
                }
                if (t[k].op2[0] == cc) {
                    t[k].op2[0] = '#';
                    t[k].op2[1] = d + '0';
                    t[k].op2[2] = '\0';
                }
            }

            // Shift the operations after i
            --n;  // Reduce the number of operations
            for (k = i; k < n; k++) {
                t[k] = t[k + 1];  // Shift the structure entries
            }
            i--;  // Reprocess the same index
        }
    }

    // Output the final list of operations
    for (i = 0; i < n; i++) {
        printf("\n%c %s %s %c", t[i].op3, t[i].op1, t[i].op2, t[i].op);
    }
}
