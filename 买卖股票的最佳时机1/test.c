#define _CRT_SECURE_NO_WARNINGS 1
int maxProfit(int* prices, int pricesSize)
{
	int min = 10001;
	int maxprofit = 0;
	for (int i = 0; i < pricesSize; i++)
	{
		if (min > prices[i])
		{
			min = prices[i];
		}
		else
		{
			if (maxprofit < prices[i] - min)
			{
				maxprofit = prices[i] - min;
			}
		}
	}
	return maxprofit;
}