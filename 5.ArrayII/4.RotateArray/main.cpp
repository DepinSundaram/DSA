#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*

Time Complexity: O(d)+O(n-d)+O(d) = O(n+d), where n = size of the array, d = the number of rotations. Each term represents each loop used in the code.

Space Complexity: O(d) extra space as we are using a temporary array of size d.
*/
void leftRotate(int arr[], int n, int d) {
    if ( n == 0) {
        return;
    }

    d = d % n;

    if (d == 0) {
        return;
    }

// store first d elements
    int temp[d];

    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }
// shift other elements

    for(int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // copy temp to d -> n

    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - (n - d)];
    }

}

/*
Time Complexity: O(d)+O(n-d)+O(n) = O(2*n), where n = size of the array, d = the number of rotations. Each term corresponds to each reversal step.

Space Complexity: O(1) since no extra space is required.
*/
void optimizedRotation(int arr[], int n, int d) {
    if ( n == 0) {
        return;
    }

    d = d % n;

    if (d == 0) {
        return;
    }

    //reverse first part
    std::reverse(arr, arr + d);
    // reserver second part
    std::reverse(arr + d, arr + n);
    // reserver whole arr

    std::reverse(arr, arr + n);
}
int main() {

    int n = 4;

    int d = 1;

    int arr[] = {1, 2, 3, 4};
    int loop = n - 1;
    //while (loop--) {
        optimizedRotation(arr, n, d);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
   // }
}