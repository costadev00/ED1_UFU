/*

*/
#include <bits/stdc++.h>
using namespace std;
class Chef
{
public:
    void makeChicken()
    {
        cout << "The chef makes chicken\n";
    }
    void makeSalad()
    {
        cout << "The chef makes salad\n";
    }
    void makeSpecialDish()
    {
        cout << "The chef makes bbq ribs\n";
    }
};
//heranca
class ItalianChef : public Chef
{
public:
    void makePasta()
    {
        cout << "The chef makes pasta\n";
    }
    //the functions is being oveerrided
    void makeSpecialDish()
    {
        cout << "The chef makes pizza\n";
    }
};
int main()
{
    Chef c;
    ItalianChef i;
    c.makeChicken();
    i.makeChicken();
    i.makePasta();
    i.makeSpecialDish();
    return 0;
}