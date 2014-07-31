
struct ListNode_
{
    int val;
    int key;
    ListNode_* pre;
    ListNode_* next;
    ListNode_(int k, int v):key(k),val(v),pre(NULL),next(NULL){}
};
class LRUCache{
private:
    int capacity_;
    int size_;
    unordered_map<int, ListNode_*> k_v;
    ListNode_* head_;
    ListNode_* tail_;
public:

    LRUCache(int capacity) {
        capacity_ = capacity;
        size_ = 0;
        head_ = NULL;
        tail_ = NULL;
    }
    
    int get(int key) {
        unordered_map<int, ListNode_*>::iterator iter = k_v.find(key);
        if (iter != k_v.end()) {
            
            int value = iter->second->val;
            MoveToHead(iter->second);
            return value;
        } else return -1;
    }
    
    void set(int key, int value) {
        unordered_map<int, ListNode_*>::iterator iter = k_v.find(key);
        if (iter != k_v.end()) {
            iter->second->val = value;
            MoveToHead(iter->second);
        } else {
            ++size_;
            if (head_ == NULL) {
                head_ = new ListNode_(key,value);
                tail_ = head_;
                k_v[key] = head_;
            } else {
                ListNode_* p = new ListNode_(key,value);
                k_v[key] = p;
                InsertFromHead(p);
            }
            if (size_ > capacity_) {
                if (size_ == 0) {
                    delete head_;
                    head_ = NULL;
                    tail_ = NULL;
                } else {
                    k_v.erase(k_v.find(tail_->key));
                    tail_ = tail_->pre;
                    delete tail_->next;
                    tail_->next = NULL;
                }
                --size_;
            }
        }
    }
    void InsertFromHead(ListNode_* p) {
        p->next = head_;
        head_->pre = p;
        head_ = p;
    }
    void MoveToHead(ListNode_* p) {
        if (p == head_) return;
        if (p == tail_) {
            tail_ = p->pre;
            p->pre = NULL;
            ListNode_* tmp = head_;
            head_ = p;
            p->next = tmp;
            tmp->pre = p;
            tail_->next = NULL;
            return;
        }
        p->next->pre = p->pre;
        p->pre->next = p->next;
        ListNode_* tmp = head_;
        head_ = p;
        p->next = tmp;
        tmp->pre = p;
        head_->pre = NULL;
    }
};
