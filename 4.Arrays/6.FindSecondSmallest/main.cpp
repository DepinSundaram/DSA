#include <iostream>
using namespace std;

/*
Time Complexity: O(N), Single-pass solution

Space Complexity: O(1)


for N2 find large and smallest in one itr
and then in second itr find next small /large
*/
int secondSmallest(int arr[], int size) {
    int small = INT_MAX;
    int second_small = INT_MAX;

    for (int i = 0; i < size ; i++) {
        if (arr[i] < small) {
            second_small = small; // 4
            small = arr[i]; // 1
        }
        else if (arr[i] < second_small && arr[i] !=small) {
            second_small = arr[i]; // 4
        }
    }
    return second_small;
}


int secondLargest(int arr[], int size) {
    int large = INT_MIN;
    int second_large = INT_MIN;
    for (int i = 0; i < size ; i++) {
        if (arr[i] > large) {
            second_large = large;
            large = arr[i];
        } else if (arr[i] > second_large && arr[i] !=large) {
            second_large = arr[i];
        }
    }
    return second_large;
}

int main() {
    int arr[]={1,4,2,7,7,5};  
    int n = sizeof(arr)/sizeof(arr[0]);
    int sS=secondSmallest(arr,n);
    int sL=secondLargest(arr,n);
    cout<<"Second smallest is "<<sS<<endl;
    cout<<"Second largest is "<<sL<<endl;
    return 0;
}