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
#include <numeric>
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
/*
class Solution_228 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 1)
            return { to_string(nums[0]) };
        if (nums.empty())
            return {};
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
                if (firstpos == secondpos) 
                { 
                    ans.push_back(to_string(firstpos)); 
                    firstpos = nums[i + 1];
                    secondpos = nums[i + 1];
                }
                else {
                    ans.push_back(to_string(firstpos) + "->" + to_string(secondpos));
                    firstpos = nums[i + 1];
                    secondpos = nums[i + 1];
                    }
            }
            if (nums[i + 1] == *(nums.end() - 1))
            {
                if (firstpos == secondpos)
                {
                    ans.push_back(to_string(firstpos));
                    firstpos = nums[i + 1];
                }
                else
                {
                    ans.push_back(to_string(firstpos) + "->" + to_string(secondpos));
                }
                
            }
        }
        return ans;
    }
};
*/

//Solution_70
/*
class Solution_70 {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};
*/

//Solution_169
/*
class Solution_169 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m169;
        for (int const el : nums)
        {
            ++m169[el];
        }
        for (auto const& m : m169)
        {
            if (m.second > nums.size() / 2)
                return m.first;
        }

        return 0;
    }
};
*/

//Solution_530
/*
 struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 TreeNode* insertNode(TreeNode* root, int value) {
     if (root == nullptr) {
         return new TreeNode(value);
     }

     if (value < root->val) {
         root->left = insertNode(root->left, value);
     }
     else {
         root->right = insertNode(root->right, value);
     }

     return root;
 }


class Solution_530 {
public:
    int getMinimumDifference(TreeNode* root) {
        preOrderTraversal(root);
        int min = abs(v530[1] - v530[0]);
        for (int i = 0; i < v530.size(); ++i)
        {
            for (int j = i+1; j < v530.size(); ++j)
            {
                if (abs(v530[i] - v530[j]) < min)
                    min = abs(v530[i] - v530[j]);
            }
        }

        return min;
    }

    void preOrderTraversal(TreeNode* root) {
        
        if (root == nullptr) {
            return;
        }

        v530.push_back(root->val);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    vector<int> v530;
};
*/

//Solution_33
/*
class Solution_33 {
public:
    int search(vector<int>& nums, int target) {
        auto it1 = find(nums.begin(), nums.end(), target);
        if ( it1 != nums.end())
        {
            return it1 - nums.begin();
        }
        else
        {
            return -1;
        }
    }
};
*/

//Solution_1351
/*
class Solution_1351 {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int counter = 0;
        for (size_t it_grid = grid.size() - 1; it_grid != -1; --it_grid)
        {
            for (size_t it_row = grid[it_grid].size() - 1; it_row != -1; --it_row)
            {
                if (grid[it_grid][it_row] < 0)
                {
                    counter++;
                }
                else
                {
                    continue;
                }
                
            }
        }
        return counter;
    }
};
*/

//Solution_11
/*
class Solution_11 {
public:
    int maxArea(vector<int>& height) {
        int max1 = 0, left = 0, right = height.size()-1;
        while (left != right)
        {
            max1 = max(min(height[left], height[right]) *(right - left), max1);

            if (height[left] < height[right])
                ++left;
            else
                --right;
        }

        return max1;
    }
};
*/

//Solution_53       // not_solved
/*
class Solution_53 {
public:
    int maxSubArray(vector<int>& nums) {
        int max1 = nums[nums.size() / 2];//accumulate(nums.begin(), nums.end(), 0);
        int left = nums.size() / 2 - 1, right = nums[nums.size() / 2] + 1;
        while (left != *nums.begin() || right != *(nums.end() - 1))
        {
            if (max1 + nums[left] >= max1)
            {
                max1 += nums[left];
                left++;
            }
            else
                if (max1 + nums[right] >= max1)
                {
                    max1 += nums[right];
                    right++;
                }
                else
                    return max1;
        }
    }
};
*/

//Solution_21
/*
struct ListNode {
    int val;    
    ListNode *next;    
    ListNode() : val(0), next(nullptr) {}    
    ListNode(int x) : val(x), next(nullptr) {}    
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution_21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* mergened = new ListNode(-1);
        ListNode* current = mergened;

        while (list1 && list2) {
            if (list1->val < list2->val)
            {
                current->next = list1;
                list1 = list1->next;
                
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
                
            }
            current = current->next;
        }

        while (list1) 
        {
            current->next = list1;
            list1 = list1->next;
            current = current->next;
        }
        while (list2)
        {
            current->next = list2;
            list2 = list2->next;
            current = current->next;
        }

        return mergened->next;
    }
};
*/

//Solution_1502
/*
class Solution_1502 {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int size = arr.size();
        if (size == 2)
            return true;
        sort(arr.begin(), arr.end());
        int c = 1, x = arr[1] - arr[0];
        while (c != size)
        {
            if (!(arr[c - 1] + x == arr[c]))
                return false;
            c++;
        }
        return true;
    }
};
*/

//Solution_141
/*
class Solution_141 {
public:
    bool hasCycle(ListNode* head) {
        int i = 0;
        while (i < 10001)
        {

            if (head == nullptr)
                return false;
            head = head->next;
            ++i;
        }

        return true;

    }
};
*/

//Solution_189
/*
class Solution_189 {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return;
        k = k % nums.size();
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
        
    }
};
*/

//Solution_605      // not_solved
/*
class Solution_605 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

    }
};
Solution_605 sl605;
vector<int> v605 = { 1,0,0,0,1 };
sl605.canPlaceFlowers(v605, 2);
*/

//Solution_2352
/*
class Solution_2352 {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> mv;
        int c = 0;

        for (size_t i = 0; i < grid.size(); i++)
        {
            vector<int> temp;
            for (size_t j = 0; j < grid[i].size(); j++)
            {
                temp.push_back(grid[j][i]);
            }
            mv.push_back(temp);
        }

        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < mv.size(); j++)
            {
                if (grid[i] == mv[j])
                    c++;
            }
        }

        return c;
    }
};
*/

//Solution_1732
/*
class Solution_1732 {
public:
    int largestAltitude(vector<int>& gain) {
        int road = 0;
        int max = 0;
        for (int el : gain)
        {
            road += el;
            if (max < road)
                max = road;
        }
        return max;
    }
};
*/

//Solution_2462
/*
class Solution_2462 {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int totalCost = 0;
        
        while (k--)
        {
            auto min1 = min_element(costs.begin(), costs.end());
            auto min2 = min1;
            if (costs.size() > candidates)
            {
                min1 = min_element(costs.begin(), costs.end() - (costs.size() - candidates));
                min2 = min_element(costs.end() - candidates, costs.end());
            }
            if (*min1 != *min2)
            {   if (*min1 < *min2)
                {
                totalCost += *min1;
                costs.erase(min1);
                }
                else
                {
                    totalCost += *min2;
                    costs.erase(min2);
                
                }
            }
            else
            {
                totalCost += *min1;
                costs.erase(min1);
            }
            
        }

        return totalCost;
    }
};
*/

//Solution_67
/*
class Solution_67 {
public:


    string addBinary(string a, string b) {
        bool flag = false;
        int aLength = a.size(), bLength = b.size();
        int curLength;
        string answer = "";
        if (aLength > bLength)
        {
            b.insert(0, aLength - bLength, '0');
            curLength = aLength;
        }
        else
            if (aLength != bLength)
            {
                a.insert(0, bLength - aLength, '0');
                curLength = bLength;
            }
        for (size_t i = curLength - 1; i != -1; --i)
        {
            if (a[i] == '0')
                // a == 0
                if (b[i] == '0')
                // b == 0 && a == 0
                {
                    if (!flag)
                    {
                        answer += '0';
                    }
                    else
                    {
                        answer += '1';
                        flag = false;
                    }
                }
                else
                // b == 1 && a == 0
                {
                    if (!flag)
                    {
                        answer += '1';
                    }
                    else
                    {
                        answer += '0';
                        flag = true;
                    }
                }
            else
                // a == 1
                if (b[i] == '0')
                // b == 0 && a == 1
                {
                    if (!flag)
                    {
                        answer += '1';
                    }
                    else
                    {
                        answer += '0';
                        flag = true;
                    }
                }
                else
                // b == 1 && a == 1
                {
                    if (!flag)
                    {
                        answer += '0';
                        flag = true;
                    }
                    else
                    {
                        answer += '1';
                        flag = true;
                    }
                }
        }
        if (flag)
            answer += '1';
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
*/

//Solution_83
/*
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution_83 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val)
            {
                current->next = current->next->next;
            }
            else
                current = current->next;  
        }
        return head;
    }
};
*/

//Solution_459
/*
class Solution_459 {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for (size_t i = 1; i <= len / 2; ++i)
        {
            if (len % i == 0)
            {
                string subStr = s.substr(0, i);
                string repStr = "";
                for (size_t j = 0; j < len / i; ++j)
                {
                    repStr += subStr;
                }
                if (repStr == s)
                    return true;
            }
        }
        return false;
    }
};
*/

//Solution_605
/*
class Solution_605 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        return true;
    }
};
*/



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
    /*Solution_228 sl228;
    vector<int> v228 = { 1, 3 };
    sl228.summaryRanges(v228);*/
    /*Solution_70 sl70;
    cout << sl70.climbStairs(3);*/
    /*Solution_169 sl169;
    vector<int> v169 = { 2,2,1,1,1,2,2,1,1 };
    cout << sl169.majorityElement(v169);*/
    /*Solution_530 sl530;
    TreeNode* root = new TreeNode(236);
    insertNode(root, 104);
    insertNode(root, 701);
    insertNode(root, NULL);
    insertNode(root, 227);
    insertNode(root, NULL);
    insertNode(root, 911);
    sl530.getMinimumDifference(root);*/
    /*Solution_33 sl33;
    vector<int> v33 = { 4,5,6,7,0,1,2 };
    int target = 3;
    cout << sl33.search(v33, target);*/
    /*Solution_1351 sl1351;
    vector<vector<int>> vv1351 = { {4,3,2,-1}, {3,2,1,-1}, {1,1,-1,-2}, {-1,-1,-2,-3} };
    cout << sl1351.countNegatives(vv1351);*/
    /*Solution_11 sl11;
    vector<int> v11 = { 1,8,6,2,5,4,8,3,7 };
    cout << sl11.maxArea(v11);*/
    /*Solution_53 sl53;
    vector<int> v53 = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << sl53.maxSubArray(v53);*/
    /*ListNode* head = nullptr; // √олова списка
    ListNode* tail = nullptr; // ’вост списка

    for (int i = 1; i <= 5; i++) {
        ListNode* newNode = new ListNode(i);

        if (head == nullptr) {
            // ≈сли список пустой, новый узел становитс€ головой и хвостом списка
            head = newNode;
            tail = newNode;
        }
        else {
            // ≈сли список не пустой, добавл€ем новый узел в конец списка
            tail->next = newNode;
            tail = newNode;
        }
    }
    ListNode* head1 = nullptr; // √олова списка
    ListNode* tail1 = nullptr; // ’вост списка

    for (int i = 2; i <= 10; i+=2) {
        ListNode* newNode = new ListNode(i);

        if (head1 == nullptr) {
            // ≈1сли список пустой, новый узел становитс€ головой и хвостом списка
            head1 = newNode;
            tail1 = newNode;
        }
        else {
            // ≈сли список не пустой, добавл€ем новый узел в конец списка
            tail1->next = newNode;
            tail1 = newNode;
        }
    }
    Solution_21 sl21;
    sl21.mergeTwoLists(head, head1);*/
    /*Solution_1502 sl1502;
    vector<int> v1502 = { 3,5,1 };
    cout << sl1502.canMakeArithmeticProgression(v1502);*/
    /*Solution_189 sl189;
    vector<int> v189 = { 1,2 };
    sl189.rotate(v189, 1);*/
    /*Solution_2352 sl2352;
    vector<vector<int>> grid = { {13,13},{13,13} };
    cout << sl2352.equalPairs(grid);*/
    /*Solution_1732 sl1732;
    vector<int> v1732 = { -5,1,5,0,-7 };
    cout << sl1732.largestAltitude(v1732);*/
    /*Solution_2462 sl2462;
vector<int> v2462 = { 31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58 };
cout << sl2462.totalCost(v2462, 11, 2);*/
    //Solution_67
    /*Solution_67 sl67;
cout << sl67.addBinary("11","1");*/
    //Solution_83
    /*
    Solution_83 sl83;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    sl83.deleteDuplicates(head);

    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    */
    //Solution_459
    /*Solution_459 sl459;
    cout << sl459.repeatedSubstringPattern("abab");*/
    //
    /*
Solution_605 sl605;
vector<int> v605 = {};
sl605.canPlaceFlowers(v605, 1);
*/


 }


 //¬аканси€ (hh.ru)
 /*
 // «а услови€ вз€то следующее:
// 1) ¬се обычные пробелы в строке равны одинарному пробелу ' '.
// 2) Ќайденный двойной пробел обозначает пробел до конца строки (длинный пробел).
// 3) —трока точно имеет длинный пробел.
 void TrimRight(char* s)
 {
     string str = s;
     int length = str.size(), start = 0;

     // сокращаем диапазон возможного первого по€влени€ длинного пробела
     while (true)
     {
         if (s[(length + start) / 2] == ' ' && s[((length + start) / 2) + 1] == ' ')
         {
             if (length / 2 < start) break;
             else length /= 2;
         }
         else
         {
             if (length < (length + start) / 2) break;
             else start = (length + start) / 2;
         }
     }

     // ищем в уменьшенном диапазоне по€вление длинного пробела и замен€ем первый пробел на “ерминальный ноль '\0'
     for (size_t i = start; i < length - 1; ++i)
     {
         if (s[i] == ' ' && s[i + 1] == ' ')
         {
             s[i] = '\0';
             break;
         }
     }
 }

 int main()
 {
     char s[] = "0123456789 0123456789 0123456789 0123456789 0123456789 01234567890123456789 0123456789 0123456789                    ";
     cout << s << "=end" << endl;
     TrimRight(s);
     cout << s << "=end" << endl;
 }
 */



//Binary Tree

//// —труктура дл€ представлени€ узла бинарного дерева
//struct Node {
//    int data;
//    Node* left;
//    Node* right;
//
//    Node(int value) {
//        data = value;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//
//// ‘ункци€ дл€ вставки нового узла в бинарное дерево
//Node* insertNode(Node* root, int value) {
//    if (root == nullptr) {
//        return new Node(value);
//    }
//
//    if (value < root->data) {
//        root->left = insertNode(root->left, value);
//    }
//    else {
//        root->right = insertNode(root->right, value);
//    }
//
//    return root;
//}
//
//// ‘ункци€ дл€ обхода узлов бинарного дерева в пр€мом пор€дке (pre-order)
//void preOrderTraversal(Node* root) {
//    if (root == nullptr) {
//        return;
//    }
//
//    std::cout << root->data << " ";
//    preOrderTraversal(root->left);
//    preOrderTraversal(root->right);
//}
//
//int main() {
//    // —оздание корневого узла
//    Node* root = new Node(5);
//
//    // ¬ставка узлов
//    insertNode(root, 3);
//    insertNode(root, 7);
//    insertNode(root, 2);
//    insertNode(root, 4);
//    insertNode(root, 6);
//    insertNode(root, 8);
//
//    // ќбход узлов в пр€мом пор€дке
//    std::cout << "Pre-order traversal: ";
//    preOrderTraversal(root);
//    std::cout << std::endl;
//
//    return 0;
//}