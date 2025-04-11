#include "sort.h"

void interpolationSort(QVector<int>& arr, QTextBrowser* browser) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int left = 0, right = i - 1;

        while (left <= right && arr[left] != arr[right]) {
            int pos = left + ((double)(key - arr[left]) / (arr[right] - arr[left])) * (right - left);
            if (pos < left) pos = left;
            if (pos > right) pos = right;

            if (arr[pos] < key) left = pos + 1;
            else right = pos - 1;
        }

        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;

        QString line;
        for (int val : arr) line += QString::number(val) + " ";
        browser->append("Шаг " + QString::number(i) + ": " + line);
    }
}

int interpolationSearch(const QVector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (arr[high] == arr[low]) break;
        int pos = low + ((double)(x - arr[low]) / (arr[high] - arr[low])) * (high - low);
        if (pos < low) pos = low;
        if (pos > high) pos = high;

        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    if (arr[low] == x) return low;
    return -1;
}
