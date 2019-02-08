#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;

    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    /*for(int i = 0; i < n; i++) printf("%d ",a[i]);
    puts("");*/

    vector<int> b;
    for (int i = 0; i < n - 1; i++) b.push_back(a[i + 1] - a[i] - 1);

    /*for(int i = 0; i < b.size(); i++) printf("%d ",b[i]);
    puts("");*/

    sort(b.rbegin(), b.rend());

    /*for(int i = 0; i < b.size(); i++) printf("%d ",b[i]);
    puts("");*/

    int ans = a[n - 1] - a[0] + 1;
    for (int i = 0; i < k - 1; i++) {
        ans -= b[i];
    }
    cout << ans << '\n';
    return 0;
}
