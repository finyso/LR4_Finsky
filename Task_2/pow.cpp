#include "pow.h"

int binpow(int digit, int power) {
    int result = 1;
    while (power > 0) {
        if (power % 2 == 1)
            result = result * digit;
        digit = digit * digit;
        power /= 2;
    }
    return result;
}
