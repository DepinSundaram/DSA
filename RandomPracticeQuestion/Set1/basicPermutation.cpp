#include <iostream>
#include <vector>

using namespace std;


void RecurPermute(vector<int>& num, vector<vector<int>>& res, vector<int>& ds, vector<int>& freq ) {
    if (ds.size() == num.size()) {
        res.push_back(ds);
        return;
    }

    for (int i = 0; i < num.size(); i++) {
        if (freq[i] == 0) {
            freq[i] = 1;
            ds.push_back(num[i]);
            RecurPermute(num, res, ds, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

std::string KthPermutation(vector<int>& num, int k) {
    int fact = 1;
    int size = num.size();
    for (int i =1; i < size; i++) {
        fact = fact* i;
    }

    k = k - 1;
    string ans{};
    while (true) {
        ans = ans + to_string(num[k / fact]);

        num.erase(num.begin() + k / fact);
        if (num.size() == 0)  break;
        k = k % fact;

        fact = fact / num.size();
    }

    return ans;
}

void Optimized(int idx, vector<vector<int>>& res, vector<int>& num)
{
    if (idx == num.size()) {
        res.push_back(num);
        return;
    }    

    for (int i = idx; i < num.size(); i++) {
        swap(num[i], num[idx]);
        Optimized(idx + 1, res, num);
        swap(num[i], num[idx]);
    }
}
vector<vector<int>> permute(vector<int>& num)
{
    int s = num.size();
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(s, 0);
    RecurPermute(num, ans, ds, freq);
    return ans;
}


int main() 
{
    std::vector<int> arr {1, 2, 3, 4};
    
    auto sum = permute(arr);

      cout << "All Permutations are " << endl;
  for (int i = 0; i < sum.size(); i++) {
    for (int j = 0; j < sum[i].size(); j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }

  std::cout << KthPermutation(arr, 17);
}