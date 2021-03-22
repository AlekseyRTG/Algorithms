#include <iostream>
#include <cmath>
#define PI 3.141592653589793238462643383279502884197169399375105820974
using namespace std;

struct Point {
    int x;
    int y;
    int number;
    double angle;
};

void swap(Point* a, Point* b) {
	Point t = *a;
	*a = *b;
	*b = t;
}

void quickSort(Point* array, int left, int right) {
    int i = left, j = right;
    double pivot = array[(left + right) / 2].angle;
    while(i <= j) {
        while (array[i].angle < pivot) i++;
        while (array[j].angle > pivot) j--;
        if (i > j) break;
        swap(&array[i], &array[j]);
        i++;
        j--;
    }
    if (left < j) quickSort(array, left, j);
    if (i < right) quickSort(array, i, right);
}

int main() {
    int n;
    cin >> n;
    Point points[n];
    pair<int, int> minPoint = make_pair(INT_MAX, 0);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].number = i + 1;
        if (points[i].y < minPoint.first || points[i].y == minPoint.first && points[i].x < points[minPoint.second].x) {
            minPoint.first = points[i].y;
            minPoint.second = i;
        }
    }
    swap(&points[0], &points[minPoint.second]);
    for (int i = 1; i < n; i++) {
        if (points[i].x == points[0].x) points[i].angle = PI / 2;
        else if (points[i].y == points[0].y) points[i].angle = 0;
        else points[i].angle = atan((double)(points[i].y - points[0].y) / (double)(points[i].x - points[0].x));
        if (points[i].angle < 0) points[i].angle = points[i].angle + 2 * PI;
    }
    quickSort(points, 1, n - 1);
    cout << points[0].number << " " << points[n / 2].number << endl;
    return 0;
}
