#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
    map<string,int> words;
    string s;
    do {
        cin>>s;
        if (s=="QUIT") break;
        map<string,int>::iterator iter1 = words.find(s);
        if (iter1 == words.end()) {
            cout<<0<<endl;
        } else {
            cout<<iter1->second<<endl;
        }
        words[s]++;
    } while (true);
    return 0;
}