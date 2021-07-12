#include <bits/stdc++.h>
using namespace std;
int LEVEL(int p) { return ceil(log2(p + 1)); }
int parent(int n) { return int((n - 1) / 2); }
class MinMaxHeap
{
    vector<int> h;
    int MaxSize;
    int n;


public:
    MinMaxHeap(int size)
    {
        MaxSize = size;
        h.resize(size);
        n = -1;
    }

    void insertFunct(int x)
    {
        n++;
        if (n == 0)
        {
            cout << "Root node: " << x << endl;
            h.at(0) = x;
            return;
        }

        h.at(n) = x;
        if (int(floor(log2(n+1))) % 2 == 1) //max
        {   cout<<"MAX LEVEL: Node="<<x<<" Index:"<<n<<endl;
            
            if (h.at(n) < h.at(parent(n)))
            {
                cout << "MAX C1: x=" << x <<" parent= "<<parent(n)<<" n= " << n << endl;
                std::swap(h.at(n), h.at(parent(x)));
            }
            if ((h.at(n) > h.at(parent(parent(n)))) && (n > 2))
            {
                cout << "MAX C2: x=" << x <<" Grandparent= "<<parent(parent(n))<<" n= " << n << endl;
                std::swap(h.at(n), h.at(parent(parent(n))));
            }
        }
        else //min
        {
            cout<<"MIN LEVEL: Node="<<x<<" Index:"<<n<<endl;
            if(h.at(n) > h.at(parent(n))){
                cout << "MIN C1: x=" << x <<" parent= "<<parent(n)<<" n= " << n << endl;
                std::swap(h.at(n),h.at(parent(n)));
            }
            if(h.at(n) < h.at(parent(parent(n))))
            {
                cout << "MIN C2: x=" << x <<" Grandparent= "<<parent(parent(n))<<" n= " << n << endl;
                std::swap(h.at(n),h.at(parent(parent(n))));
            }
        }
    }

    void displayHeap()
    {
        cout << "\n\n\nHeap Contents:\n";
        for (vector<int>::iterator itr = h.begin(); itr != h.end(); ++itr)
            cout << *itr << " ";
        cout << endl;
    }
};

int main()
{
    MinMaxHeap obj(9);
    obj.insertFunct(8);
    obj.insertFunct(9);
    obj.insertFunct(10);
    obj.insertFunct(100);
    obj.insertFunct(150);
    obj.insertFunct(49);
    obj.insertFunct(51);
    obj.insertFunct(69);
    obj.insertFunct(165);
    obj.displayHeap();
    return 0;
}