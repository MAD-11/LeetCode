#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
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
/*
class Solution_347 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        vector<int> an;
        an.reserve(k);
        for (auto el : nums)
        {
            ++mp[el];
        }
        vector<pair<int, int>> vp(mp.begin(), mp.end());
        sort(
            vp.begin(),
            vp.end(),
            [](const auto& p1, const auto& p2) {
                return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
            }
        );

        for (int i = 0; i < k; ++i)
        {
            an.push_back(vp[i].first);
        }

        return an;
    }
};
*/

//Solution_1232
/*
class Solution_1232 {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y = coordinates[1][0] - coordinates[0][0];
        int x = coordinates[1][1] - coordinates[0][1];
        for (int i = 2; i < coordinates.size(); i++)
        {
            if (x * (coordinates[i][0] - coordinates[1][0]) != y * (coordinates[i][1] - coordinates[1][1]))
                return false;
        }
        return true;
    }
};
*/

//Solution_242
/*
class Solution_242 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        map<char, int> s1;
        map<char, int> s2;
        for (int i = 0; i < s.size(); i++)
        {
            ++s1[s[i]];
            ++s2[t[i]];
        }

        if (s1 != s2)
        {
            return false;
        }

        return true;
    }
};
*/

//Solution_219
/*
class Solution_219 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (um.count(nums[i])) 
            {
                if (i - um[nums[i]] <= k)
                    return true;
            }
            um[nums[i]] = i;
        }
        return false;
    }
};
*/

//Solution_3        not solved
/*
class Solution_3 {
public:
    int lengthOfLongestSubstring(string s) {
        string prev = "";
        string curr = "";

        for (auto el : s)
        {
            int found = curr.find(el);
            if ( found != std::string::npos)
            {
                if (curr.size() > prev.size())
                {
                    prev = curr;
                    curr = "";
                }
                else
                {
                    curr = "";
                }
            }
            curr += el;
        }
        if (curr.size() > prev.size())
            return curr.size();
        else
            return prev.size();
    }
};
*/

//Solution_125
/*
class Solution_125 {
public:
    bool isPalindrome(string s) {
        string ans;
        for (int x = 0; x != s.size(); ++x)
        {
            if (isalpha(s[x]) || isdigit(s[x]))
            {
                ans += putchar(tolower(s[x]));
            }
            
        }
        string nsa = ans;
        reverse(nsa.begin(), nsa.end());
        if (ans.compare(nsa) == 0)
            return true;
        else
            return false;
    }
};
*/

//Solution_26
/*
class Solution_26 {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it1 = nums.begin();
        auto it2 = unique(nums.begin(), nums.end());

        return it2 - it1;
    }
};
*/

//Solution_7
/*
class Solution_7 {
public:
    int reverse(int &x) {
        
        queue<int> st7;
        int sign = 1;
        if (x < 0)
        {
            x = abs(x);
            sign = -1;
        } 
        while (x != 0)
        {
            int a = x % 10;
            st7.push(x%10);
            x /= 10;
        }
        while (!st7.empty())
        {
            if (x > INT_MAX / 10 || (x == INT_MAX / 10 && st7.front() > 7)) return 0;
            if (x < INT_MIN/ 10 || (x == INT_MIN / 10 && st7.front() < -8)) return 0;
            x *= 10;
            x += st7.front();
            st7.pop();
        }
        return sign*x;
    }
};
*/

//Solution_88
/*
class Solution_88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        for (int i = m; i < nums1.size(); ++i)
        {
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(), nums1.end());
    }
};
*/

//Solution_744
/*
class Solution_744 {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it1 = letters.begin();
        while (!(it1 == letters.end()))
        {
            if (target < *it1)
                return *it1;
            else
                ++it1;
        }

        return letters[0];
    }
};
*/

//Solution_128      //not_solved
/*
class Solution_128 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return 1;
        set<int> s128;
        for (auto el : nums)
        {
            s128.insert(el);
        }

        int maxlength = 0;
        int counter = 1;

        auto it1 = s128.begin();
        auto it2 = it1++;
        int x = *it1 - *it2;
        
        for (; it2 != --s128.end();)
        {
            if (*it2 + x == *(++it2))
                ++counter;
            else
            {
                if (counter > maxlength)
                    maxlength = counter;
                counter = 2;
                it1 = it2;
                x = *(++it2) - *it1;
            }
                
        }
        if (counter > maxlength)
            maxlength = counter;
        return maxlength;
    }
};
*/

//Solution_27
/*
class Solution_27 {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it1 = nums.begin();
        auto it2 = nums.begin();
        while (it2 != nums.end())
        {
            if (*it1 == val)
            {
                if (*it2 != val)
                {
                    swap(*it1, *it2);
                }
                else
                {
                    it2++;

                }
            }
                else
                {
                    it1++; it2++;
                }
            
        }
        auto it3 = find(nums.begin(), nums.end(), val);
        return it3 - nums.begin();
    }
};
*/

//Solution_228
/**/
class Solution_228 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int firstpos = nums[0], secondpos = nums[0];
        vector<string> ans = {};
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] + 1 == nums[i + 1])
            {
                secondpos = nums[i + 1];
            }
            else
            {
                ans.push_back(to_string(firstpos) + "->" + to_string(i));
                firstpos = nums[i];
                secondpos = nums[i + 1];
            }
        }
        return ans;
    }
};


int main()
{
    /*Solution_121 sl121;
    vector<int> v121 = { 7,1,5,3,6,4 };
    cout << sl121.maxProfit(v121);*/
    /*Solution_347 sl347;
    vector<int> v347 = { 4,1,-1,2,-1,2,3 };
    for (auto el : sl347.topKFrequent(v347, 2)){cout << el << " ";}*/
    /*Solution_1232 sl1232;
    vector<vector<int>> v1232 = { {2,4},{2,5},{2, 7} };
    cout << sl1232.checkStraightLine(v1232);*/
    /*Solution_242 sl242;
    string s1 = "anagram", s2 = "nagaram";
    cout << sl242.isAnagram(s1,s2);*/
    /*Solution_219 sl219;
    vector<int> v219 = { 1,2,3,1,2,3 };
    int k = 2;
    cout << sl219.containsNearbyDuplicate(v219, k);*/
    /*Solution_3 sl3;
    cout << sl3.lengthOfLongestSubstring("pwwkew");*/
    /*Solution_125 sl125;
    cout << sl125.isPalindrome("1A man, a plan, a canal: Panama1");*/
    /*Solution_26 sl26;
    vector<int> v26 = { 0,0,1,1,1,2,2,3,3,4 };
    cout << sl26.removeDuplicates(v26);*/
    /*Solution_7 sl7;
    int y = 1534236469;
    cout << sl7.reverse(y);*/
    /*Solution_88 sl88;
    vector<int> v88_1 = { 1,2,3,0,0,0 }, v88_2 = { 2,5,6 };
    int m = 3, n = 3;
    sl88.merge(v88_1, m, v88_2, n);*/
    /*Solution_744 sl744;
    vector<char> v744 = { 'c','f','j'};
    char target = 'a';
    cout << sl744.nextGreatestLetter(v744, target);*/
    /*Solution_128 sl128;
    vector<int> v128 = { 4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3 };
    cout << sl128.longestConsecutive(v128);*/
    /*Solution_27 sl27;
    vector<int> v27 = { 0,1,2,2,3,0,4,2 };   int x = 2;
    cout << sl27.removeElement(v27, x);*/
    /**/
    Solution_228 sl228;
    vector<int> v228 = { 0,1,2,4,5,7 };
    sl228.summaryRanges(v228);


    return 0;
}