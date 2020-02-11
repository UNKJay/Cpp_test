#include <iostream>
using namespace std;
 
class Integer{
private:
    int _num;
//getLength()函数获取_num长度
    int getLength(){
        int num=_num,len=0;
        while(num){
            len++;
            num/=10;
        }
        return len;
    }
public:
//Integer类构造函数
    Integer(int num):_num(num){
    }
//反转_num
    int inversed(){
        int num=0,tmp=_num;
        int len=getLength();
        for (int i = 0; i < len; i++)
        {
            num=num*10+tmp%10;
            tmp/=10;
        }
        return num;
    }
};
 
int main() {
    int n;
    cin >> n;
    Integer integer(n);
    cout << integer.inversed() << endl;
    return 0;
}