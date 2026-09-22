class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int count;
    int cap;
public:
    MyCircularQueue(int k) : data(k), head(0), count(0), cap(k){
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        data[(head+count)%cap] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        head = (head+1)%cap;
        count--;
        return true;
    }
    
    int Front() {
        if(!isEmpty()){
            return data[head];
        }
        return -1;
    }
    
    int Rear() {
        if(!isEmpty()){
            return data[(head+count-1)%cap];
        }
        return -1;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */