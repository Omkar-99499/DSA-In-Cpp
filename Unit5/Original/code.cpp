#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, e;
    cout << "Enter number of users: ";
    cin >> n;

    vector<vector<int>> graph(n);

    cout << "Enter number of friendships: ";
    cin >> e;

    cout << "Enter friendships (user1 user2):\n";

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting user (0 to " << n - 1 << "): ";
    cin >> start;

    if (start < 0 || start >= n)
    {
        cout << "Invalid starting user!\n";
        return 0;
    }

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    int count = 0;

    cout << "\nBFS Visitation Order: ";

    while (!q.empty())
    {
        int user = q.front();
        q.pop();

        cout << user << " ";
        count++;

        for (int friendUser : graph[user])
        {
            if (!visited[friendUser])
            {
                visited[friendUser] = true;
                q.push(friendUser);
            }
        }
    }

    cout << "\nReachable users count: " << count;

    cout << "\nUnvisited users: ";
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << i << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;

    return 0;
}
