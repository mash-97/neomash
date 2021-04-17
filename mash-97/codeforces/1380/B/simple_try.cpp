#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    char bot_string[200001];
    scanf("%s", bot_string);
    int length = (int)strlen(bot_string);
    int r = 0;
    int s = 0;
    int p = 0;
    for(int i=0; i<length; i++)
    {
      if(bot_string[i]=='R') r++;
      else if(bot_string[i]=='S') s++;
      else if(bot_string[i]=='P') p++;
    }
    
    char r_char='P';
    if(r>=s && r>=p) r_char = 'P';
    if(s>=r && s>=p) r_char = 'R';
    if(p>=s && p>=r) r_char = 'S';
    for(int i=0; i<length; i++)
      printf("%c", r_char);
    printf("\n");
  }
  return 0;
}
