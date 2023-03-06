/**
 * 剑指offer004:只出现一次的数字
 * 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    int ans = 0;
    for(int i = 0; i < 32; i++) {
        int temp = 0;
        for(int j = 0; j < n; j++){
            temp += nums[j] >> i & 1;
        }
        if(temp % 3) ans |= 1 << i;
    }

    cout << ans << endl;

    return 0;
}