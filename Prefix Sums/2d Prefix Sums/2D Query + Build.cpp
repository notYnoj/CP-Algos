
/* 2D prefix sums are rather simple in which they fall very similar to normal prefix sum (if u want for (i,j) to have (i,j) u can do -1 (if i!=0 || j!=0)
  or if u want i+1, j+1 to have i,j u can do i+1, j+1 when doing prefix sums (no need for previous if statement)

However querying and updating is a bit harder 
#define ll long long
Query:
auto query = [&](int from_x, from_y, to_x, to_y) ->long long{
  ll sum = 0;
  sum+=pref[to_x+1][to_y+1];
  sum-=pref[to_x+1][from_y];
  sum-=pref[from_x][to_y+1];
  sum+=pref[from_x][from_y];
  return sum;
};

auto build = [&](int i, int j) {
  pref[i+1][j+1] = (grid[i][j] + pref[i][j+1] + pref[i+1][j] - pref[i][j]);
};
*/
