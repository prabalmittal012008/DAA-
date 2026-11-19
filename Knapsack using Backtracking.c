
#include <stdio.h>

int wt[20], val[20], n, W;
int maxProfit = 0;

void knapsack(int i, int weight, int profit)
{
    if (weight > W)
        return;

    if (profit > maxProfit)
        maxProfit = profit;

    if (i == n)
        return;

    // Include current item
    knapsack(i + 1, weight + wt[i],
             profit + val[i]);

    // Exclude current item
    knapsack(i + 1, weight, profit);
}

int main()
{
    int i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter profits:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter capacity: ");
    scanf("%d", &W);

    knapsack(0, 0, 0);

    printf("Maximum profit = %d", maxProfit);

    return 0;
}
