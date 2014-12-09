/**
 *字典树
 */
#include <stdio.h>
#include <vector>

#define NUM 26
using std::vector;
class Node
{
public:
    Node *next[NUM];
    int count;
    char c;
    bool end;
    Node():count(0),end(false)
    {
        for (int i = 0; i < NUM; ++i) {
            next[i] = NULL;
        }
    }
};

class Trie
{
public:
    Trie():root(new Node())
    {
    }
    void Insert(const char* str);
    void Print();
private:
    void PrintInorder(Node* root, vector<char> &temp);
    Node* root;
};

void Trie::Insert(const char* str)
{
    if (str == NULL) return;
    Node* p = root;
    while (*str != '\0') {
        int index = *str - 'a';
        if ((p->next)[index] == NULL) {
            (p->next)[index] = new Node();
            (p->next)[index]->c = *str;
            (p->next)[index]->count = p->count + 1;
        }
        if (*(str + 1) == '\0') (p->next)[index]->end = true;
        ++str;
        p = (p->next)[index];
    }
}

void Trie::PrintInorder(Node *root, vector<char> &temp)
{
    for (int i = 0; i < NUM; ++i) {
        if ((root->next)[i] != NULL) {
            temp.push_back((root->next)[i]->c);
            if ((root->next)[i]->end) {
                for (int i = 0; i < temp.size(); ++i) {
                    printf("%c", temp[i]);
                }
                printf("\n");
            }
            PrintInorder((root->next)[i], temp);
            temp.pop_back();
        }
    }
}

void Trie::Print()
{
    vector<char> temp;
    PrintInorder(root, temp);
}
int main()
{
    printf("hello world\n");
    Trie T;
    T.Insert("a");
    T.Insert("ab");
    T.Insert("ac");
    T.Insert("bbc");
    T.Insert("cbc");
    T.Insert("dbc");
    T.Print();
    return 0;
}

