class Solution {
public:
    
    
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int room_num){
        visited[room_num] = true;
        if(rooms[room_num].empty()){
            return;
        }
        for(int room_keys : rooms[room_num]){
            if(!visited[room_keys]){
                dfs(rooms,visited, room_keys);
            }
        }
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        dfs(rooms,visited,0);
        bool answer = true;
        for(bool visit : visited){
            if(!visit){
                answer &= visit;
            }
        }
        return answer;
    }
};