#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string sumAB(string s1,string s2){
    string result="";
    int length1=s1.size();
    int length2=s2.size();
    int carry=0,sum;
    int num1,num2;

    for (int i = 0; i < max(length1,length2); i++)
    {
        if (i>=length1)
            num1=0;
        else
            num1=static_cast<int>(s1[length1-1-i]-'0');

        if (i>=length2)
            num2=0;
        else
            num2=static_cast<int>(s2[length2-1-i]-'0');

        sum=(num1+num2+carry)%10;
        carry=(num1+num2+carry)/10;
        result.insert(0,to_string(sum));
    }
    if (carry==1)
        result.insert(0,"1");
    return result;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<sumAB(s1,s2)<<endl;
    return 0;
}