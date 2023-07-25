#include <iostream>
#include <map>

using namespace std;

int main() {

    map<char, int> mp = {
        {'a', 5},
        {'b', 1},
        {'c', 2}
    };

    mp['d'] = 6;
    mp.insert(pair<char, int>('e', 3));
    mp.erase('b');
    cout << mp['b'];


    cout << endl;
    return 0;
}