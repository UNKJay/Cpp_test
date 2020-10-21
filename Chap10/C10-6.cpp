#include<iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int main() {
    string a, b;
    cin>>a>>b;
    map<string,int> M;
    for (int i = 0; i < a.length()-b.length()+1; i++)
    {
        M[a.substr(i,b.length())]++;
    }
    cout<<M[b]<<endl;
    return 0;
}