#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll knapsack(ll knapsackCapacity, ll itemCount, const vector<ll> &weights, const vector<ll> &values)
{
    // matriz usando programacao dinamica para guardar valores parciais
    vector<vector<ll>> dp(itemCount + 1, vector<ll>(knapsackCapacity + 1, 0));

    for (ll i = 1; i <= itemCount; ++i)
    {
        for (ll j = 1; j <= knapsackCapacity; ++j)
        {
            // verifica se da pra colocar na mochila
            if (weights[i] <= j)
                // calcula o valor maximo se incluir o item
                dp[i][j] = max(values[i] + dp[i - 1][j - weights[i]], dp[i - 1][j]);
            else
                // mantem o valor anterior
                dp[i][j] = dp[i - 1][j];
        }
    }

    // retorna o valr maximo q pode ser alcancado
    return dp[itemCount][knapsackCapacity];
}

int main()
{
    ll itemCount, knapsackCapacity;
    cin >> itemCount >> knapsackCapacity;
    vector<ll> weights(itemCount + 1), values(itemCount + 1);

    ll i = 1;
    while (i <= itemCount)
    {
        // le peso e valor
        cin >> weights[i] >> values[i];
        i++;
    }

    // chama a funcao knapsack
    cout << knapsack(knapsackCapacity, itemCount, weights, values) << endl;

    return 0;
}
