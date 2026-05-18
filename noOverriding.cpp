#include <iostream>
using namespace std;

class baseClass
{
public:
    virtual void perkenalan() final
    {
        cout << "Hallo saya function dari baseclass";
    }
};
class derivedClass : public baseClass
{
public:
    void perkenalan1()
    {
        cout << "Hallo saya function dari derivedclass";
    }
};
