// #include "Hello.h"
#include "calculator.h"
#include "printer.h"
int main()
{
    int a, b;
    a = 5;
    b = 6;
    Calculator cal;
    int x = cal.add(a,b);
    Print p;
    p.print(x);
    return 0;
}
