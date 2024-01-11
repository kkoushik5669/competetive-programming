#include <iostream>
 
int const lgmax = 20;
int const nmax = 200000;
int far[1 + lgmax][1 + nmax];
int level[1 + nmax];
 
int getLca(int x, int y) {
  if(level[x] < level[y])
    std::swap(x, y);
  for(int h = lgmax; 0 <= h; h--)
    if(level[y] + (1 << h) <= level[x])
      x = far[h][x];
  if(x == y)
    return x;
  for(int h = lgmax; 0 <= h; h--)
    if(far[h][x] != far[h][y]) {
      x = far[h][x];
      y = far[h][y];
    }
  return far[0][x];
}
 
int main() {
  int n, q;
  std::cin >> n >> q;
  for(int i = 2;i <= n; i++)
    std::cin >> far[0][i];
 
  for(int h = 1; h <= lgmax; h++)
    for(int i = 1;i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
 
  for(int i = 2;i <= n; i++)
    level[i] = level[far[0][i]] + 1;
 
  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    std::cout << getLca(x, y) << '\n';
  }
}
