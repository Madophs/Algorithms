#include <bits/stdc++.h>

using namespace std;

// For testing purposes
enum Strategy {Random, Shuffle, Duplicates, Input};
vector<int> genRandNumbers(int size, const int mod, Strategy strategy);
void printVec(vector<int> &vec);

int apply_partition(vector<int> &vec, int l, int r)
{
    int pivot = l++;
    while (l < r) {
        while (l < r && vec[l] < vec[pivot]) ++l;
        while (r > l && vec[r] >= vec[pivot]) --r;
        swap(vec[l], vec[r]);
    }

    if (vec[l] >= vec[pivot])
        --l;

    swap(vec[pivot], vec[l]);
    return l;
}

void quicksort(vector<int> &vec, int l, int r)
{
    if (l >= r)
        return;
    int pivot = apply_partition(vec, l, r);
    quicksort(vec, l, pivot);
    quicksort(vec, pivot + 1, r);
}

int main()
{
    vector<int> vec = genRandNumbers(99999, 10000, Strategy::Random);
    printVec(vec);
    quicksort(vec, 0, vec.size()-1);
    printVec(vec);
    if (is_sorted(vec.begin(), vec.end())) {
        cout << "Is sorted" << endl;
    } else {
        cout << "Isn't sorted" << endl;
    }
    return 0;
}

vector<int> genRandNumbers(int size, const int mod, Strategy strategy)
{
    srand(time(0));
    vector<int> vec(size);

    switch (strategy) {
        case Random:
            while (size-- > 0) {
                int randNum = rand() % mod;
                vec.at(size) = randNum;
            }
        return vec;
        case Shuffle:
            iota(vec.begin(), vec.end(), 0);
            random_shuffle(vec.begin(), vec.end());
        case Input:
            vec.clear();
            int val;
            while (cin >> val)
                vec.push_back(val);
            return vec;
    }

    return vec;
}

void printVec(vector<int> &vec)
{
    for (unsigned int i = 0; i < vec.size(); ++i) {
        if (i && i % 10 == 0)
            cout << endl;
        cout << vec[i] << " ";
    }
    cout << endl << endl;
}
