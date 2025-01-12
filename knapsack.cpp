/*
    Fill in this block comment before submitting.
    Name: Syed Yasoob Ali
*/

#include <algorithm>
#include <vector>
using namespace std;

int knapsackBF(int weight, vector<pair<int, int>> & items, vector<pair<int, int>> & taken)
{
	/************ BRUTE FORCE CODE HERE! ***************/
	// weight = maximum weight knapsack can hold
	// items  = vector of items to choose from
	// taken  = vector to hold chosen items
	/***************************************************/
	int bestValue = 0;
	
	vector<pair<int, int>> bestTaken;

	// Iterates through every combination of items
	for (int i = 0; i < (1 << items.size()); i++)
		{
			vector<pair<int, int>> currentTaken;
			int currentValue = 0;
			int currentWeight = 0;

			// Checks to see if it is already included in the current combination
			for (int j = 0; j < items.size(); j++)
				{
					if (i & (1 << j))
					{
						currentTaken.push_back(items[j]);
						currentValue += items[j].second;
						currentWeight += items[j].first;
					}
				}

			// If current combination is valid and has a higher value than the current best, update best values
			if (currentWeight <= weight && currentValue > bestValue)
			{
				bestValue = currentValue;
				bestTaken = currentTaken;
			}
		}

	taken = bestTaken;
	// best value should be the sum of all values in 'taken'
	return bestValue;
}


int knapsackDYN(int weight, vector<pair<int, int>> & items, vector<pair<int, int>> & taken)
{
	/******** DYNAMIC PROGRAMMING CODE HERE! ***********/
	// weight = maximum weight knapsack can hold
	// items  = vector of items to choose from
	// taken  = vector to hold chosen items
	/***************************************************/
	int bestValue = 0;

	vector <pair<int, int>> bestTaken;

	// Creates a table to store max value that can be achieved for each weight up to the max weight
	int n = items.size();
	vector<vector<int>> dp(n + 1, vector<int>(weight + 1, 0));

	// Iterates through all the items
	for (int i = 1; i <= n; i++)
		{
			// Iterates through all the weights
			for (int w = 1; w <= weight; w++)
				{
					// If current item's weight is less than or equal to current weight, calculates the maximum value that can be achieved by either including or not including the item
					if (items[i - 1].first <= w)
					{
						dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].first] + items[i - 1].second);
					}
					else
					{
						// Otherwise, the maximum value is the value of the previous row
						dp[i][w] = dp[i - 1][w];
					}
				}
		}

	// Max value that can be achieved is stored in bottom right corner of table
	bestValue = dp[n][weight];
	
	int i = n;
	int w = weight;

	// Iterates through the table to find the items that were taken
	while (i > 0 && w > 0)
		{
			// If the value of current cell is different from value in the cell above, this means current item was taken
			if (dp[i][w] != dp[i - 1][w])
			{
				bestTaken.push_back(items[i - 1]);
				w -= items[i - 1].first;
			}
			
			i--;
		}

	
	taken = bestTaken;
	// best value should be the sum of all values in 'taken'
	return bestValue;

	// Posts the results backwards from the brute force version but should still be the correct values
}