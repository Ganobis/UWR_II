#include "bits/stdc++.h"
using namespace std;

const int maxc=107;

int F, C;
pair <int, int> M[maxc];

int main(){
  scanf("%d%d", &F, &C);
  for(int i=0; i<C; i++)
    scanf("%d%d", &M[i].first, &M[i].second);
  char answer[3];
  scanf("%s", answer);
  if(!strcmp(answer, "NIE")){
    printf("NIE\n");
    return 0;
  }
  int sum=0;
  long long declared_value_mini;
  long long actual_value=0;
  int amount;
  scanf("%lld", &declared_value_mini);
  for(int i=0; i<C; i++){
    scanf("%d", &amount);
    actual_value += amount*M[i].first;
    sum += amount*M[i].second;
  }
  if(sum != F){
    printf("Sumaryczna waga wypisanych monet nie jest równa F (minimum)\n");
    printf("Otrzymano: %d\n", sum);
    printf("Oczekiwano: %d\n", F);
    return 1;
  }
  if(actual_value != declared_value_mini){
    printf("Sumaryczna wartość wypisanych monet nie zgadza się (minimum)\n");
    printf("Otrzymano: %lld\n", actual_value);
    printf("Oczekiwano: %lld\n", declared_value_mini);
    return 1;
  }

  long long declared_value_maxi;
  actual_value=0;
  sum=0;
  scanf("%lld", &declared_value_maxi);
  for(int i=0; i<C; i++){
    scanf("%d", &amount);
    actual_value += amount*M[i].first;
    sum += amount*M[i].second;
  }
  if(sum != F){
    printf("Sumaryczna waga wypisanych monet nie jest równa F (maximum)\n");
    printf("Otrzymano: %d\n", sum);
    printf("Oczekiwano: %d\n", F);
    return 1;
  }
  if(actual_value != declared_value_maxi){
    printf("Sumaryczna wartość wypisanych monet nie zgadza się (maxium)\n");
    printf("Otrzymano: %lld\n", actual_value);
    printf("Oczekiwano: %lld\n", declared_value_maxi);
    return 1;
  }

  printf("TAK\n");
  printf("%lld\n", declared_value_mini);
  printf("%lld\n", declared_value_maxi);
}
