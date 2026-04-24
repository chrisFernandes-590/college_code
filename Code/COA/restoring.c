#include <stdio.h>
#include <stdlib.h>

#define BITS 5 // Number of bits for dividend/divisor

// Function to print binary representation
void print_binary(int num, int bits)
{
    for (int i = bits - 1; i >= 0; i--)
        printf("%d", (num >> i) & 1);
    printf("\n");
}

int main()
{
    int dividend, divisor;
    int A = 0, Q, M;
    int count = BITS;

    printf("Enter dividend (positive integer): ");
    scanf("%d", &dividend);
    printf("Enter divisor (positive integer): ");
    scanf("%d", &divisor);

    if (divisor == 0)
    {
        printf("Error: Division by zero is undefined.\n");
        return 1;
    }

    Q = dividend;
    M = divisor;

    printf("\nInitial Values:\n");
    printf("A = ");
    print_binary(A, BITS + 1);
    printf("Q = ");
    print_binary(Q, BITS);
    printf("M = ");
    print_binary(M, BITS);
    printf("\n-----------------------------------------------\n");

    while (count--)
    {
        printf("Step %d:\n", BITS - count);

        // Left shift A and Q
        A = (A << 1) | ((Q >> (BITS - 1)) & 1);
        Q = (Q << 1) & ((1 << BITS) - 1);

        printf("After left shift -> A: ");
        print_binary(A, BITS + 1);
        printf("Q: ");
        print_binary(Q, BITS);

        // Subtract M
        A = A - M;
        printf("\nA = A - M -> ");
        print_binary(A, BITS + 1);
        printf("Decimal A: %d\n", A);

        // If A < 0, restore and set Q0 = 0
        if (A < 0)
        {
            A = A + M;
            Q = Q & (~1);
            printf("A < 0 → Restore A, Q0 = 0\n");
        }
        else
        {
            Q = Q | 1;
            printf("A ≥ 0 → Keep A, Q0 = 1\n");
        }

        printf("Updated A: ");
        print_binary(A, BITS + 1);
        printf("Updated Q: ");
        print_binary(Q, BITS);
        printf("\n-----------------------------------------------\n");
    }

    printf("\nFinal Result:\n");
    printf("Quotient (Q) = %d\t", Q);
    printf("Binary: ");
    print_binary(Q, BITS);

    printf("\nRemainder (A) = %d\t", A);
    printf("Binary: ");
    print_binary(A, BITS + 1);
    printf("\n");

    return 0;
}