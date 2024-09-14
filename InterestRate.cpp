#include <iostream>
#include <cmath>

using namespace std;

class Interest
{
protected:
    int principal, rate, time;

public:
    Interest()
    {
        principal = rate = time = 0;
    }

    Interest(int principal, int rate, int time)
    {
        this->principal = principal;
        this->rate = rate;
        this->time = time;
    }

    string toString()
    {
        string s = "Principal = Rs " + to_string(principal) + "\nRate of Interest = " + to_string(rate) + "%\nTime Period = " + to_string(time) + " years";
        return s;
    }
};

class SimpleInterest : public Interest
{
public:
    SimpleInterest(int principal, int rate, int time) : Interest(principal, rate, time) {}

    double getFinalAmount()
    {
        double val = principal;
        val = val + (principal * rate * time) / 100.0;
        return val;
    }
};

class CompoundInterest : public Interest
{
public:
    CompoundInterest(int principal, int rate, int time) : Interest(principal, rate, time) {}

    double getFinalAmount()
    {
        double val = principal * pow((1 + rate / 100.0), time);
        return val;
    }
};

int main()
{
    int principal, rate, time;
    cin >> principal >> rate >> time;

    char choice;
    cin >> choice;

    if (choice == 's')
    {
        SimpleInterest si(principal, rate, time);
        cout << si.toString() << endl;
        double ans = si.getFinalAmount();
        ans = round(ans * 100) / 100.0;
        cout << ans << endl;
    }
    else
    {
        CompoundInterest ci(principal, rate, time);
        cout << ci.toString() << endl;
        double ans = ci.getFinalAmount();
        ans = round(ans * 100) / 100.0;
        cout << ans << endl;
    }

    return 0;
}
