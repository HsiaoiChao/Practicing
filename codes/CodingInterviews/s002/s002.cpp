/**
 * 剑指offer002:
 * 给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式输出
 * 输入为 非空 字符串且只包含数字 1 和 0
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    string ans;
    cin >> s1 >> s2;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int len = max(s1.size(), s2.size());
    int tmp = 0;

    for(int i = 0; i < len; i++) {
        tmp += (i < s1.size()) ? s1[i] == '1' : 0;
        tmp += (i < s2.size()) ? s2[i] == '1' : 0;
        ans += to_string(tmp%2);
        tmp /= 2;
    }
    if(tmp) ans += '1';

    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;
    
}