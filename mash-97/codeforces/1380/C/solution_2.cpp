#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int calculate_ls_teams(int *array, int n, int x)
{
    int total_teams = 0;
    
    for(int i=n-1, ac=1; i>=0;i--, ac++)
    {
        int _ = array[i]*ac;
        
        if(_ >= x) 
        {
            total_teams += 1;
            ac = 0;
        }
    }
    return total_teams;
    
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int n,x;    
        scanf("%d %d", &n, &x);
        
        int array[n];
        for(int i=0; i<n; i++)
            scanf("%d", &array[i]);
            
        sort(array, array+n);
        
        int total_teams = calculate_ls_teams(array, n, x);
        printf("%d\n", total_teams);
    }
    
    return 0;
}
