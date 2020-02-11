#include <iostream>

using namespace std;

enum CPU_Rank {P1=1,P2,P3,P4,P5,P6,P7};

class CPU{
private:
    CPU_Rank rank;
    int frequency;
    float voltage;

public:
    CPU(CPU_Rank r,int f,float v):rank(r),frequency(f),voltage(v){
        cout<<"构造一个CPU类"<<endl;
    }
    CPU():CPU(P1,0,0){}      //默认构造函数

    CPU (const CPU &c): rank(c.rank), frequency(c.frequency), voltage(c.voltage) {     //拷贝构造函数
        cout<<"通过拷贝构造函数构造一个CPU"<<endl;
    }
    
    ~CPU(){                  //析构函数
        cout<<"析构一个CPU"<<endl;
    }

    //外部接口
    CPU_Rank GetRank() const {return rank;}
    int GetFrequency() const {return frequency;}
    float GetVoltage() const {return voltage;}

    void SetRank(CPU_Rank r) {rank = r;}
    void SetFrequency(int f) {frequency = f;}
    void SetVoltage(float v) {voltage = v;}

    void Run() {cout << "CPU开始运行！"<<endl;}
    void Stop() {cout<< "CPU停止运行！"<<endl;}

     
};

enum RAM_Type{DDR2=2,DDR3,DDR4};

class RAM{
private:
    RAM_Type type;
    unsigned int frequency; //MHz
    unsigned int size;  //GB

public:
    RAM(RAM_Type t,unsigned int f,unsigned int s): type(t),frequency(f),size(s){
        cout<<"构造一个RAM类"<<endl;
    }
    RAM():RAM(DDR2,0,0){}      //默认构造函数

    RAM (const RAM &r): type(r.type), frequency(r.frequency), size(r.size) {     //拷贝构造函数
        cout<<"通过拷贝构造函数构造一个RAM"<<endl;
    }

    ~RAM(){                  //析构函数
        cout<<"析构一个RAM"<<endl;
    }

    //外部接口
    RAM_Type GetType() const {return type;}
    unsigned int GetFrequency() const {return frequency;}
    unsigned int GetSize() const {return size;}

    void SetType(RAM_Type t) {type = t;}
    void SetFrequency(unsigned int f) {frequency = f;}
    void SetSize(unsigned int s) {size = s;}

    void Run() {cout << "RAM开始运行！"<<endl;}
    void Stop() {cout<< "RAM停止运行！"<<endl;}
     
};

enum CDROM_Interface {SATA,USB};
enum CDROM_Install_type {external,built_in};


class CD_ROM{
private:
    enum CDROM_Interface interface_type;
    CDROM_Install_type install_type; //MHz
    unsigned int cache_size;  //MB

public:
    CD_ROM(CDROM_Interface i,CDROM_Install_type it,unsigned int s): interface_type(i),install_type(it),cache_size(s){
        cout<<"构造一个CDROM类"<<endl;
    }
    CD_ROM():CD_ROM(SATA,built_in,0){}      //默认构造函数

    CD_ROM(const CD_ROM &cd): interface_type(cd.interface_type), install_type(cd.install_type), cache_size(cd.cache_size) {     //拷贝构造函数
        cout<<"通过拷贝构造函数构造一个CD_ROM"<<endl;
    }

    ~CD_ROM(){                  //析构函数
        cout<<"析构一个CDROM"<<endl;
    }

    //外部接口
    CDROM_Interface GetInterfaceType() const {return interface_type;}
    CDROM_Install_type GetInstallType() const {return install_type;}
    unsigned int GetSize() const {return cache_size;}

    void SetInterfaceType(CDROM_Interface i) {interface_type = i;}
    void SetInstallType(CDROM_Install_type it) {install_type = it;}
    void SetSize(unsigned int s) {cache_size = s;}

    void Run() {cout << "CD_ROM开始运行！"<<endl;}
    void Stop() {cout<< "CD_ROM停止运行！"<<endl;}
     
};

class Computer
{
private:
    CPU my_cpu;
    RAM my_ram;
    CD_ROM my_cdrom;
    unsigned int storage_size; //GB
    unsigned int band_width;
public:
    Computer(CPU c,RAM r,CD_ROM cd,unsigned int s,unsigned int b): my_cpu(c),my_ram(r),my_cdrom(cd),storage_size(s),band_width(b){
        cout<<"构造一个Computer"<<endl;
    }

    Computer (const Computer &c): my_cpu(c.my_cpu), my_ram(c.my_ram), my_cdrom(c.my_cdrom),storage_size(c.storage_size),band_width(c.band_width) {     //拷贝构造函数
        cout<<"通过拷贝构造函数构造一个Computer"<<endl;
    }

    ~Computer(){cout<<"析构一个Computer"<<endl;}

    //外部接口
    void Run(){
        my_cpu.Run();
        my_ram.Run();
        my_cdrom.Run();
        cout<<"Computer 开始运行！"<<endl;
    }

    void Stop(){
        my_cpu.Stop();
        my_ram.Stop();
        my_cdrom.Stop();
        cout<<"Computer 结束运行！"<<endl;
    }
};


int main(){
    CPU a(P6,300,2.8);
    a.Run();
    a.Stop();
    cout<<"**********"<<endl;

    RAM b(DDR3,1600,8);
    b.Run();
    b.Stop();
    cout<<"**********"<<endl;

    CD_ROM c(SATA,built_in,2);
    c.Run();
    c.Stop();
    cout<<"**********"<<endl;

    Computer my_computer(a,b,c,128,10);
    cout<<"**********"<<endl;

    my_computer.Run();
    my_computer.Stop();
    cout<<"**********"<<endl;


    return 0;
}