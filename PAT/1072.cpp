#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;
int NHouse, NGas, mm, max_range, max_min = -1, best = -1;
int total, best_total = INF;
int graph[1050][1050];

int str2int(char str[]) {
    if (str[0] == 'G')
        return 1000 + atoi(str + 1);
    else
        return atoi(str);
}

int Dijkstra(int src) {
    total = 0;
    int dist[1050];
    bool visited[1050] = {false};
    fill(visited, visited + 1050, false);
    fill(dist, dist + 1050, INF);
    dist[src] = 0;
    //    visited[src] = 1;
    for (int i = 0; i < NHouse + NGas; ++i) {
        int mDist = INF, index = -1;
        for (int j = 1; j <= 1000 + NGas; ++j) {
            if (!visited[j] && dist[j] < mDist) {
                mDist = dist[j];
                index = j;
            }
            if (j == NHouse) j = 1000;
        }
        if (index != -1) {
            visited[index] = true;
            for (int j = 1; j <= 1000 + NGas; ++j) {
                if (!visited[j] && graph[index][j] != INF) {
                    int newd = dist[index] + graph[index][j];
                    if (newd < dist[j]) dist[j] = newd;
                }
                if (j == NHouse) j = 1000;
            }
        } else return -1;
    }
    int min_dist = INF;
    for (int i = 1; i <= NHouse; ++i) {
        if (dist[i] > max_range) return -1;
        if (dist[i] < min_dist) {
            min_dist = dist[i];
        }
        total += dist[i];
    }
    return min_dist;
}

int main() {
    fill(graph[0], graph[0] + 1050 * 1050, INF);
    scanf("%d%d%d%d", &NHouse, &NGas, &mm, &max_range);
    char s1[6], s2[6];
    int v1, v2, weight;
    for (int i = 0; i < mm; ++i) {
        scanf("%s%s%d", s1, s2, &weight);
        v1 = str2int(s1);
        v2 = str2int(s2);
        graph[v1][v2] = graph[v2][v1] = min(graph[v1][v2], weight);
    }
    for (int i = 0; i < 1050; ++i) graph[i][i] = 0;
    for (int i = 1001; i <= 1000 + NGas; ++i) {
        int temp_min = Dijkstra(i);
        if (temp_min == -1 || temp_min == INF) continue;
        if (temp_min > max_min) {
            max_min = temp_min;
            best = i;
            best_total = total;
        }
        else if (temp_min == max_min) {
            if (total < best_total) {
                best = i;
                best_total = total;
            } // the gas station with a lower number is preferable
        }
    }
    if (best != -1)
        printf("G%d\n%d.0 %.1lf\n", best - 1000, max_min, best_total * 1.0 / NHouse);
    else printf("No Solution\n");
    return 0;
}
