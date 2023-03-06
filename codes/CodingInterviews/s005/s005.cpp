/**
 * 剑指offer005:单词长度的最大乘积
 * 
 * 给定一个字符串数组 words，请计算当两个字符串 words[i] 和 words[j] 不包含相同字符时，它们长度的乘积的最大值。
 * 假设字符串中只包含英语的小写字母
 * 如果没有不包含相同字符的一对字符串，返回 0
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    int ans = 0;
    vector<int> tmp(n);

    for(int i = 0; i < n; i++) {
        string word = words[i];
        int len = word.size();
        for(int j = 0; j < len; j++) {
            tmp[i] |= 1 << (word[j] - 'a');
        }
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if((tmp[i] & tmp[j]) == 0) ans = max(ans, int(words[i].size() * words[j].size()));
        }
    }
    cout << ans << endl;

    return 0;
}