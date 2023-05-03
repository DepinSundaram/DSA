#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

vector<int> nextGreaterElements(int arr[], int size) {
    vector<int> res(6, -1);
    stack<int> st;
    for (int i = size-1; i >= 0 ; --i) {
        if (st.empty()) {
            res[i] = -1;
        } else {
            while (!st.empty() && st.top() < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            }
        }
        st.push(arr[i]);
    }
    return res;
}
/*
Time Complexity: O(N)

Space Complexity: O(N)
*/
vector<int> nextGreaterElementsCircular(int arr[], int size) {
    vector<int> res(6, -1);
    stack<int> st;
    for (int i = 2*size-1; i >= 0 ; --i) {
        if (st.empty()) {
            res[i] = -1;
        } else {
            while (!st.empty() && st.top() <= arr[i%size]) {
                st.pop();
            }
            if (i < size && !st.empty()) {
                res[i] = st.top();
            }
        }
        st.push(arr[i%size]);
    }
    return res;
}
int main () {

    int arr[] = {5,7,1,2,6,0};
    vector < int > res = nextGreaterElementsCircular(arr, 6);
    for (auto r : res) {
        std::cout << r << " ";
    }


}