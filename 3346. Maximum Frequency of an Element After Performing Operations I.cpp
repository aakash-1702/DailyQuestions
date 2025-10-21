class Solution {
public:
    int M = 1e5 + 2;

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<long long> freq(M+1, 0);

        // Step 1: frequency of each number
        for (auto &x : nums) freq[x]++;

        // Step 2: prefix sum to count <= i elements
        for (int i = 1; i <= M; i++) freq[i] += freq[i - 1];

        int ans = 0;

        // Step 3: for each number, calculate total within [x - k, x + k]
       for(int i = 0 ; i <= M ;i++){
         if(freq[i] == 0) continue;
         int lRange = max(0 , i - k);
         int rRange = min(M , i+k);
         int totalCnt = freq[rRange] - (lRange > 0 ? freq[lRange-1] : 0);
         int targetCnt = freq[i] - (i > 0 ? freq[i-1] : 0);
         int remain = totalCnt - targetCnt;
         ans = max(ans , targetCnt + min(remain , numOperations));
       }

        return ans;
    }
};
