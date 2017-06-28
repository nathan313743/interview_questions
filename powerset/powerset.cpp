#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;


/*
    Explanation:
i  	a,b,c 	    Subset
0 	000 	    { }         
1 	001 	    {a}         j:0         001 << 0 = 001
2 	010 	    {b}         j:1         001 << 1 = 010
3 	011 	    {a,b}       j:0, j:1    001 << 0 = 001, 001 << 1 = 010
4 	100 	    {c}         j:2         001 << 2 = 100
5 	101 	    {a,c}       j:0, j:2    001 << 0 = 001, 001 << 2 = 100
6 	110 	    {b,c}       etc
7 	111 	    {a,b,c}
*/

class Powerset
{
  public:
    void print(vector<char> *list);
    vector<string> process(vector<char> *list);
};

void Powerset::print(vector<char> *list)
{
    int setLength = pow(2, list->size());

    for (int i = 0; i < setLength; ++i)
    {
        for (int j = 0; j < list->size(); ++j)
        {
            // Shift the bit
            if (i & (1 << j))
            {
                cout << list->at(j);
            }
        }
        cout << endl;
    }
}

vector<string> Powerset::process(vector<char> *list)
{
    int setLength = pow(2, list->size());
    vector<string> result;

    for (int i = 0; i < setLength; ++i)
    {
        string t;
        for (int j = 0; j < list->size(); ++j)
        {
            if (i & (1 << j))
            {
                t += list->at(j);
                t += ",";
            }
        }

        if (t.length() > 0)
        {
            // remove trailing comma.
            t = t.substr(0, t.length() - 1);
        }

        result.push_back(t);
    }

    return result;
}

int main()
{
    Powerset powerset;
    vector<char> *list = new vector<char>();
    list->push_back('a');
    list->push_back('b');
    list->push_back('c');
    //powerset.print(list);
    vector<string> result = powerset.process(list);

    for (std::vector<string>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}