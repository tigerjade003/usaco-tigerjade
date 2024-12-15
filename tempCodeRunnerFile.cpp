 if(x < 0 || y < 0 || x >= N || y >= N) return false;
    if(visited[x][y] || unusable[x][y]) return true;
    if(x == 0 || y == 0 || x == N || y == N) return false;