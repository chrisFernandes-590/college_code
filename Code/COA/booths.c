#include <stdio.h>

// Print 16-bit binary
void printBinary(int num)
{
    for (int i = 15; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to get 2's complement of a number for given bit width
int twosComplement(int num, int bits)
{
    return (~num + 1) & ((1 << bits) - 1);
}

int main()
{
    int M, Q;
    printf("Enter multiplicand: ");
    scanf("%d", &M);
    printf("Enter multiplier: ");
    scanf("%d", &Q);

    int bits = 8; // number of bits for A and Q
    int A = 0;    // Accumulator
    int Qm1 = 0;  // Q-1
    int count = bits;

    // If multiplier is negative, take 2's complement
    int multiplier = Q;
    if (Q < 0)
    {
        multiplier = twosComplement(-Q, bits);
    }

    int multiplicand = M;  // keep M as is
    int Qreg = multiplier; // Q register

    printf("\nInitial Values:\n");
    printf("A = ");
    printBinary(A);
    printf("Q = ");
    printBinary(Qreg);
    printf("Q-1 = %d\n", Qm1);
    printf("-------------------------------------------\n");

    while (count--)
    {
        int Q0 = Qreg & 1;

        printf("Step %d:\n", bits - count);
        printf("Q0 = %d, Q-1 = %d ", Q0, Qm1);

        // Booth decision
        if (Q0 == 0 && Qm1 == 1)
        {
            printf("A = A + M\n");
            A = A + multiplicand;
        }
        else if (Q0 == 1 && Qm1 == 0)
        {
            printf("A = A - M\n");
            A = A - multiplicand;
        }
        else
        {
            printf("No Operation\n");
        }

        printf("Before Shift:\n");
        printf("A = ");
        printBinary(A);
        printf("Q = ");
        printBinary(Qreg);
        printf("Q-1 = %d\n", Qm1);

        // Arithmetic right shift
        int temp = A;
        A = A >> 1;
        Qm1 = Qreg & 1;
        Qreg = (Qreg >> 1) | ((temp & 1) << (bits - 1));

        printf("After Shift:\n");
        printf("A = ");
        printBinary(A);
        printf("Q = ");
        printBinary(Qreg);
        printf("Q-1 = %d\n", Qm1);
        printf("-------------------------------------------\n");
    }

    // Combine A and Qreg for final product
    int product = (A << bits) | Qreg;

    printf("\nFinal Result:\n");
    printf("Result in Decimal: %d\n", product);
    printf("Result in Binary : ");
    printBinary(product);
    return 0;
}