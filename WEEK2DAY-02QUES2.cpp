/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise. In other words, return true if one of s1's permutations is the substring of s2. Example 1: Input: s1 = "ab", s2 = "eidbaooo" Output: true Explanation: s2 contains one permutation of s1 ("ba"). Example 2: Input: s1 = "ab", s2 = "eidboaoo" Output: false Constraints: 1 <= s1.length, s2.length <= 104 s1 and s2 consist of lowercase English letters*/
#include <iostream>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {

    int n = s1.size();
    int m = s2.size();

    if(n > m)
        return false;

    vector<int> count1(26, 0);
    vector<int> count2(26, 0);

    for(int i = 0; i < n; i++) {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;
    }

    if(count1 == count2)
        return true;

    for(int i = n; i < m; i++) {

        count2[s2[i] - 'a']++;

        count2[s2[i - n] - 'a']--;

        if(count1 == count2)
            return true;
    }

    return false;
}

int main() {

    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    if(checkInclusion(s1, s2))
        cout << "True";
    else
        cout << "False";

    return 0;
}