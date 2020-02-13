#include "employee.h"

using namespace std;

int main(){

    Employee e("Wang","Haidian","Beijing","100084");
    e.display();
    e.changeName("Li");
    e.display();
    
    return 0;
}