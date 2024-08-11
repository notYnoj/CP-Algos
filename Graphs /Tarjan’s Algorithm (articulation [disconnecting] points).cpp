/* Articulation points are points where when removed causes a graph to be disconnected:
*/

/* Idea is to DFS and check if u is a root node and has 2 children it is an articulation point
otherwise if u is a node with child v and doesnt have any back edges than it is an articulation point

Algo:
*/
vector<vector<int>> grid; //assumin this is populated
vector<bool> visited; // assumin this is populated
vector<int> low, disc;
int time = 0;
void Tarjan(int u, int p = -1 //the usual u and p, vector<int>& art //stores articulation points){
  int child = 0; //children (first point)
  visited[u] = true;
  disc[u] = low[u] = ++time;
  for(auto i: grid[u]){
    if(!visted[v]){
      children++;
      Tarjan(i, u, art);
      low[u] = min(low[u], low[v]); //making lowest possible
      if(parent != -1 && low[v]>=disc[u]){
        art.push_back(u);
      }
    }else if(v!=parent){
      low[u] = min(low[u], disc[v]);// lower value of u for back edges
    }
    
  }
  if (parent == -1 && children > 1)
          isAP[u] = true; //first case
  
  }
