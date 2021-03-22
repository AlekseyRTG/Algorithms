#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, max = 0;
    cin >> n;
    stack<int> balls;
    for (int i = 0; i < n; i++) {
        int currentBall;
        cin >> currentBall;
        if (currentBall > max) {
            for (int j = max + 1; j <= currentBall - 1; j++) balls.push(j);
            max = currentBall;
        } else {
            if (currentBall == balls.top()) balls.pop();
            else {
                cout << "Cheater" << endl;
                return 0;
            }
        }
    }
    cout << "Not a proof" << endl;
    return 0;
}
