#include <iostream>
#include <vector>

using namespace std;



class Solution
{
    void PalindromicPartition(int idx, string str, vector<string>& path, vector<vector<string>>& res) {
        if (idx == str.size()) {
            res.push_back(path);
            return;
        }

        for (int i = idx ;i < str.size(); ++i) {
            if (IsPalindrome(str, idx, i)) {
                path.push_back(str.substr(idx, i - idx + 1));
                PalindromicPartition(i + 1, str, path, res);
                path.pop_back();
            }
        }
    }

    bool IsPalindrome(string str, int start, int end) {
        std::cout << str.substr(start, end) << std::endl;
        while (start <= end) {
            if (str[start++] != str[end--]) {
                return false;
            }
        }
        return true;

    }
public:
    vector < vector < string > > partition(std::string str) {

        vector<string> path;
        vector< vector <string > > res;
        PalindromicPartition(0, str, path, res);

        return res;
    }
};


int main()
{
    string s = "aabb";
    Solution obj;
    vector < vector < string > > ans = obj.partition(s);
    int n = ans.size();
    cout << "The Palindromic partitions are :-" << endl;
    cout << " [ ";
    for (auto i: ans) {
        cout << "[ ";
        for (auto j: i) {
        cout << j << " ";
        }
        cout << "]\n ";
    }
    cout << "]";

    return 0;
}