#include <iostream>
#include <bits/stdc++.h>
const int N = 50005;
const int M = 20000005;
const int max_ = 0x3f3f3f3f;
int n;
int val[15];
std::string ch[N];
std::map<long long, int> mp;
struct edge {
    int v, w, next;
} edge[M];
int head[N], ec;
int dis[N], par[N];
bool vis[N];
std::vector<int> vec;
struct pp{
    int d, u;
    bool operator < (const pp &cmp) const {
        return d > cmp.d;
    }
};
void add_edge(int u, int v, int w) {
    edge[ec] = {v, w, head[u]};
    head[u] = ec++;
};
std::vector<long long> py;
void deal(int id) {
    long long tmp = 0;
    for (int i = 0; i < 10; ++i) {
        tmp = tmp * 10 + ch[id][i] - '0';
    }
    const long long tt = tmp;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            tmp = tmp - (ch[id][i] - '0' - j) * py[i];
            auto it = mp.find(tmp);
            if (it != mp.end()) {
                int len = 0;
                int idx = it->second;
                while (len < 9 && ch[id][len] == ch[idx][len]) {
                    len++;
                }
                add_edge(id, idx, val[len]);
                add_edge(idx, id, val[len]);
            }
            tmp = tt;
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            int t1 = ch[id][i] - '0';
            int t2 = ch[id][j] - '0';
            tmp = tmp - (t1 - t2) * py[i] - (t2 - t1) * py[j];
            auto it = mp.find(tmp);
            if (it != mp.end()){
                int len = 0;
                int idx = it->second;
                while (len < 9 && ch[id][len] == ch[idx][len]){
                    len++;
                }
                add_edge(id, idx, val[len]);
                add_edge(idx, id, val[len]);
            }
            tmp = tt;
        }
    }
    mp.insert({tt, id});
}
void dcstr(int x){
    std::priority_queue<pp> pq;
    dis[x] = 0;
    pq.push({dis[x], x});
    while (!pq.empty()){
        int u = pq.top().u;
        pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = head[u]; i != -1 ; i = edge[i].next) {
            int v = edge[i].v;
            if (dis[v] > dis[u] + edge[i].w){
                par[v] = u;
                dis[v] = dis[u] + edge[i].w;
                pq.push({dis[v], v});
            }
        }
    }
}
int main() {
    long long tmp = 1;
    for (int i = 0; i < 10; ++i) {
        py.push_back(tmp);
        tmp *= 10;
    }
    std::reverse(py.begin(), py.end());
    std::cin >> n;
    memset(head, -1, sizeof(head));
    ec = 0;
    for (int i = 0; i < 10; ++i) {
        std::cin >> val[i];
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> ch[i];
        deal(i);
    }
    memset(dis, max_, sizeof(dis));
    par[1] = -1;
    dcstr(1);
    if (dis[n] == max_){
        std::cout << "-1";
        return 0;
    }
    std::cout << dis[n] << "\n";
    int x = n;
    while(x != -1){
        vec.push_back(x);
        x = par[x];
    }
    reverse(vec.begin(), vec.end());
    std::cout << vec.size() << "\n";
    for (int i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << (i == vec.size() - 1? "\n" : " ");
    }
    return 0;
}
