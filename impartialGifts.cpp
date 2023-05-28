#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll D;

    cin >> N >> M >> D;

    vector<ll> A(N), B(M);

    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (ll i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll maxSum = 0;

    for (ll aokiGift : A)
    {
        auto lower = lower_bound(B.begin(), B.end(), aokiGift - D);
        auto upper = upper_bound(B.begin(), B.end(), aokiGift + D);

        if (lower != upper)
        {
            ll max_snuke_gift = *prev(upper);
            maxSum = max(maxSum, aokiGift + max_snuke_gift);
        }
    }

    if (maxSum == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << maxSum << endl;
}