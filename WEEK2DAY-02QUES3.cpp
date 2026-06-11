/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {

    vector<int> result;

    int n = s.size();
    int m = p.size();

    if(m > n)
        return result;

    vector<int> countP(26, 0);
    vector<int> countS(26, 0);

    for(int i = 0; i < m; i++) {
        countP[p[i] - 'a']++;
        countS[s[i] - 'a']++;
    }

    if(countP == countS)
        result.push_back(0);

    for(int i = m; i < n; i++) {

        countS[s[i] - 'a']++;

        countS[s[i - m] - 'a']--;

        if(countP == countS)
            result.push_back(i - m + 1);
    }

    return result;
}

int main() {

    string s, p;

    cin >> s >> p;

    vector<int> ans = findAnagrams(s, p);

    for(int x : ans)
        cout << x << " ";

    return 0;
}