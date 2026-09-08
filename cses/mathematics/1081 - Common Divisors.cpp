#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    int mx = 0;

    for (int &x : a) {
        cin >> x;
        mx = max(mx, x);
    }

    vector<int> freq(mx + 1);

    for (int x : a)
        freq[x]++;


    for (int d = mx; d >= 1; d--) {
        int cnt = 0;

        for (int multiple = d; multiple <= mx; multiple += d) {
            cnt += freq[multiple];

            if (cnt >= 2) {
                cout << d << '\n';
                return 0;
            }
        }
    }

    return 0;
}