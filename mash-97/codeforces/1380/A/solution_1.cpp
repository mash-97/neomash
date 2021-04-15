#include <iostream>
#include <cstdio>

int main(){
  int T;
  scanf("%d", &T);
  
  while(T--){
    int n;
    scanf("%d", &n);
    int nums[n];
    
    for(int i=0; i<n; i++)
      scanf("%d", &nums[i]);
    
    int possible = 0;
    int i, j;
    for(i=0; i<n-2; i++)
    {
      for(j=i+1; j<n-1; j++)
      {
	if(nums[i]<nums[j] && nums[j]>nums[j+1]){
	  possible = 1;
	  break;
	}
      }
      if(possible) break;
    }
    
    if(possible){
      printf("YES\n");
      printf("%d %d %d\n", i+1, j+1, j+2);
    }
    else printf("NO\n");
  }
  
  return 0;
}
