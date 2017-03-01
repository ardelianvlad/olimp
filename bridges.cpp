#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


vector<int> *g;
bool *used;
int *tin, *fup;

int timer, n;

void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v])
				//IS_BRIDGE(v,to);
				cout << v << " " << to << endl;
		}
	}
}

void find_bridges() {
	timer = 0;
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs (i);
}

int main()
{
    ifstream fin("in.txt");
    int a, b;
    fin >> n;
    used = new bool[n];
    tin = new int[n];
    fup = new int[n];
    g = new vector<int>[n];
    for(int i=0; i<n; i++) {
        fin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fin.close();
    find_bridges();
    delete[] used;
    delete[] tin;
    delete[] fup;
    delete[] g;
    return 0;
}
