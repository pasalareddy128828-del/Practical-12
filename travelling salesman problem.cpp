
#include <iostream>
#include <algorithm>
using namespace std;

#define V 4
#define INF 999999

int tsp(int graph[V][V], int pos, int visited)
{
    // If all cities are visited
    if (visited == (1 << V) - 1)
    {
        return graph[pos][0];
    }

    int ans = INF;

    // Visit unvisited cities
    for (int city = 0; city < V; city++)
    {
        if ((visited & (1 << city)) == 0)
        {
            int cost = graph[pos][city] +
                       tsp(graph, city, visited | (1 << city));

            ans = min(ans, cost);
        }
    }

    return ans;
}

int main()
{
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int visited = 1; // Starting from city 0

    cout << "Minimum travelling cost: "
         << tsp(graph, 0, visited) << endl;

    return 0;
}
