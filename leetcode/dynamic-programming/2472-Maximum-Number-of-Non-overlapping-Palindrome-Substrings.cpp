class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans = 0;
        int last = -1; 

        for (int mid = 0; mid < n; mid++) {

         
            int l = mid, r = mid;

            while (l > last && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    ans++;
                    last = r;
                    mid = r;     
                    break;
                }

                l--;
                r++;
            }

            
            if (mid < n - 1 && last < mid) {
                l = mid;
                r = mid + 1;

                while (l > last && r < n && s[l] == s[r]) {
                    if (r - l + 1 >= k) {
                        ans++;
                        last = r;
                        mid = r;
                        break;
                    }

                    l--;
                    r++;
                }
            }
        }

        return ans;
    }
};