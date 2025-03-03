#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N = 1e5+10;
int parent[N];
int size[N];

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}
int find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    //left tree as larger size...
    a = find(a);
    //right tree as smaller size...
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    int cost = 0;
    for (auto it : edges)
    {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (find(u) != find(v))
        {
            cost += w;
            Union(u, v);
        }
    }
    return 0;
}