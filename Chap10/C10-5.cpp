#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int main() {
    int N;
    cin>>N;
    vector<int> nums;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin>>num;
        nums.push_back(num);
    }
    sort(nums.begin(),nums.end());
    vector<int>::iterator iter = unique(nums.begin(),nums.end());
    nums.erase(iter,nums.end());
    for (vector<int>::iterator iter1 = nums.begin(); iter1!=nums.end(); ++iter1) {
        cout<<*iter1<<endl;
    }
    return 0;
}