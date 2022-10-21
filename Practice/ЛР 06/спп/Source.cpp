#include <iostream>
#include <bitset>
#include <vector>
#include <sstream>

#define elif else if

using namespace std;
template<typename T>
int get_max(T some_bitset)
{
    int max = -1;
    for (int i = 0; i < some_bitset.size(); i++)
        if (some_bitset[i])
            max = i;
    return max;
}
template<typename T>
string print(T some_bitset)
{
    auto s = stringstream();
    string sep = "";
    for (int i = some_bitset.size() - 1; i >= 0; i--)
        if (some_bitset[i])
        {
            s << i << " ";
        }
    if (!s.tellp())
        s << "remainder 0";
    return s.str();
}
int main()
{
    auto up = { 6, 5, 3, 0 };
    auto down = { 4, 3, 2, 0 };

    vector<string> to_print;
    bitset<50> current, div;

    for (int i : up)
        current[i] = true;
    for (int i : down)
        div[i] = true;

    bitset<20> ans;


    to_print.push_back(print(current));

    while (get_max(current) > 0 && get_max(current) >= get_max(div))
    {
        int k = get_max(current) - get_max(div);
        ans[k] = !ans[k];
        current ^= (div << k);
        to_print.push_back(print(div << k));
        to_print.push_back(print(current));
    }
    for (int i = 0; i < to_print.size(); i++)
    {
        cout << to_print[i] << '\n';
        if (i % 2 != 0)
            cout << "----------------------------\n";
    }
    cout << "ANS\n" << print(ans);
}