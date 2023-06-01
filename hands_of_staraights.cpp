/*
Alice has some cards, each card has one number written on it. She wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand of size N where hand [ i ] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
*/

bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        int x=groupSize;
        if(N%groupSize) return false;
        map<int,int> m;
        for(auto&it:hand) m[it]++;
        while(!m.empty()){
            auto it = m.begin();
            int e=it->first;
            m[it->first]--;
            if(m[it->first]==0) m.erase(it);
            int s(1);
            while(s<x){
                e++;
                if(m[e]==0) return false;
                m[e]--;
                if(m[e]==0) m.erase(e);
                s++;
            }
        }
        return true;
    }