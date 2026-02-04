class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        const long long NEG = -(1LL<<60);
        int n = (int)nums.size();

        long long s0 = nums[0];   
        long long s1 = NEG;     
        long long s2 = NEG;       
        long long s3 = NEG;       
        long long ans = NEG;

        for (int i = 1; i < n; i++) {
            long long ns0 = nums[i];
            long long ns1 = NEG, ns2 = NEG, ns3 = NEG;

            if (nums[i] > nums[i - 1]) {
                ns1 = max(s0, s1) + nums[i];
                ns3 = max(s2, s3) + nums[i];
            } else if (nums[i] < nums[i - 1]) {
                ns2 = max(s1, s2) + nums[i];
            } 
            s0 = ns0; 
            s1 = ns1; 
            s2 = ns2; 
            s3 = ns3;
            ans = max(ans, s3);
        }

        return ans;
    }
};