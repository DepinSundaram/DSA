#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:

/*

Time Complexity: O(N) * O(N) = O(N^2)

Reason: We are placing N numbers in N positions. This will take O(N) time. For every number,
we are reducing the search space by removing the element already placed in the previous step. This takes another O(N) time.

Space Complexity: O(N) 

Reason: We are storing  the numbers in a data structure(here vector)
*/
    string getPermutation(int n , int k) {
        int fact;
        vector<int> num;
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            num.push_back(i);
        }
        num.push_back(n);

        string ans = "";
        k = k - 1;

        while(true) {
            ans = ans + to_string(num[k/fact]);
            num.erase(num.begin() + k / fact);
            if (num.size() == 0) {
                break;
            }

            k = k % num.size();
            fact = fact / num.size();
        }

        return ans;

    }
};
int main() {
  int n = 3, k = 3;
  Solution obj;
  string ans = obj.getPermutation(n, k);
  cout << "The Kth permutation sequence is " << ans << endl;

  return 0;
}