#include<iostream>
using namespace std;

#include <stdio.h>

int coinChange(int amount, int coins[], int coinsSize) {
    int dp[amount + 1];
    for (int i = 0; i <= amount; ++i) {
        dp[i] = 0;
    }
    dp[0] = 1;  // Base case: there is one way to make amount 0 (using no coins)

    for (int i = 0; i < coinsSize; ++i) {
        for (int j = coins[i]; j <= amount; ++j) {
            cout << "Initial dp value is " << dp[j]<<endl;
            dp[j] += dp[j - coins[i]];
            cout << "Dp array number " << j << " is as follows: "<< dp[j] <<endl;
        }
    }

    cout << "Dp array\n";
    for(int i=0 ; i<amount+1 ; i++)
    {
        cout << dp[i] <<endl;
    }

    return dp[amount];
}

int main() {
    int amount = 5;
    int coins[] = {1, 2, 5};
    int coinsSize = sizeof(coins) / sizeof(coins[0]);

    int combinations = coinChange(amount, coins, coinsSize);
    printf("Number of combinations: %d\n", combinations);

    return 0;
}