#include "bits/stdc++.h"
using namespace std;

const int maxc=100;
const int maxf=1000000;
const int maxp=100000;

set< pair<int,int> > coins;

pair<int, int> random_coin(int p);

int main(int argc, char** argv){
  int f = 10000;
  int c = 10;
  int p = 500;
  if(argc > 1){
    f = atoi(argv[1]);
    if(f>maxf)
      f = maxf;
  }
  if(argc > 2){
    c = atoi(argv[2]);
    if(c>maxc)
      c = maxc;
  }
  if(argc > 3){
    p = atoi(argv[3]);
    if(p>maxp)
      p=maxp;
  }

  srand (time(NULL));

  printf("%d\n", f);
  printf("%d\n", c);
  pair<int, int> coin = random_coin(p);
  for(int i=0; i<c; i++){
    while(coins.count(coin))
      coin = random_coin(p);
    coins.insert(coin);
    printf("%d %d\n", coin.first, coin.second);
  }
}

pair<int, int> random_coin(int p){
  pair<int, int> coin;
  int mult;
  coin.first = (rand()%p)+1;
  mult = rand()%41 + 80;
  coin.second = coin.first*mult/100;
  if(coin.second > p)
    coin.second = p;
  if(coin.second < 1)
    coin.second = 1;
  return coin;
}
