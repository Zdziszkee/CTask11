#include <stdio.h>
#include <math.h>

char *decimal_to_binary(unsigned decimal);

char *decimal_to_binary_bitwise(unsigned decimal);


int main() {
    unsigned decimal;
    scanf("%d", &decimal);
    char *binary = decimal_to_binary(decimal);
    char *binaryBitwise = decimal_to_binary_bitwise(decimal);
    return 0;
}


char *decimal_to_binary(unsigned decimal) {
    int power = 1;
    while ((pow(2, power)) < decimal) {
        power++;
    }
    char binary[power];
    for (int i = 0; i < sizeof(binary) / sizeof(binary[0]); ++i) {
        binary[i] = 0;
    }

    for (int i = (power - 1); i >= 0; i--) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
    }
    puts(binary);
    return binary;
}

char *decimal_to_binary_bitwise(unsigned decimal) {
    int power = 1;
    while ((pow(2, power)) < decimal) {
        power++;
    }
    char binary[power];
    for (int i = (power - 1); i >= 0; i--) {
        if ((decimal & 1) == 1) {
            binary[i] = '1';
        } else {
            binary[i] = '0';
        }
        decimal = decimal >> 1;
    }
    puts(binary);
    return binary;
}





