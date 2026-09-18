class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                if (first[x] < l) {
                    valid = false;
                    break;
                }

                r = max(r, last[x]);
            }

            if (valid)
                intervals.push_back({l, r});
        }

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        int m = intervals.size();

        vector<pair<int, int>> dp(m + 1, {0, 0});
        vector<bool> take(m + 1, false);

        for (int i = 1; i <= m; i++) {
            int l = intervals[i - 1].first;
            int r = intervals[i - 1].second;

            dp[i] = dp[i - 1];

            int p = 0;

            for (int j = i - 1; j >= 1; j--) {
                if (intervals[j - 1].second < l) {
                    p = j;
                    break;
                }
            }

            int cnt = dp[p].first + 1;
            int len = dp[p].second + r - l + 1;

            if (cnt > dp[i].first ||
                (cnt == dp[i].first && len < dp[i].second)) {
                dp[i] = {cnt, len};
                take[i] = true;
            }
        }

        vector<string> ans;
        int i = m;

        while (i > 0) {
            if (!take[i]) {
                i--;
                continue;
            }

            int l = intervals[i - 1].first;
            int r = intervals[i - 1].second;

            ans.push_back(s.substr(l, r - l + 1));

            int p = 0;

            for (int j = i - 1; j >= 1; j--) {
                if (intervals[j - 1].second < l) {
                    p = j;
                    break;
                }
            }

            i = p;
        }

        return ans;
    }
};