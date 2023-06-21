#include <iostream>
#include <vector>

using namespace std;


//Solution_121
class Solution_121 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int maxprice = prices[1] - prices[0];
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            for (int j = i + 1; j < prices.size(); ++j)
            {
                if (prices[j] - prices[i] > maxprice)
                {
                    maxprice = prices[j] - prices[i];
                }
            }
        }
        if (maxprice > 0)
            return maxprice;
        return 0;
    }
};

int main()
{
    Solution_121 sl121;
    vector<int> v121 = {1,3,6,2};

    cout << sl121.maxProfit(v121);
}