#include<iostream>

using namespace std;

string s;
bool symm(int L,int R){
    if (L==R||L==R+1)
        return true;
    if (s[L]!=s[R])
        return false;
    return symm(++L,--R);
}
int main(){
    cin>>s;
    if (symm(0,s.size()-1))
        cout<<"Yes."<<endl;
    else
        cout<<"No."<<endl;
    return 0;
}