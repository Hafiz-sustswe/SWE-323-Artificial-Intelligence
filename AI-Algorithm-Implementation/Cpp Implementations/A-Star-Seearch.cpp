//ashrafsusts19

#include <bits/stdc++.h>
#include <limits>

using namespace std;
typedef long long int lli;
#define prnt(a) cout << a << "\n"
#define prnt2(a, b) cout << a << " " << b << "\n";
#define prnt3(a, b, c) cout << a << " " << b << " " << c << "\n";
#define forp1(a) for (lli i = 0; i < a; i++)
#define forp2(a, b) for (lli i = a; i < b; i++)
#define forf(a, b, c) for (lli i = a; i < b; i += c)
#define forv1(i, a) for (lli i = 0; i < a; i++)
#define forv2(i, a, b) for (lli i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define refill(a, b, c) a.clear();a.resize(b, c);
#define reloc(a, b) a.clear();a.resize(b);


void debug(vector<lli> &lst){
    cout << "Debug: ";
    for (lli i = 0; i < lst.size(); i++) cout << lst[i] << " ";    
    cout << "\n";
}

void debug2(string name, vector<lli> &lst)
{
    cout << name << ": ";
    for (lli i = 0; i < lst.size(); i++) cout << lst[i] << " ";
    cout << "\n";
}


struct Edge{
    lli parent, node, g, h;
};

struct CompareEdge{
    bool operator()(Edge const& p1, Edge const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.g + p1.h > p2.g + p2.h;
    }
};

void printPath(lli ind, vector<lli> &parents){
    if (parents[ind] != ind){
        printPath(parents[ind], parents);
    }
    cout << ind + 1 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);       
    cout << "The following algorithm is the implementation of A* algorithm.\n" << 
        "It takes a graph with nodes valued from 1 to n.\n" << 
        "Here n is the number of nodes.\n" <<
        "It takes a set of m undirected edges to build the graph.\n" << 
        "Afterwards, the heuristic value of each node is taken.\n" << 
        "Finally the algorithm takes the start node and end node, then it finds the shortest path using A* Path Finding Algorithm\n";
    lli n, m;
    lli start, end;
    prnt("Input number of nodes and edges: ");
    cin >> n >> m;
    map<lli, vector<pair<lli, lli>>> edges;
    prnt("Input the edges in the following format: node1 node2 weight");    
    forp1(m){
        lli a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }
    prnt("Input heuristic values for nodes 1, 2, 3.... n: ");
    vector<lli> nodeHValue(n);
    forp1(n){
        cin >> nodeHValue[i];
    }    
    prnt("Input Start and Destination Nodes: ");
    cin >> start >> end;
    start--, end--;

    vector<lli> parents(n);
    vector<lli> mnCost(n, LLONG_MAX);
    forp1(n){
        parents[i] = i;
    }
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;
    for (pair<lli, lli> e: edges[start]){
        pq.push({start, e.first, e.second, nodeHValue[e.first]});
    }
    mnCost[start] = nodeHValue[start];
    while (!pq.empty()){
        Edge e = pq.top();
        pq.pop();
        if (mnCost[e.node] > e.g + e.h){
            parents[e.node] = e.parent;
            mnCost[e.node] = e.g + e.h;
            for (pair<lli, lli> child: edges[e.node]){
                if (mnCost[child.first] > child.second + e.g + nodeHValue[child.first]){
                    pq.push({e.node, child.first, child.second + e.g, nodeHValue[child.first]});
                }
            }
        }    
    }
    if (parents[end] == end){
        prnt("Path not found");
    }
    else {
        cout << "The shortest path from " << start + 1 << " to " << end + 1 << " is:\n";
        printPath(end, parents);
        cout << "\n";
        cout << "The lenght of the shortest path is: " << mnCost[end] - nodeHValue[end] << "\n";

    }    

}
        