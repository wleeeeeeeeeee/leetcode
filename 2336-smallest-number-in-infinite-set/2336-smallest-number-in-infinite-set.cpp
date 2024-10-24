class SmallestInfiniteSet {
private :
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> vec;
public:
    SmallestInfiniteSet() {
        vec.assign(1001,1);    
        for(int i = 1; i <= 1000;i++){
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int answer = 0;
        if(!pq.empty()){
            answer = pq.top();
            vec[answer] -= 1;
            pq.pop();    
        }
        return answer;
    }
    
    void addBack(int num) {
        if(vec[num] == 0){
            pq.push(num);
            vec[num] += 1;
        }
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */