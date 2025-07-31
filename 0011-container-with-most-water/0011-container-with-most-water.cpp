class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while (left<right){
            int temp = (right - left) * min(height[right], height[left]);
            ans = max(temp, ans);
            if (height[left]<height[right]){
                left++;
            }
            else right--;

        }
        return ans;
    }
};