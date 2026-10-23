#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, e, start;

    cout << "Enter number of users: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of users!";
        return 0;
    }

    vector<vector<int>> graph(n);

    cout << "Enter number of friendships: ";
    cin >> e;

    cout << "Enter friendships (u v):\n";

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            cout << "Invalid friendship!";
            return 0;
        }

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "Enter starting vertex (0 to "
         << n - 1 << "): ";
    cin >> start;

    if (start < 0 || start >= n)
    {
        cout << "Invalid starting vertex!";
        return 0;
    }

    vector<int> level(n, -1);
    queue<int> q;

    q.push(start);
    level[start] = 0;

    int count = 0;

    cout << "\nBFS Traversal Order: ";

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";
        count++;

        for (int v : graph[u])
        {
            if (level[v] == -1)
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    cout << "\n\nReachable Vertices: ";

    for (int i = 0; i < n; i++)
    {
        if (level[i] != -1)
            cout << i << " ";
    }

    cout << "\nUnvisited Vertices: ";

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (level[i] == -1)
        {
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << "\n\nBFS Levels:\n";

    for (int i = 0; i < n; i++)
    {
        if (level[i] != -1)
        {
            cout << "Vertex " << i
                 << " : Level " << level[i] << endl;
        }
    }

    cout << "\nReachable Vertices Count: "
         << count << endl;

    return 0;
}
