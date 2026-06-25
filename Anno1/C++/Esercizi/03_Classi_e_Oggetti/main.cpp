#include <iostream>

class Rettangolo
{
    private:
    int  base,altezza;

    public:
    Rettangolo (int b,int a) : base(b),altezza(a) {}
    int Area () {return base*altezza;}

};

int main() {
    int a,b;
    std::cout << "Inserire base e altezza del rettangolo:";
    std::cin>>b>>a;
    Rettangolo ret(b,a);
    std::cout <<"valore area rettangolo:"<<ret.Area() << std::endl;
    return 0;
}