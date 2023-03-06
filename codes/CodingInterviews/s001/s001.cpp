/**
 * 剑指offer001:
 * 给定两个整数 a 和 b ，求它们的除法的商 a/b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%' 。
 * 
 * 注意：
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31, 2^31−1]。本题中，如果除法结果溢出，则返回 2^31 − 1
*/

#include<bits/stdc++.h>
using namespace std;

int calculate(int a, int b) {
    int ans = 0;
    while(a <= b) {
        int temp = b;
        int count = 1;
        while(temp >= 0xc0000000 && a <= temp + temp) {
            count += count;
            temp += temp;
        }
        ans += count;
        a -= temp;
    }
    return ans;
}

int main() {
    int a, b;
    cin >> a >> b;
    if(a == INT_MIN && b == -1) return INT_MAX;
    int flag = true;
    if(a > 0) {
        a = -a;
        flag = !flag;
    }
    if(b > 0) {
        b = -b;
        flag = !flag;
    }

    int c = calculate(a, b);
    if(flag) cout << c << endl;
    else cout << -c << endl;

    return 0;
}