#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>      // std::setprecision



using namespace std;

struct Item {
   int value;
   int weight;
};

class Solution
{
    public:
    bool static comp(Item a, Item b) {
        double r1 = (double) a.value / (double)a.weight;
        double r2 = (double) b.value / (double)b.weight;
        return r1 > r2;
    }
    double fractionalKnapsack( int W, Item arr[], int n) {

        sort(arr, arr + n, comp);
        double finalvalue = 0.0;
        int currWeight = 0;


        for (int i =0; i < n;i++) {
            if (currWeight + arr[i].weight <= W) {
                currWeight += arr[i].weight;
                finalvalue += arr[i].value;
            } else {
                int remain = W - currWeight;
                finalvalue += ((double)arr[i].value / (double)arr[i].weight) * remain;
            }
        }

        return finalvalue;
    }
};

int main() {
   const int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}