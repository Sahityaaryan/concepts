#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int minMoves(vector<string>& classroom, int energy) {
    const int dr[] = {1,-1,0,0};
    const int dc[] = {0,0,1,-1};
    const int m = classroom.size();
    const int n = classroom[0].size();
    int start_r = -1, start_c = -1;

    vector<pair<int, int>> litter_coords;
    map<pair<int, int>, int> litter_coord_to_index;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            char current_letter = classroom[i][j];
            if(current_letter == 'L'){
                litter_coord_to_index[{i,j}] = litter_coords.size();
                litter_coords.push_back({i,j});
            }
            if(current_letter == 'S'){
                start_r = i;
                start_c = j;
            }
        }
    }

    // for(int i = 0; i)
    int litter_num = litter_coords.size();
    if(litter_num == 0) return 0;

    int target_mask = (1<<litter_num)-1;

    // minimum distance on the basis of (r,c,remainingEnergy, mask_we_got_so_far)
    vector<vector<vector<vector<int>>>> dist(m, vector<vector<vector<int>>>(n, vector<vector<int>>(energy+1, vector<int>(1<<litter_num, -1))));

    //
    queue<tuple<int, int, int, int>> q;

    dist[start_r][start_c][energy][0] = 0;

    q.push({start_r, start_c, energy, 0});


    while(!q.empty()){

        auto [curr_r, curr_c, curr_energy, curr_mask] = q.front();q.pop();

        int moves = dist[curr_r][curr_c][curr_energy][curr_mask];

        if(curr_mask == target_mask) return moves;

        for(int i = 0; i < 4; i++){

            int nr = curr_r + dr[i];
            int nc = curr_c + dc[i];

            if(nr >= 0 && nr < m && nc >=0  && nc < n && classroom[nr][nc] != 'X' && curr_energy > 0){
                int new_energy = curr_energy-1;
                int new_moves = moves+1;
                int new_mask = curr_mask;

                if(classroom[nr][nc] == 'L') {
                    int ind = litter_coord_to_index[{nr, nc}];
                    new_mask |= (1<<ind);
                }
                if(classroom[nr][nc] == 'R'){
                    new_energy = energy;
                }

                if(dist[nr][nc][new_energy][new_mask] == -1 || new_moves < dist[nr][nc][new_energy][new_mask]){
                    dist[nr][nc][new_energy][new_mask] = new_moves;
                    q.push({nr,nc,new_energy,new_mask});
                }
            }
        }
    }
    return -1;
}
};


int main(){

    return 0;
}
