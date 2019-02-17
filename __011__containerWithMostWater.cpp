/*
 11. Container With Most Water
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 Note: You may not slant the container and n is at least 2.
 The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 
 Example:
 Input: [1,8,6,2,5,4,8,3,7]
 Output: 49
 */
#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int water = 0;
    int iLeft = 0, iRight = height.size() - 1;
    while(iLeft < iRight){
        int h = min(height[iLeft], height[iRight]);
        water = max(water, h*(iRight - iLeft));
        while(height[iLeft] <= h && iLeft < iRight) iLeft++;
        while(height[iRight] <= h && iLeft < iRight) iRight--;
    }
    return water;
}

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "max area = " << maxArea(height) << endl;
    return 0;
}
