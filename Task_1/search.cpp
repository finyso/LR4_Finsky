#include "search.h"

int binsearch(int* arr, int size, int digit) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == digit) return mid + 1;
        if (arr[mid] < digit) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
