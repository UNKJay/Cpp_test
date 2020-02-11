#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;

class Equation{
private:
    int _a, _b, _c,_delta;
public:
    Equation(int a, int b, int c):_a(a),_b(b),_c(c){
        _delta=_b*_b-4*_a*_c;
    }

    void solve(){
        if (_delta>0 && _a!=0){
            cout<<1<<endl;
            double x=-_b/(2.0*_a);
            double y=sqrt(_delta)/(2.0*_a);
            cout<<fixed<<setprecision(2)<<x-y<<' '<<x+y<<endl;
        }
        else if(_delta==0 && _a!=0){
            cout<<2<<endl;
            double x=-_b/(2.0*_a);
            cout<<fixed<<setprecision(2)<<x<<endl;
        }
        else if (_delta<0 && _a!=0){
            cout<<3<<endl;
        }
        else if (_a==0 && _b==0 && _c!=0){
            cout<<4<<endl;
        }
        else if (_a==0 && _b==0 && _c==0){
            cout<<5<<endl;
        }
        else if (_a==0 && _b!=0){
            cout<<6<<endl;
            double x=-_c/double(_b);
            cout<<fixed<<setprecision(2)<<x<<endl;
        }
    }
};

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    Equation tmp(a, b, c);
    tmp.solve();
    return 0;
}