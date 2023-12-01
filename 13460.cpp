#include<iostream>
#include<queue>
using namespace std;

struct step{
  int Rx, Ry;
  int Bx, By;
  int Count;
};

char map[11][11];
bool visit[11][11][11][11];
int N, M;
int dx[] = {1, -1, 0, 0};
ind dy[] = {0, 0, 1, -1};

void move(int& rx, int& ry, int & distance, int& i)
{
  while(map[rx+dx[i]][ry+dy[i]!='#' && map[rx][ry] != 'O')
  {
  rx += dx[i];
  ry += dy[i];
  distance += 1;
  }
}

void BFS(int Rx, int Ry, int Bx, int By){
  queue<step> q;
  q.push({Rx, Ry, Bx, By, 0});
  visit[Rx][Ry][Bx][By];
  while(!q.empty()){
    int rx = q.front().Rx;
    int ry = q.front().Ry;
    int bx = q.front().Bx;
    int by = q.front().By;
    int count = q.front().Count;
    q.pop();
    if(count >= 10) break;
    for(int i=0;i<4;i++){
      int nRx=rx, nRy=ry, nBx=bx, nBy=by;
      int Rc=0;, Bc=0, ncount = count + 1;
      move(nRx, nRy, Rc, i);
      move(nBx, nBy, Bc, i);
      if(map[nBx][nBy]=='O')continue;
      if(map[nRx][nRy]=='O'){
        cout << ncount;
        return;
      }
      if(nRx==nBx && nRy==nBy){
        if(Rc>Bc) nRx -= dx[i], nRy -= dy[i];
        else nBx -= dx[i], nBy -= dy[i];
      }
      if(visit[nRx][nRy][nBx][nBy]) continue;
      visit[nRx][nRy][nBx][nBy] = true;
      q.push({nRx, nRy, nBx, nBy, ncount});
    }
  }
  cout << -1;
}

void Answer(){
  cin >> N >> M;
  int Rx = 0, Ry =0, Bx=0, By=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> map[i][j];
      if(map[i][j]=='R'){
        Rx=i;Ry=j;
      }
      else if(map[i][j]=='B'){
        Bx=i, By=j;
      }
    }
  }
  BFS(Rx, Ry, Bx, By);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); 
  Answer();
  return 0;
}

