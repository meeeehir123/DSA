/*Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise. Each letter in magazine can only be used once in ransomNote. Example 1: Input: ransomNote = "a", magazine = "b" Output: false Example 2: Input: ransomNote = "aa", magazine = "ab" Output: false Example 3: Input: ransomNote = "aa", magazine = "aab" Output: true Constraints: 1 <= ransomNote.length, magazine.length <= 105 ransomNote and magazine consist of lowercase English letters.*/
#include <iostream>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    int freq[26] = {0};

    for(char c : magazine)
    {
        freq[c - 'a']++;
    }

    for(char c : ransomNote)
    {
        if(freq[c - 'a'] == 0)
            return false;

        freq[c - 'a']--;
    }

    return true;
}

int main()
{
    string ransomNote = "aa";
    string magazine = "aab";

    cout << canConstruct(ransomNote, magazine);

    return 0;
}