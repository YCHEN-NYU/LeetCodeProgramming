/*
 42. Trapping Rain Water
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 
 Example:
 Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 Output: 6
 */

#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    if(height.size() == 0)  return 0;
    int n = height.size();
    vector<int> leftHeight(n, 0), rightHeight(n, 0);
    leftHeight[0] = height[0];
    rightHeight[n - 1] = height[n - 1];
    
    for(int i = 1; i < n; i++){
        leftHeight[i] = max(leftHeight[i - 1], height[i]);
    }
    for(int j = n - 2; j >= 0; j--){
        rightHeight[j] = max(rightHeight[j + 1], height[j]);
    }
    
    int water = 0;
    for(int k = 0; k < n; k++){
        water += max(min(leftHeight[k], rightHeight[k]) - height[k], 0);
    }
    return water;
}







