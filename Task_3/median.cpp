#include "median.h"
#include <algorithm>
#include <cmath>

int medianOfThree(int a, int b, int c) {
    QVector<int> temp{a, b, c};
    std::sort(temp.begin(), temp.end());
    return temp[1];
}

QVector<int> computeMedians(const QVector<int> &arr) {
    QVector<int> result;
    int n = arr.size();
    for (int i = 0; i < n; i += 3) {
        if (i + 2 < n) {
            result.append(medianOfThree(arr[i], arr[i+1], arr[i+2]));
        } else {
            int sum = 0;
            int count = 0;
            for (int j = i; j < n; ++j) {
                sum += arr[j];
                ++count;
            }
            result.append(std::round((double)sum / count));
        }
    }
    return result;
}
