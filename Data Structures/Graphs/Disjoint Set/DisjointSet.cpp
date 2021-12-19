#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
public:
    UnionFind(int sz) : root(sz), rank(sz){
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }
    int find(int x);
    void unionSet(int x, int y);
    bool connected(int x, int y);
    void Display(){
        for(int a=0; a<root.size(); a++){
            std::cout<<root[a]<<std::endl;
        }
    }

private:
    std::vector<int> root;
    std::vector<int> rank;
};

int UnionFind::find(int x)
{
    if (x == root[x])
    {
        return x;
    }
    return root[x] = find(root[x]);
}

void UnionFind::unionSet(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY)
    {
        if (rank[rootX] > rank[rootY])
        {
            root[rootY] = rootX;
        }
        else if (rank[rootX] < rank[rootY])
        {
            root[rootX] = rootY;
        }
        else
        {
            root[rootY] = rootX;
            rank[rootX] += 1;
        }
    }
}

bool UnionFind::connected(int x, int y){
    return find(x) == find(y);
}

int main(){
    cout << boolalpha;
    UnionFind uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);
    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf.connected(4, 9) << endl;  // true
    return 0;
}
