#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int calculate_ls_teams(int *array, int si, int ei, int x)
{
    int maximum_teams = 0;
    
    //~ printf("\n\ne: %d\n", ei);
    for(int i=si; i<ei; i++)
    {
        int tmp_size = (int)ceil((x*1.0)/array[i]);
        if(tmp_size > (ei-i)) 
        {
            // printf("%d Continue..\n", array[i]);
            continue;
        }
        // printf("%d :: i: %d, (e-i): %d, tmp_size: %.2f\n", array[i], i, (ei-i), tmp_size);
        
        int tmp_count = 1;
        
        for(int ni=i+tmp_size; ni<ei; ni+=tmp_size)
        {
            tmp_size = (int)ceil((x*1.0)/array[ni]);
            if(tmp_size <= (ei-ni))
            {
                // printf("\tni: %d, tmp_size: %.2f\n", ni, tmp_size);
                
                tmp_count+=1;
            }
            else tmp_size = 1;
        }
        
        if(tmp_count > maximum_teams) maximum_teams = tmp_count;
    }
    
    return maximum_teams;
}

bool cmp(int a, int b)
{
    return a > b;
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
        //~ for(auto x: array) printf("--> %d\n", x);
        int total_teams = 0;
        
        // seperate solo teams
        int spi;
        for(spi=n; spi>0; spi--){
            if(array[spi-1]>=x)
                continue;
            else
                break;
        }
        
        total_teams += n-spi;
        //~ printf("solo teams: %d\nspi: %d\n", total_teams, spi);
        
        total_teams += calculate_ls_teams(array, 0, spi, x);
        printf("%d\n", total_teams);
    }
    
    return 0;
}
