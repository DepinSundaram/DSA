#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int LongestSubstring(string S)
{
    int size = S.size();


    int res = INT_MIN;
    int start = 0, end = 0;
    map<int, int> mpp;

    while (end < size) {
        if (!mpp.count(S[end])) {
            mpp[S[end]] = end;
        } else {
            start = max(mpp[S[end]] + 1, start);
            mpp[S[end]] = end;
        }
        if ((end - start + 1) > res) {
            res = end - start + 1;
        }
        end++;
    }
    std::cout << S.substr(start, end);
    return res;
}

    int longestKSubstr(string s, int k) {
    // your code here
    
        int size = s.size();
        int fq = 0;
        int res = INT_MIN;
        
        int start = 0;
        int end = 0;
        vector<int> mpp{256, 0};
        while (end < size) {
            if (mpp[s[end]] == 0) {
                fq++;
            }
            
            if ( fq > k && start < size) {
                while(fq > k) {
                    mpp[s[start]]--;
                    if (mpp[s[start]] == 0) {
                        fq--;
                    }
                    start++;
                }        
            }
            if (fq == k) {
                res = max (end - start + 1, res);
            }
            mpp[s[end]]++;
            end++;
        }
        
        if (res == INT_MIN) {
            return -1;
        }
       return res;
    }


int main()
{
    std::string str = "vsrt";
    cout << longestKSubstr(str, 2);
}