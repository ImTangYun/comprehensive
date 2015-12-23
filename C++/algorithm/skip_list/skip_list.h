//
// authored by yuntang
// time: 2015-12-21
//

#ifndef _SKIP_LIST_H_
#define _SKIP_LIST_H_

#include <stdlib.h>
#include <stdio.h>

#ifndef _WIN32
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#endif
namespace lab{

#define MAX_LEVEL 16

    template<typename K, typename V>
        struct IndexNode
        {
            IndexNode():pre_(NULL), next_(NULL), down_(NULL), value_(NULL)
            {
            }
            IndexNode* next_;
            IndexNode* down_;
            IndexNode* pre_;
            K key_;
            V* value_;
        };
    template<typename K, typename V>
        class IndexNodeIterator
        {
            public:
                IndexNodeIterator():node_(NULL){}
                IndexNodeIterator(IndexNode<K, V>* node):node_(node){}
                IndexNodeIterator operator=(IndexNode<K, V>* node);
                IndexNodeIterator operator++();
                IndexNodeIterator operator++(int32_t);
                IndexNodeIterator operator--();
                IndexNodeIterator operator--(int32_t);
                bool operator==(const IndexNodeIterator &iter);
                bool operator!=(const IndexNodeIterator &iter);
                // operator+();
                // operator-();
                IndexNode<K, V>* operator->();
            private:
                IndexNode<K, V>* node_;
        };
    template<typename K, typename V>
        inline IndexNodeIterator<K, V> IndexNodeIterator<K, V>::operator=(IndexNode<K, V>* node)
        {
            node_ = node;
            return *this;
        }
    template<typename K, typename V>
        inline IndexNodeIterator<K, V> IndexNodeIterator<K, V>::operator++()
        {
            node_ = node_->next_;
            return node_;
        }
    template<typename K, typename V>
        inline IndexNodeIterator<K, V> IndexNodeIterator<K, V>::operator++(int32_t)
        {
            IndexNode<K, V>* tmp = node_;
            node_ = node_->next_;
            return tmp;
        }
    template<typename K, typename V>
        inline IndexNodeIterator<K, V> IndexNodeIterator<K, V>::operator--()
        {
            node_ = node_->pre_;
            return node_;
        }
    template<typename K, typename V>
        inline IndexNodeIterator<K, V> IndexNodeIterator<K, V>::operator--(int32_t)
        {
            IndexNode<K, V>* tmp = node_;
            node_ = node_->pre_;
            return tmp;
        }
    template<typename K, typename V>
        inline IndexNode<K, V>* IndexNodeIterator<K, V>::operator->()
        {
            return node_;
        }
    template<typename K, typename V>
        inline bool IndexNodeIterator<K, V>::operator==(const IndexNodeIterator &iter)
        {
            return iter.node_ == node_;
        }
    template<typename K, typename V>
        inline bool IndexNodeIterator<K, V>::operator!=(const IndexNodeIterator &iter)
        {
            return iter.node_ != node_;
        }

    template<typename K, typename V>
        class skip_list
        {
            public:
                typedef IndexNodeIterator<K, V> iterator;

                skip_list();
                ~skip_list();
                bool add(K key, V value);
                bool remove(K key);
                bool contains(K key);
                IndexNode<K, V>* find(K key);
                V first();
                IndexNode<K, V>* begin();
                IndexNode<K, V>* end();
                V last();
                int32_t size();
                void dump();
                int32_t generate_random_level(int32_t max, int32_t min = 0);
            private:
                void insert_after(IndexNode<K, V>* pos, IndexNode<K, V>* to_insert);
                void insert_before(IndexNode<K, V>* pos, IndexNode<K, V>* to_insert);
                IndexNode<K, V>* remove_node(IndexNode<K, V>* node);
                IndexNode<K, V>* search_first_node(K key);

            private:
                int32_t size_;
                IndexNode<K, V>* head_;
                IndexNode<K, V>* tail_;
                int32_t max_level_;
                int32_t rand_count_;
        };
    template<typename K, typename V>
        void skip_list<K, V>::dump()
        {
            for (int32_t i = MAX_LEVEL - 1; i >= 0; --i) {
                IndexNode<K, V>* iter = (head_ + i)->next_;
                printf("head[%d]<->", i);
                while (iter != tail_ + i) {
                    printf("%d(%p)<->", iter->key_, iter->down_);
                    iter = iter->next_;
                }
                printf("tail[%d]\n", i);
            }
        }
    template<typename K, typename V>
        skip_list<K, V>::skip_list():max_level_(0), size_(0), rand_count_(0)
    {
#ifndef _WIN32
        struct timeval tpstart;
        gettimeofday(&tpstart,NULL);
        srand(tpstart.tv_usec);
#endif
        head_ = new IndexNode<K, V>[MAX_LEVEL];
        tail_ = new IndexNode<K, V>[MAX_LEVEL];
        head_[0].next_ = tail_;
        for (int32_t i = 0; i < MAX_LEVEL; ++i) {
            head_[i].next_ = tail_ + i;
            tail_[i].pre_ = head_ + i;
        }
    }
    template<typename K, typename V>
        int32_t skip_list<K, V>::size()
        {
            return size_;
        }
    template<typename K, typename V>
        IndexNode<K, V>* skip_list<K, V>::remove_node(IndexNode<K, V>* node)
        {
            if ((node >= head_ && node < head_ + MAX_LEVEL) ||
                    (node >= tail_ && node < tail_ + MAX_LEVEL)) {
                return tail_;
            }
            delete node->value_;
            IndexNode<K, V>* tmp = node->next_;
            node->pre_->next_ = node->next_;
            node->next_->pre_ = node->pre_;
            delete node;
            return tmp;
        }
    template<typename K, typename V>
        skip_list<K, V>::~skip_list()
        {
            int32_t level = max_level_;
            while (level >= 0) {
                IndexNode<K, V>* tmp = (head_ + level)->next_;
                while (tmp != tail_ + level) {
                    tmp = remove_node(tmp);
                }
                --level;
            }
        }
    template<typename K, typename V>
        inline IndexNode<K, V>* skip_list<K, V>::begin()
        {
            return head_->next_;
        }
    template<typename K, typename V>
        inline IndexNode<K, V>* skip_list<K, V>::end()
        {
            return tail_;
        }
    template<typename K, typename V>
        int32_t skip_list<K, V>::generate_random_level(int32_t max, int32_t min)
        {
            /*if (max == min) return max;
            if (rand_count_ > 100) {
                struct timeval tpstart;
                gettimeofday(&tpstart,NULL);
                srand(tpstart.tv_usec);
                rand_count_ = 0;
            }
            ++rand_count_;
            if (!(rand() % 13)) return generate_random_level(max, (max + min) / 2 + 1);
            return generate_random_level((max + min) / 2, min);*/
            int32_t i = min;
            while (i < max) {
                if (!(rand() % 2)) return i;
                ++i;
            }
            return max;
        }
    template<typename K, typename V>
        inline void skip_list<K, V>::insert_after(IndexNode<K, V>* pos, IndexNode<K, V>* to_insert)
        {
            to_insert->pre_ = pos;
            to_insert->next_ = pos->next_;
            pos->next_->pre_ = to_insert;
            pos->next_ = to_insert;
        }
    template<typename K, typename V>
        inline void skip_list<K, V>::insert_before(IndexNode<K, V>* pos, IndexNode<K, V>* to_insert)
        {
            to_insert->next_ = pos;
            to_insert->pre_ = pos->pre_;
            pos->pre_->next_ = to_insert;
            pos->pre_ = to_insert;
        }
    template<typename K, typename V>
        inline bool skip_list<K, V>::contains(K key)
        {
            return search_first_node(key) != tail_;
        }
    template<typename K, typename V>
        IndexNode<K, V>* skip_list<K, V>::search_first_node(K key)
        {
            if (size_ == 0) return tail_;
            if (key < head_->next_->key_ || key > tail_->pre_->key_) return tail_;
            int32_t level = max_level_;
            IndexNode<K, V>* tmp = (head_ + level)->next_;
            while (level >= 0) {
                if (tmp->key_ > key) {
                    while (tmp->pre_ != head_ + level && tmp->key_ > key) {
                        tmp = tmp->pre_;
                    }
                } else if (tmp->key_ == key) {
                    return tmp;
                } else {
                    while (tmp->next_ != tail_ + level && tmp->key_ < key) {
                        tmp = tmp->next_;
                    }
                }
                if (tmp->key_ != key) {
                    tmp = tmp->down_;
                    --level;
                }
            }
            return tail_;
        }
    template<typename K, typename V>
        bool skip_list<K, V>::remove(K key)
        {
            IndexNode<K, V>* tmp = search_first_node(key);
            if (tmp == tail_) return true;
            while (tmp != NULL) {
                IndexNode<K, V>* tmp1 = tmp->down_;
                remove_node(tmp);
                tmp = tmp1;
            }
            return true;
        }
    template<typename K, typename V>
        IndexNode<K, V>* skip_list<K, V>::find(K key)
        {
            IndexNode<K, V>* tmp = search_first_node(key);
            if (tmp == tail_) return tail_;
            while (tmp->down_ != NULL) {
                tmp = tmp->down_;
            }
            return tmp;
        }
    template<typename K, typename V>
        bool skip_list<K, V>::add(K key, V value)
        {
            IndexNode<K, V>* first = search_first_node(key);
            if (first != tail_) {
                while (first->down_ != NULL) {
                    first = first->down_;
                }
                delete first->value_;
                first->value_ = new V(value);
                return true;
            }
            int32_t level = generate_random_level(MAX_LEVEL - 1);
            IndexNode<K, V>* tmp = NULL;
            int32_t i = level;

            // first node in these levels
            for (; i >= 0 && head_[i].next_ == tail_ + i; --i) {
                IndexNode<K, V>* node = new IndexNode<K, V>();
                node->key_ = key;
                insert_after(head_ + i, node);
                if (tmp == NULL) {
                    tmp = node;
                    continue;
                }
                tmp->down_ = node;
                tmp = node;
            }

            // first node
            if (i < 0) {
                tmp->value_ = new V(value);
                // every level is the first node expect the level 0
            } else if (i == 0 && level != 0) {
                IndexNode<K, V>* iter = head_;
                while (iter->next_ != tail_ && iter->next_->key_ < key) {
                    iter = iter->next_;
                }
                IndexNode<K, V>* node = new IndexNode<K, V>();
                node->value_ = new V(value);
                node->key_ = key;
                insert_after(iter, node);
                if (tmp)
                    tmp->down_ = node;
                // some level first and some not
            } else {
                IndexNode<K, V>* tmp1 = tmp;
                tmp = head_[max_level_].next_;
                int32_t tmp_level = max_level_;
                if (tmp->key_ < key) {
                    while (tmp_level >= 0) {
                        while (tmp->key_ < key && tmp->next_ != tail_ + tmp_level) {
                            tmp = tmp->next_;
                        }
                        if (tmp_level <= level) {
                            IndexNode<K, V>* node = new IndexNode<K, V>();
                            node->key_ = key;
                            insert_after(tmp, node);
                            if (tmp1 != NULL) {
                                tmp1->down_ = node;
                            }
                            tmp1 = node;
                        }
                        if (tmp_level != 0)
                            tmp = tmp->down_;
                        --tmp_level;
                    }
                } else {
                    while (tmp_level >= 0) {
                        while (tmp->key_ > key && tmp->pre_ != head_ + tmp_level) {
                            tmp = tmp->pre_;
                        }
                        if (tmp_level <= level) {
                            IndexNode<K, V>* node = new IndexNode<K, V>();
                            node->key_ = key;
                            insert_before(tmp, node);
                            if (tmp1 != NULL) {
                                tmp1->down_ = node;
                            }
                            tmp1 = node;
                        }
                        if (tmp_level != 0)
                            tmp = tmp->down_;
                        --tmp_level;
                    }
                }
                tmp1->value_ = new V(value);
            }
            max_level_ = level > max_level_?level:max_level_;
            ++size_;
            return true;
        }
};

#endif
