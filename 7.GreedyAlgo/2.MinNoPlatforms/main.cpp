#include <iostream>
#include <vector>
#include <algorithm>

/*
Output: Minimum number of Platforms required 3

Time Complexity: O(n^2)  (due to two nested loops).

Space Complexity: O(1)  (no extra space used).
*/
int countPlatforms(int n, int arr[], int dep[])
{
    int ans=1; //final value
    for(int i=0;i<=n-1;i++)
    {
        int count=1; // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++)
        {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
           (arr[j]>=arr[i] && arr[j]<=dep[i]))
           {
               count++;
           }
        }
        ans=std::max(ans,count); //updating the value
    }
    return ans;

}

/*
Time Complexity: O(nlogn) Sorting takes O(nlogn) and traversal of arrays takes O(n) so overall time complexity is O(nlogn).

Space complexity: O(1)  (No extra space used).
*/
int countPlatformsOptimized(int n, int arr[], int dep[]) {

    std::sort(arr, arr + n);
    std::sort(dep, dep +n);

    int pf = 1;
    int res =1;
    int i = 1, j = 0;

    while (i < n && j < n) {

        if (arr[i]<= dep[j]) {
            pf++;
            i++;
        } else if (arr[i] > dep[j]) {
            pf--;
            j++;
        }
        if (pf > res) {
            res = pf;
        }
    }

    return res;
}



int main ()
{
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    std::cout<<"Minimum number of Platforms required "<<countPlatformsOptimized(n,arr,dep)<<std::endl;
}