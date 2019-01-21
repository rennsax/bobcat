#include <iostream>

#include <bobcat/pattern>

using namespace std;
using namespace FBB;

    Pattern nosep
    {
        //   1           2
        R"_(^(\w+)\s*:\s*(-?\d+)\s+)_"      // ID : zoneshift: minutes
        // 3
        "("
        //  4           5   6
        R"_((true|false)(\s+(\d+))?|)_"     // true/false [nMinutes shift]
        //  7   
        R"_((\d+)|)_"                       // nMinutes shift

                                            // hhmm hhmm [nMinutes shift]
        //  8           9        10  11
        R"_((\d{3,4})\s+(\d{3,4})(\s+(-?\d+))?)_"
        ")$",
        true, 12
    };


void show(size_t idx)
{
    if (idx < nosep.end() && not nosep[idx].empty())
        cout << "    " << idx << ": " << nosep[idx] << '\n';
}
    
int main()
{
    size_t indices[] = {1, 2, 4, 6, 7, 8, 9, 11};

    while (true)
    {
        cout << "? ";
        string line;
        if (not getline(cin, line))
            break;

        if (nosep << line)
        {
            cout << "NOSEP: #subexpr: " << nosep.end() << '\n';
            for (size_t idx: indices)
                show(idx);
        }
        else
            cout << "NOSEP: no match\n";
    }
}















