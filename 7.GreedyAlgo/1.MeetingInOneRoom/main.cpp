#include <iostream>
#include <vector>

using namespace std;
struct meeting 
{
    int start;
    int end;
    int pos;
};
class Solution
{
public:
    bool static comp(struct meeting m1, struct meeting m2) {
        if (m1.end < m2.end) return true;
        else if (m1.end > m2.end) return false;
        else if (m1.pos < m2.pos) return true;
        return true; 
    }

    /*
    Time Complexity: O(n) to iterate through every position and insert them in a data structure. O(n log n)  to sort the data structure in ascending order of end time. O(n)  to iterate through the positions and check which meeting can be performed.

    Overall : O(n) +O(n log n) + O(n) ~O(n log n)

    Space Complexity: O(n)  since we used an additional data structure for storing the start time, end time, and meeting no.
    */
    void maxMeetings(int start[], int end[], int n) {
        struct meeting meet[n];

        for (int i = 0; i < n ; i++) {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i + 1;
        }

        sort(meet, meet + n, comp);

        vector <int> ans;
        int limit = meet[0].end;

        for (int i = 1; i < n; i++) {
            if (meet[i].start > limit) {
                limit = meet[i].end;
                ans.push_back(meet[i].pos);
            }
        }

        for (const auto& idx : ans) {
            std::cout << idx << " ";
        }
    }
};

int main() {
   Solution obj;
   int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] = {2,4,5,7,9,9};
   obj.maxMeetings(start, end, n);
   return 0;
}