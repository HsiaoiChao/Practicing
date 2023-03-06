/**
 * 剑指offer003:前 n 个数字二进制中 1 的个数
 * 给定一个非负整数 n ，请计算 0 到 n 之间的每个数字的二进制表示中 1 的个数，并输出一个数组。
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ans(n + 1);

    for(int i = 1; i <= n; i++) ans[i] = ans[i >> 1] + i % 2;

    for(int i = 0; i <= n; i++) {
        cout << ans[i] << " " ;
    }
    cout << endl;

    return 0;
}