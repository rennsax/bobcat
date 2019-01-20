#include <iostream>

#include <bobcat/pattern>

using namespace std;
using namespace FBB;

    Pattern nosep
    {
        //  1
        R"_((\w+)\s*:\s*)_"
        // 2
        "("
        //  3           4   5
        R"_((true|false)(\s+(\d+))?|)_"
        //  6   
        R"_((\d+)|)_"
        //  7           8        9   10
        R"_((\d{3,4})\s+(\d{3,4})(\s+(\d+))?)_"
        ")",
        true, 11
    };


void show(size_t idx)
{
    if (idx < nosep.end() && not nosep[idx].empty())
        cout << "    " << idx << ": " << nosep[idx] << '\n';
}
    
int main()
{
    size_t indices[] = {1, 3, 5, 6, 7, 8, 10};

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















