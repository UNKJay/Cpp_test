#include <iostream>
#include <string>
using namespace std;
 
template<class T, int MAX = 1000>
class Stack
{
private:
       T list[MAX + 1];
       int top;
public:
       Stack();
       void push(const T &item);//将item压栈
       T pop();//将栈顶元素弹出栈
       const T & peek() const;//访问栈顶元素
       bool isEmpty() const;//判断是否栈空
};
//请完成栈模板类的实现，并解决括号匹配问题

template<class T, int MAX>
Stack<T,MAX>::Stack() : top(-1) {}

template<class T, int MAX>
void Stack<T,MAX>::push(const T &item) {
    list[++top] = item;
}

template<class T, int MAX>
T Stack<T,MAX>::pop() {
    return list[top--];
}

template<class T, int MAX>
const T& Stack<T,MAX>::peek() const {
    return list[top];
}

template<class T, int MAX>
bool Stack<T,MAX>::isEmpty() const {
    return top == -1;
}

int main() {
    string str;
    while (cin>>str)
    {
        Stack<char> sta;
        bool result = true;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(') sta.push(str[i]);
            else if (str[i] == ')') {
                if (sta.isEmpty()) {
                    result = false;
                    break;
                } else  sta.pop();
            } else continue;
        }
        cout<<(result?"Yes":"No")<<endl;
    }
}