#include <iostream>
#include <vector>

using namespace std;
struct Job
{

    int id;
    int dead;
    int profit;
};


class Solution
{
    public:
    bool static comp(Job a, Job b) {
        return a.profit > b.profit;
    }

    std::pair<int, int> JobScheduling(Job arr[], int size) {
        sort(arr, arr + size, comp);

        int maxi = arr[0].dead;
        for (int i = 1; i < size; i++) {
            maxi = max(maxi, arr[i].dead);
        }

        int slot[maxi + 1];
        for (int i = 0; i < maxi; i++) {
            slot[i] = -1;
        }

        int countJobs = 0, jobProfit = 0;

        for (int i = 0; i < size ; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        return make_pair (countJobs, jobProfit);

    }
};


int main() {

    const int n =4;
    Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;}