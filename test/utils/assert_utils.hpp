#include <iostream>
#include <vector>
#include <algorithm>

namespace algo
{
    using namespace std;

    template<class T>
    bool vector_are_equal(vector<T> a, vector<T> b)
    {
        if (a.size() != b.size())
            return false;
        for (int i = 0; i < (int)a.size(); ++i) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
}
