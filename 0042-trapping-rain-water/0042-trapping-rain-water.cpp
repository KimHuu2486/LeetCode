class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int left_max = height[left];
        int right_max= height[right];
        int water = 0;
        while (left<right){
            if (height[left]<height[right]){
                left++;
                left_max = max(left_max, height[left]);
                water += left_max - height[left];
            }
            else{
                right--;
                right_max = max(right_max, height[right]);
                water+=right_max - height[right];
            }
        }
        return water;
    }
};