/*/
 * author: mash-97
 * purpose: checks if the team is allowed according to the problem
 * warning: uses copy for independency
/*/
bool is_allowed_team(vector<int> team, int x)
{
    vector<int> ct(team.size());
    copy(team.begin(), team.end(), ct.begin());
    sort(ct.begin(), ct.end());
    
    return (ct[0]*(int)ct.size()) >= x ? true : false;
}


/*/
 * author: mash-97
 * purpose: returns combination of possible teams
 * warning: it uses 2**n, where n is the number of available teams
/*/
vector<vector<vector<int>>> get_possible_teams(vector<vector<int>> teams, int x)
{
    vector<vector<vector<int>>> comb_teams;
    int n = (int)teams.size();
    for(int i=0; i<(2<<n); i++)
    {
        vector<vector<int>> tmp_teams;
        for(int j=0; j<n; j++){
            if((i&(1<<j))){
                if(is_allowed_team(teams[j], x))
                    tmp_teams.push_back(teams[j]);
                else{
                    tmp_teams = {};
                    break;
                }
            }
        }
        
        if((int)tmp_teams.size()!=0)
            comb_teams.push_back(tmp_teams);
    }
    
    return comb_teams;
}



vector<vector<vector<vector<int>>>> get_satisfied_teams(vector<vector<vector<int>>> possible_teams)
{
    map<int, vector<vector<vector<vector<int>>>>> dicta;
    int max_t = -1;
    
    for(auto vvv: possible_teams)
    {
        if((int)vvv.size()>= max_t){
            if(!dicta[max_t])
            {
                vector<vector<vector<vector<int>>>> tv;
                dicta[max_t] tv;
            }
            dict[max_t].push_back(vvv);
            max_t = vvv.size();
        }
    }
    return dicta[max_t];
}
