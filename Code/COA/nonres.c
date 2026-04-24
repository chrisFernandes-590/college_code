#include <stdio.h>
#include <stdlib.h>

#define BITS 5 // Number of bits for Q and M

// Print binary representation
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

    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);

    if (divisor == 0)
    {
        printf("Error: Division by zero.\n");
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
    printf("----------------------------------------------\n");

    while (count--)
    {
        printf("Step %d:\n", BITS - count);

        // SHIFT LEFT A and Q
        A = (A << 1) | ((Q >> (BITS - 1)) & 1);
        Q = (Q << 1) & ((1 << BITS) - 1);

        printf("After Left Shift -> A: ");
        print_binary(A, BITS + 1);
        printf("Q: ");
        print_binary(Q, BITS);

        // NON-RESTORING RULE
        if (A >= 0)
        {
            A = A - M;
            printf("A >= 0 -> A = A - M: ");
        }
        else
        {
            A = A + M;
            printf("A < 0 -> A = A + M: ");
        }
        print_binary(A, BITS + 1);

        // Set Q0
        if (A >= 0)
        {
            Q |= 1; // Q0 = 1
            printf("A >= 0 => Q0 = 1\n");
        }
        else
        {
            Q &= (~1); // Q0 = 0
            printf("A < 0 => Q0 = 0\n");
        }

        printf("Updated A: ");
        print_binary(A, BITS + 1);
        printf("Updated Q: ");
        print_binary(Q, BITS);
        printf("----------------------------------------------\n");
    }

    // FINAL CORRECTION
    if (A < 0)
    {
        A = A + M;
        printf("Final Correction: A was negative => A = A + M\n");
    }

    printf("\nFinal Result:\n");
    printf("Quotient (Q) = %d\tBinary: ", Q);
    print_binary(Q, BITS);

    printf("Remainder (A) = %d\tBinary: ", A);
    print_binary(A, BITS + 1);

    return 0;
}
