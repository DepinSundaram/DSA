// https://www.codingninjas.com/codestudio/problems/count-subsequences_630524?leftPanelTab=2

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;

int MOD = 1e9 + 7;

class CountSub
{
    vector<vector<int>> m_SubSequence;
public:
/*
Brute Force
The idea is to generate all the subsequences and check whether the elements present are equal or not.

 

Here is the algorithm :

 

Generate all the subsequences of the given array.
Maintain a variable ‘COUNT’ which stores the total number of subsequences in which all the elements are equal.
Iterate over each of the generated subsequences.
In case all the elements of the current subsequence are equal, we increment ‘COUNT’.
After, iterating over all the subsequences, the value of ‘COUNT’ is the answer that we are looking for.
Time Complexity
O((2 ^ N) * N), where ‘N’ is the size of the array.

 

Each number has two choices, whether to include it in a subsequence or not.
 There are total ‘N’ numbers present with us, so the total possible combinations will be 2*2*2… (‘N’ times).
 And for every subsequence we check whether all the elements are equal or not by traversing it which can have maximum ‘N’ elements. 
 Therefore, the overall time complexity will be O((2 ^ N) * N).

Space Complexity
O(2 ^ N), where ‘N’ is the size of the array.

 

We use a vector/list to store all the number of subsequences which can be maximum upto 2^N. 
Recursion stack in our algorithm works in a depth - first way, so we cannot have more than ‘N’ 
recursive calls on the stack as the total numbers present can be at max ‘N’. 
Therefore, the overall space complexity will be O(2 ^ N).
*/
    void GenerateAllSubSeq(int arr[], int idx, vector<int>& ds, int N)
    {
        if (idx >= N) {
            m_SubSequence.push_back(ds);

            return;
        }

        ds.push_back(arr[idx]);
        GenerateAllSubSeq(arr, idx + 1, ds, N);
        ds.pop_back();
        GenerateAllSubSeq(arr, idx + 1, ds, N);
    }

    vector<vector<int>> GetSubSeq() const {
        return m_SubSequence;
    }

    long countSubsequences(int* arr, int n) {
        // Write your code here. 

        vector<int> ds;
        GenerateAllSubSeq(arr, 0, ds, n);


        int count = 0;

        auto subse = GetSubSeq();
        for (auto s : subse) {

            if(s.size()) {
                bool isSame = true;
                int element = s[0];

                for (auto i : s) {
                    if (i !=element) {
                        isSame = false;
                        break;
                    } 
                }

                if (isSame) {
                    count++;
                    count = count % MOD;
                }
            }

        }
        return count;
    }
/*

Combinations
In this approach, we will calculate the contribution of each distinct element to the answer. 
For example, if we had ‘k’ occurrences of an element in the array, we will be able to form :

kC1 subsequences of length 1
kC2 subsequences of length 2
kC3 subsequences of length 3
   .

   .

   .

   K.  kCk  subsequences of length k

Hence the contribution of this element to the answer = kC1 + kC2 + kC3 … + kCk = (2^k) - 1

So, the contribution of each distinct element would be equal to (2 ^ FREQ) - 1. Where ‘FREQ’ is the frequency of that element in the array.

 

Here is the algorithm :

 

Store the frequency of each element in a hashmap (say, ‘FREQ’).
Maintain a variable ‘RESULT’ which stores the final answer.
For each element present in the hashmap,
Calculate the value of (2^eleCount - 1) % MOD, ‘eleCount’ is frequency of current element.
Add the above value to ‘RESULT’
The final answer is the value of ‘RESULT’ after we are done iterating over all the elements of the hashmap.
Time Complexity
O(N), where ‘N’ is the size of the array.

 

We are just storing the frequency of each element by iterating on array. After that we are just iterating on map one time in which max elements can be equal to size of array. POWER function runs a loop over a power which can take time maximum upto O(log(pow)) as we are subsequently dividing our power with 2. Hence, the overall time complexity will be O(N).

Space Complexity
O(N), where ‘N’ is the size of the array.

We are storing frequency of each element in map. Maximum elements can be equal to size of array. Hence, the overall space complexity will be O(N).
*/

    long OptimizedCount(int arr[], int n) {
        unordered_map<int, int> mpp;

        for(int i = 0; i < n ; i++) {
            mpp[arr[i]]++;
        }

        long res = 0L;
        for (auto ip : mpp) {
            res += pow(2, ip.second) - 1;
        }

        return res;
    }
};



int main()
{
    CountSub a;
    int A[] = { 1, 2, 3};

    int N = sizeof(A) / sizeof(A[0]);
/*
    vector<int> ds;
   a.GenerateAllSubSeq(A, 0, ds, N);

    auto res = a.GetSubSeq();

    for (const auto ele : res) {
        if (ele.empty()) {
            cout << "{}\n";
        }
        for (auto i : ele) {
            cout << i << " ";
        }
        cout << std::endl;
    }


    std::cout << "Total no of subsq : " << a.GetSubSeq().size() << std::endl;
*/
    std::cout << a.OptimizedCount(A, N);
    return 0;

}