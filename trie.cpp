#include <bits/stdc++.h>

using namespace std;

struct node {
    bool end = false;
    int index = -1;
    vector<node*> child = vector<node*>(26,NULL); // array of next node pointers from current node
};

// works on lowecase strings only
class Trie{
    public:
        node* root;
        Trie(vector<string> arr){
            root = new node();
            for(int s_i=0; s_i<arr.size(); s_i++){
                string s = arr[s_i];
                node* curr = root;
                int i=0;
                for(; i<s.length(); i++){
                    if( curr->child[s[i]-'a'] == NULL )
                    {
                        curr->child[s[i]-'a'] = new node();
                    }
                    curr = curr->child[s[i]-'a'];
                }
                i--;
                curr->end = true;
                curr->index = s_i; 
            }
        }
        bool has(string s){
            node* curr = root;
            for(int i=0; i<s.length(); i++){
                if(curr->child[s[i]-'a'] == NULL)
                    return false;
                curr = curr->child[s[i]-'a'];
            }
            return true;
        }
};

int main(){
    vector<string> l = {"abcd", "bcds", "cdsf"};
    Trie t = Trie(l);
    cout << t.has("ad") << endl;
    return 0;
}
