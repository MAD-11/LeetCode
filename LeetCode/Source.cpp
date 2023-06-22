#include <iostream>
#include <vector>
#include <map>

using namespace std;


//Solution_121
/*
class Solution_121 {
public:
    int maxProfit(vector<int>& prices) {
        int max = INT_MAX;
        int cur = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < max) {
                max = prices[i];
            }
            if (cur < prices[i] - max) {
                cur = prices[i] - max;
            }
        }
        return cur;
    }
};
*/

//Solution_347
/**/
class Solution_347 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> an;
        an.reserve(k);
        for (auto el : nums)
        {
            ++mp[el];
        }
        auto it1 = mp.begin();
        for (int i = 0; i < k; ++i)
        {
           an.push_back(it1->first);
           ++it1;
        }

        return an;
    }
};

int main()
{
    /*Solution_121 sl121;
    vector<int> v121 = { 7,1,5,3,6,4 };
    cout << sl121.maxProfit(v121);*/

    Solution_347 sl347;
    vector<int> v347 = { 2,2,3 , 1,1,1 };
    

    for (auto el : sl347.topKFrequent(v347, 2))
    {
        cout << el << " ";
    }

    return 0;
}