class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
     unordered_map<long long, int> mp;
    mp[0] = -1;

    long long prefix = 0;
    int best = INT_MAX;
    int ans = INT_MAX;

    vector<int> dp(arr.size(), INT_MAX);

    for (int i = 0; i < arr.size(); i++) {
        prefix += arr[i];

        if (mp.count(prefix - target)) {
            int j = mp[prefix - target];
            int len = i - j;

            if (j >= 0 && dp[j] != INT_MAX)
                ans = min(ans, len + dp[j]);

            best = min(best, len);
        }

        dp[i] = best;
        mp[prefix] = i;
    }

    return ans == INT_MAX ? -1 : ans;
    }
};