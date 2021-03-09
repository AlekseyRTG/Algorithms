#include <iostream>
using namespace std;

int search(int* array, int size, int i = 0, int sum1 = 0, int sum2 = 0) {
    static int min_ = 100000;
    if (i == size) min_ = min(min_, abs(sum1 - sum2));
    else {
        search(array, size, i + 1, sum1 + array[i], sum2);
        search(array, size, i + 1, sum1, sum2 + array[i]);
    }
    return min_;
}

int main() {
    int n;
    cin >> n;
    int rocks[n];
    for (int i = 0; i < n; i++) cin >> rocks[i];
    cout << search(rocks, n) << endl;
    return 0;
}
