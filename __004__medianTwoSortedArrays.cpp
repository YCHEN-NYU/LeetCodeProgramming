/*
 4. Median of Two Sorted Arrays
 There are two sorted arrays nums1 and nums2 of size m and n respectively.
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 You may assume nums1 and nums2 cannot be both empty.
 
 Example 1:
 nums1 = [1, 3]
 nums2 = [2]
 The median is 2.0
 
 Example 2:
 nums1 = [1, 2]
 nums2 = [3, 4]
 The median is (2 + 3)/2 = 2.5
 */

#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size(), N2 = nums2.size(), N = N1 + N2;
    if(N1 > N2) return findMedianSortedArrays(nums2, nums1);
    
    if(N1 == 0){
        if(N2 % 2 == 0)
            return (nums2[N2/2 - 1] + nums2[N2/2])/2.0;
        else
            return nums2[N2/2];
    }
    
    int cutL = 0, cutR = N1;
    int cut1 = cutL + (cutR - cutL)/2, cut2 = N/2 - cut1;
    
    while(cut1 <= N1){
        cut1 = cutL + (cutR - cutL)/2;
        cut2 = N/2 - cut1;
        
        double L1 = (cut1 == 0? INT_MIN : nums1[cut1 - 1]);
        double L2 = (cut2 == 0? INT_MIN : nums2[cut2 - 1]);
        double R1 = (cut1 == N1? INT_MAX : nums1[cut1]);
        double R2 = (cut2 == N2? INT_MAX : nums2[cut2]);
        
        if(L1 > R2)
            // move to the left
            cutR = cut1 - 1;
        else if(L2 > R1)
            // move to the right
            cutL = cut1 + 1;
        else {
            // case with target found
            if(N % 2 == 0)
                // N is even
                return (max(L1, L2) + min(R1, R2))/2.0;
            else
                return min(R1, R2);
        }
    }
    return -1;
}


int main(){
    vector<vector<int>> numList = {{1, 3}, {2, 4}};
    cout << findMedianSortedArrays(numList[0], numList[1]) << endl;
}
