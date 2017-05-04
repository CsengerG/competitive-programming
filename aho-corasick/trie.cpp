#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(int)n;++i)

using namespace std;

const int alph_size = 30; // size of the alphabet

struct Node {
    char c;

    int parent;
    int children[alph_size];

    int ends; // how many words end here

    Node(){
        parent = -1;
        ends = 0;
        c = '#';
        FOR(i,alph_size) children[i]=-1;
    }
    Node(int _parent, int _ends, char _c){
        parent = _parent;
        ends = _ends;
        c = _c;
        FOR(i,alph_size) children[i]=-1;
    }
};

vector<Node> trie;

void addString(string s){
    int currNode = 0; // first node is the root

    FOR(i,s.size()){
        char c = s[i]-'a'; // next character

        if( trie[currNode].children[c] == -1 ){ // if node doesn't exist, create it
            trie[currNode].children[c] = trie.size();

            if(i==s.size()-1) trie.push_back(Node(currNode,1,s[i]));
            else trie.push_back(Node(currNode,0,s[i]));
        } else {
            int child = trie[currNode].children[c];
            if(i==s.size()-1) trie[child].ends++;
        }
        
        currNode = trie[currNode].children[c];
    }
}

int main(){
    // create root
    trie.push_back(Node());

    addString("aaaa");
    addString("aabcd");
    addString("abcde");
    addString("abcdf");

    FOR(i,trie.size()){
        cout << trie[i].c << " ";
    }
}
