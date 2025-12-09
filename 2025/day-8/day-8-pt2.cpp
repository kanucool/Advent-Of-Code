#include <bits/stdc++.h>
using namespace std;
using lint = long long;


struct UnionFind {
    vector<lint> parents;
    vector<lint> sizes;

    UnionFind(lint n) {
        parents.resize(n);
        iota(begin(parents), end(parents), 0);
        sizes.resize(n, 1);
    }

    lint find(lint p) {
        if (parents[p] != p) {
            parents[p] = find(parents[p]);
        }
        return parents[p];
     }

    bool onion(lint p, lint q) {
        lint parentP = find(p);
        lint parentQ = find(q);
        if (parentP == parentQ) return false;

        if (sizes[parentP] >= sizes[parentQ]) {
            sizes[parentP] += sizes[parentQ];
            parents[parentQ] = parentP;
        }
        else {
            sizes[parentQ] += sizes[parentP];
            parents[parentP] = parentQ;
        }

        return true;
    }
};


struct Node {
    lint x, y, z;
    
    Node(string& s) {
        stringstream ss(s);
        char trash;
        ss >> x >> trash >> y >> trash >> z;
    }

    Node(lint x, lint y, lint z) : x(x), y(y), z(z) {}

    double operator-(const Node& b) const {
        const Node& a = *this;
        lint xDist = a.x - b.x;
        lint yDist = a.y - b.y;
        lint zDist = a.z - b.z;
        return sqrt(xDist*xDist + yDist*yDist + zDist*zDist);
    }
};

struct Edge {
    lint u, v;
    double weight;

    Edge(lint u, lint v, vector<Node>& nodes) {
        this->u = u;
        this->v = v;

        weight = nodes[u] - nodes[v];
    }

    bool operator>(const Edge& b) const {
        return weight > b.weight;
    }
};


int main() {
    string s;
    vector<Node> nodes;

    while (getline(cin, s)) {
        nodes.push_back(Node(s));
    }
    lint N = nodes.size();

    priority_queue<Edge, vector<Edge>, greater<Edge>> heap;

    vector<pair<Node, Node>> edges;
    for (lint i = 0; i < N; i++) {
        for (lint j = i + 1; j < N; j++) {
            heap.push(Edge(i, j, nodes));
        }
    }

    UnionFind Graph(N);

    lint res = 0;

    while (!heap.empty()) {
        auto [p, q, weight] = heap.top(); heap.pop();
        if (Graph.onion(p, q)) {
            res = nodes[p].x * nodes[q].x;
        }
    }

    cout << res << endl;
    return 0;
}
