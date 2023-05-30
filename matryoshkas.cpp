#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::vector<ll> a(n);
        std::map<ll, ll> count;
        std::set<ll> sizes;

        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
            count[a[i]]++;
            sizes.insert(a[i]);
            sizes.insert(a[i] + 1);
        }

        ll b = 0;
        ll sets = 0;

        for (ll current : sizes)
        {
            ll current_count = count[current];
            sets += std::max(0LL, current_count - b);
            b = current_count;
        }

        std::cout << sets << std::endl;
    }
}