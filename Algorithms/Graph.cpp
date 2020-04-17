Bipartite Graph Check:

bool bipartite(int u) {
	for(int x : adj[u]) {
		if(col[x] == -1) {
			col[x] = 1-col[u];
			if(!bipartite(x)) return false;
		} else if(col[x] == col[u]) return false;
	}
	return true;
}

//###############################################################################//

Topological Sort:

void topo(int u) {
	vis[u]=1;
	for(int x : adj[u]) if(!vis[x]) topo(x);
	ts.push_back(u);
}

void khan(int n) {
	queue<int> q;
	for(int i=1; i<=n; i++)
		if(income[i] == 0) q.push(i);
 
	while(!q.empty()) {
		int u = q.front(); q.pop();
		ans.push_back(u);
		for(int x : adj[u])
			if(--income[x] == 0) q.push(x);
	}
}

//###############################################################################//

SCC [Tarjan]:   // O(V + E)

void SCC(int u) {
	dfs_num[u] = dfs_low[u] = num++;
	in_stk[u] = 1; stk.push_back(u);
 
	for(int x : adj[u]) {
		if(dfs_num[x] == -1) SCC(x);
		if(in_stk[x]) dfs_low[u] = min(dfs_low[u], dfs_low[x]);
	}
	if(dfs_num[u] == dfs_low[u]) {
		while(1) {
			int v = stk.back(); stk.pop_back(); in_stk[v]=0;
			if(u == v) break;
		}
		scc++;
	}
}

//###############################################################################//

ArticulationPointAndBridge:     // O(V + E)

int dfs_num[MAX_N], dfs_low[MAX_N], dfs_parent[MAX_N];

void articulationPointAndBridge(int u) {
    dfs_num[u] = dfs_low[u] = num++;
    for (int v : adj[u]) {
        if (dfs_num[v] == -1) {
            if (u == dfsRoot) rootChildren++;
            
            dfs_parent[v] = u;
            articulationPointAndBridge(v);

            if (dfs_low[v] >= dfs_num[u]) //can't reach back
                articulation_vertex[u] = true;
            if (dfs_low[v] > dfs_num[u]) //can't reach back
                printf(" Edge (%d, %d) is a bridge\n", u, v);

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    } 
}

main() {
    ...
    for (int i = 0; i < V; i++)
        if (dfs_num[i] == -1) {
            dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1); 
        }
}

//###############################################################################//

Biconnected Components:     // O(V + E)
// connected && after removing any vertex remains connected

stack<pair<int, int> > st;

void Biconnected(int u) {
    dfs_num[u] = dfs_low[u] = num++;
    for (int v : adj[u]) {
        if (dfs_num[v] == -1) {
            if (u == dfsRoot) rootChildren++;

            dfs_parent[v] = u;
            st.push(make_pair(u,v));

            Biconnected(v);

            if ((u != dfsRoot && dfs_low[v] >= dfs_num[u]) || (u == dfsRoot && rootChildren > 1)) {
            	while(1) { //print the component
            		auto x = st.top(); st.pop();
            		cout << x.first << " " << x.second << endl;
            		if(x == make_pair(u,v)) break;
            	}
            	cout << endl;
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u] && dfs_num[v] < dfs_low[u]) { //back edge not added yet to the component
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            st.push(make_pair(u,v));
        }
    }
}

while(!st.empty()) { //last component
    auto x = st.top(); st.pop();
    cout << x.first << " " << x.second << endl;
}


//###############################################################################//

DSU:

class UnionFind {
    private: 
    vector<int> p, rank;
    public:
    UnionFind(int N) { 
        rank.assign(N, 0);
        p.assign(N, 0); 
        for (int i = 0; i < N; i++) p[i] = i; 
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;    // rank keeps the tree short
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++; 
            }
        }
    } 
};

//###############################################################################//

Mother Vertices [reachable from all other vertices]: `SPOJ - CAPCITY`

1) run Tarjan [SCC]
2) calc num of outgoing for all components
3) if more than one == 0 --> No mother
4) Mother vertices are the ones in the SCC with 0 outgoing

//###############################################################################//
//###############################################################################//

MST [Kruskal]:      // O(E log V)

vector< pair<int, pair<int, int> > > EdgeList;
for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    EdgeList.push_back(make_pair(w, make_pair(u, v))); 
}

sort(EdgeList.begin(), EdgeList.end());
int mst_cost = 0;
UnionFind UF(V);

for (int i = 0; i < E; i++) {
    pair<int, pair<int, int> > front = EdgeList[i];
    if (!UF.isSameSet(front.second.first, front.second.second)) {
        mst_cost += front.first;
        UF.unionSet(front.second.first, front.second.second);
    } 
}

//###############################################################################//

MST [Prim]:     // O(E log V)

vector<int> taken;
priority_queue<ii, vector<ii>, greater<ii> > pq;    //sort ascending

void process(int vtx) {
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        if (!taken[v.first]) pq.push(make_pair(v.second, v.first));
    } 
}
taken.assign(V, 0);
process(0);

mst_cost = 0;
while (!pq.empty()) {
    ii front = pq.top(); pq.pop();
    u = front.second, w = front.first;
    if (!taken[u])
        mst_cost += w, process(u);
}

//###############################################################################//
//###############################################################################//

SSSP [Unweighted Graph]:       // O(V + E)

void printPath(int u) {
    if (u == s) { printf("%d", s); return; }
    printPath(p[u]);
    printf(" %d", u);
}

vector<int> p;
vector<int> dist(V, INF); dist[s] = 0;
queue<int> q; q.push(s);

while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dist[v.first] == INF) {
            dist[v.first] = dist[u] + 1;
            p[v.first] = u;
            q.push(v.first);
        }
    } 
}
printPath(t), printf("\n");

//###############################################################################//

SSSP [Dijkstra]:        // O(E log V)
// can't handle negative cycles

vi dist(V, INF); dist[s] = 0;
priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s)); //sorted increasingly

while (!pq.empty()) {
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist[u]) continue; // this is a very important check (The Vertex might be processed before with better distance "d")
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dist[u] + v.second < dist[v.first]) {
            dist[v.first] = dist[u] + v.second; // relaxation
            pq.push(ii(dist[v.first], v.first));
        }
    }
} // this variant can cause "duplicate" items in the priority queue

//###############################################################################//

SSSP [BellmanFord]:     // O(VE)
//handles negative cycles

vi dist(V, INF); dist[s] = 0;
for (int i = 0; i < V - 1; i++) {  // relax all E edges V-1 times
    for (int u = 0; u < V; u++) { // these two loops = O(E), overall O(VE)
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j]; // record SP spanning here if needed
            dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
        }
    }
}

// after running the O(VE) Bellman Ford’s algorithm shown above
bool hasNegativeCycle = false;
for (int u = 0; u < V; u++) { // one more pass to check
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dist[v.first] > dist[u] + v.second) // if this is still possible
            hasNegativeCycle = true;
    }
}
printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");

//###############################################################################//

APSP [Floyd Warshall]:      // O(V^3)

//AdjMat[i][j] = (edge(i, j) || INF)
for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]); //Shortest Path (W || INF)
            AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]); //Transitive Closure [if every (i,j) is conn] (1 || 0)
            AdjMat[i][j] += AdjMat[i][k] * AdjMat[k][j]; //Counting Pathes (1 || 0)
            AdjMat[i][j] = min(AdjMat[i][j], max(AdjMat[i][k], AdjMat[k][j])); //Minimax (W || INF)

//Printing the Shortest Paths
for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
        p[i][j] = i;

for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]) { // this time, we need to use if statement
                AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
                p[i][j] = p[k][j]; // update the parent matrix
            }

void printPath(int i, int j) {
    if (i != j) printPath(i, p[i][j]);
    printf(" %d", j);
}

//###############################################################################//

To reverse shortest to longest just reverse the edges sign (+ TO -)

//###############################################################################//
//###############################################################################//

NetworkFlow :   "Edmonds Karp’s implementation of the Ford Fulkerson’s algo"

int res[MAX_V][MAX_V], mf, f, s, t;
vector<int> p; // p stores the BFS spanning tree from s

void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; }
    else if (p[v] != -1) { // we use else for the last case
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

mf = 0;
while (1) { // O(VE^2)
    f = 0;
    vi vis(MAX_V, 0); vis[s] = 1; queue<int> q; q.push(s);
    p.assign(MAX_V, -1); // record the BFS spanning tree, from s to t!
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break; // stop if we already reach sink t
        for (int v = 0; v < MAX_V; v++)
            if (!vis[v] && res[u][v] > 0)
                vis[v] = 1, q.push(v), p[v] = u;
    }
    augment(t, INF); // find the min edge weight if any
    if (f == 0) break; // mo flow, terminate
    mf += f;
}

printf("%d\n", mf);

//###############################################################################//

Unique Min Cut: `GYM 100200A`

1) First use a max-flow algorithm to find augmented path on residue graph.
2) On residue graph, find all nodes that are reachable from source. Mark this set of nodes White.
3) On residue graph, find all nodes from which it is possible to reach sink. Mark these nodes Black.
4) Min Cut is unique if sum of White and Black nodes is equal to total number of nodes.

//###############################################################################//

MCMF [Min Cost Max Flow]:

void augment(int v, ll minEdge) {
	if(v == s) {f = minEdge; return;}
	else if(p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f, res[v][p[v]] += f;
		cost[v][p[v]] = -cost[v][p[v]];
		cost[p[v]][v] = -cost[p[v]][v];
	}
}

//Shortest Path Faster Algorithm
bool spfa(int src, int sink) {
	queue<int> q; q.push(src);

	for(int i=0; i<=n; i++)
    	dist[i] = INF, used[i] = 0;

	dist[src] = 0, used[src] = 1, p[src] = src;

	while(!q.empty()) {
		int u = q.front(); q.pop();
		used[u] = 0;
		for(int v : adj[u]) {
			if(dist[u] + cost[u][v] < dist[v] && res[u][v] > 0) {
				p[v] = u;
				dist[v] = dist[u] + cost[u][v];
				if(!used[v]) q.push(v), used[v]=1;
			}
		}
	}

	return dist[sink] != INF;
}

while(spfa(s, t)) {
    augment(n, INF);
    totflow += f;
}

//###############################################################################//

MCMF on bipartite graph "assignment problem" [Hungarian algo]:      // O(N^3)

const int MAXN = 105;
const int INF = 1e9;

int n, m;
int a[MAXN][MAXN];
int u[MAXN], v[MAXN], link[MAXN], par[MAXN], used[MAXN], minval[MAXN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAXN; j++) {
            used[j] = false;
            minval[j] = INF;
        }
        int j_cur = 0;
        par[j_cur] = i;
        do {
            used[j_cur] = true;
            int j_next, delta = INF, i_cur = par[j_cur];
            for (int j = 0; j <= m; j++) 
                if (!used[j]) {
                    int cur = a[i_cur][j] - u[i_cur] - v[j];
                    if (cur < minval[j]) {
                        minval[j] = cur; link[j] = j_cur;
                    }
                    if (minval[j] < delta) {
                        delta = minval[j]; j_next = j;
                    }
                }
            for (int j = 0; j <= m; j++) 
                if (used[j]) {
                    u[par[j]] += delta; v[j] -= delta;
                }
                else {
                    minval[j] -= delta;
                }
            j_cur = j_next;
        } while (par[j_cur]);
        do {
            int j_prev = link[j_cur];
            par[j_cur] = par[j_prev];
            j_cur = j_prev;
        } while (j_cur > 0);
    }

    printf("%d", -v[0]); //final answer
    return 0;
}

//###############################################################################//

MCBM [Max Cardinality Bipartite Matching]:

vector<int> match, vis; // global variables

//left, right, left, right, ...
int Aug(int l) { // return 1 if an augmenting path is found
    if (vis[l]) return 0; // return 0 otherwise
    vis[l] = 1;
    for (int r : adj[l]) { //right set
        if (match[r] == -1 || Aug(match[r])) {
            match[r] = l; return 1; // found 1 matching
        }
    }
    return 0; // no matching
}

// inside int main()
// build unweighted bipartite graph with directed edge left->right set
int MCBM = 0;
match.assign(V, -1); // V is the number of vertices in bipartite graph
for (int l = 0; l < n; l++) { // n = size of the left set
    vis.assign(n, 0); // reset before each recursion
    MCBM += Aug(l);
}
printf("Found %d matchings\n", MCBM);

//###############################################################################//

MVC [Min Vertex Cover] = MCBM   "König's theorem"
MIS [Max Independent Set] = V - MCBM
MPC [Min Path Cover] = V - MABM "DAG"

//###############################################################################//

Eulerian Path [Hierholzer Algorithm]:       // O(V+E)
//visit every edge exactly once

void EulerTour(int u) {
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (v.second) { // if this edge can still be used/not removed
            v.second = 0; // make the weight of this edge to be 0 (‘removed’)
            for (int k = 0; k < (int)AdjList[v.first].size(); k++) { // remove bi-directional edge
                ii uu = AdjList[v.first][k];
                if (uu.first == u && uu.second) {
                    uu.second = 0;
                    break;
                } 
            }
            EulerTour(v.first);
        }
    }
    tour.push_back(u);
}

//###############################################################################//

DAG SSSP OR SSLP: "topo from source then dfs"
DAG longest path: "dfs with dp"

//###############################################################################//
//###############################################################################//

MVC [Min Vertex Cover On Tree]: //Tree becomes DAG

int MVC(int v, int flag) {
    int ans = 0;
    if (memo[v][flag] != -1) return memo[v][flag]; // top down DP
    else if (leaf[v])
        ans = flag; // 1/0 = taken/not
    else if (flag == 0) { // if v is not taken, we must take its children
        ans = 0;
        // Note: ‘Children’ is an Adjacency List that contains the
        // directed version of the tree (parent points to its children; but the
        // children does not point to parents)
        for (int j = 0; j < (int)Children[v].size(); j++)
            ans += MVC(Children[v][j], 1);
    }
    else if (flag == 1) { // if v is taken, take the minimum between
        ans = 1; // taking or not taking its children
        for (int j = 0; j < (int)Children[v].size(); j++)
            ans += min(MVC(Children.[v][j], 1), MVC(Children[v][j], 0));
    }
    return memo[v][flag] = ans;
}

//###############################################################################//

Tree Diameter:

1) run bfs from any node to get the farthest node "a"
2) run another bfs from "a" to get the farthest node "b"
3) diameter is the distance between a and b

//###############################################################################//

LCA [Lowest Common Ancestor]: //using SegmentTree

int E[2*n]; //euler tour
int L[2*n]; //depth
int H[n]; //first occurrence
int idx;

void dfs(int cur, int depth) {
    H[cur] = idx;
    E[idx] = cur;
    L[idx++] = depth;
    for(int i=0; i<children[cur].size(); i++) {
        dfs(children[cur][i], depth+1);
        E[idx] = cur;       // backtrack to current node
        L[idx++] = depth;
    }
}

void buildRMQ() {
    idx = 0;
    memset(H, -1, sizeof H);
    dfs(0, 0);  // we assume that the root is at index 0
}

E[RMQ(H[u], H[v])]  //RMQ on [E] to get the index of the item on lowest level

//###############################################################################//
//###############################################################################//

Fenwick Tree [Binary Indexed Tree] (BIT) "dynamic range query":

vector<int> ft;
ft.assign(n + 1, 0);

int LSOne(int i) {return (i & (-i));}
int query(int b) {      //query(1, b)
    int sum = 0;
    for(; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}
int query(int a, int b) {return query(b) - query(a-1);}   //1-based indexing    O(logN)
void update(int k, int v) {for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;}  //(v is inc/dec value)   O(logN)

//###############################################################################//

SegmentTree [Range sum query]:

int tree[4*MAX_N]{}; //worst case memory 
int arr[MAX_N]{}; //worst case memory 

void build(int p, int L, int R) {       // O(N)
    if(L == R)    // Leaf node will have a single element
        tree[p] = arr[L];
    else {
        int mid = (L+R)/2;
        build(p*2, L, mid);          // Recurse on the left child
        build(p*2+1, mid+1, R);      // Recurse on the right child
        tree[p] = tree[p*2] + tree[p*2+1];
    }
}

void update(int p, int L, int R, int idx, int val) {        // O(logN)
    if(L == R)
        tree[p] = val;
    else {
        int mid = (L + R)/2;
        if(idx <= mid)      //update left child
            update(p*2, L, mid, idx, val);
        else                //update right child
            update(p*2+1, mid+1, R, idx, val);
        tree[p] = tree[p*2] + tree[p*2+1];
    }
}

int query(int p, int L, int R, int i, int j) {          // O(logN)
    if(i > R || j < L)        //node is completely outside
        return 0;
    if(i <= L && R <= j)      //node is completely inside
        return tree[p];
    int mid = (L+R)/2;
    return (query(p*2, L, mid, i, j) +
            query(p*2+1, mid+1, R, i, j));
}

//To build: build(1, 0, n-1);
//To update: update(1, 0, n-1, idx, val);
//To query: query(1, 0, n-1, i, j);

//###############################################################################//

SegmentTree [Lazy propagation] "Update Interval":

//if lazy[node] != zero --> it needs to be updated
//(R - L + 1) --> interval length

void updateRange(int p, int L, int R, int i, int j, int val) {
    if(lazy[p] != 0) {
        tree[p] += (R - L + 1) * lazy[p];    //update it
        if(L != R) {
            lazy[p*2] += lazy[p];           //mark child as lazy
            lazy[p*2+1] += lazy[p];         //mark child as lazy
        }
        lazy[p] = 0;
    }
    if(L > R || i > R || j < L)
        return;
    if(i <= L && R <= j) {
        tree[p] += (R - L + 1) * val;
        if(L != R) {
            lazy[p*2] += val;
            lazy[p*2+1] += val;
        }
        return;
    }
    int mid = (L + R) / 2;
    updateRange(p*2, L, mid, i, j, val);
    updateRange(p*2 + 1, mid + 1, R, i, j, val);
    tree[p] = tree[p*2] + tree[p*2+1];
}

int queryRange(int p, int L, int R, int i, int j) {
    if(i > R || j < L) return 0;
    if(lazy[p] != 0) {
        tree[p] += (R - L + 1) * lazy[p];            //update it
        if(L != R) {
            lazy[p*2] += lazy[p];         //mark child as lazy
            lazy[p*2+1] += lazy[p];       //mark child as lazy
        }
        lazy[p] = 0;
    }
    if(i <= L && R <= j)
        return tree[p];
    int mid = (L + R) / 2;
    int p1 = queryRange(p*2, L, mid, i, j);
    int p2 = queryRange(p*2 + 1, mid + 1, R, i, j);
    return (p1 + p2);
}

//###############################################################################//

Sparse Table:
//keep splitting arr to subs of len 2^j (j >= 0)
//dp (table method)

const int N = 1e5;
const int k = 16;
long long table[N][k + 1];
int arr[N];

//build
for(int i = 0; i < n; i++)
    table[i][0] = F(arr[i]);
for(int j = 1; j <= k; j++) {
    for(int i = 0; i + (1 << j) <= n; i++)
        table[i][j] = F(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}

//query segment [L,R]
for(int j = k; j >= 0; j--) {
    if(L + (1 << j) - 1 <= R) {
        ans = F(ans, table[L][j]);
        //ans = ans + table[L][j]       (Range sum query)
        //ans = min(ans, table[L][i])   (Range minimum query)
        L += 1 << j;
    }
}

//another way to query
int x = floor(log2(R-L+1);
return F(table[L][x], table[R-(1<<x)+1][x]);

//###############################################################################//
//###############################################################################//
