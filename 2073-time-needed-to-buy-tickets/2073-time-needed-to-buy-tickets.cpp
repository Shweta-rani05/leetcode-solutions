class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        for(int i = 0 ; i<tickets.size();i++){
            q.push(i);
        }
        int timeNeeded = 0;
        while(!q.empty()){
            timeNeeded++;
            int idFront = q.front();
            q.pop();
            tickets[idFront]--;

            if(k == idFront && tickets[idFront]==0) return timeNeeded;
            if(tickets[idFront] != 0) q.push(idFront);
        }
         return timeNeeded;
    }
   
};