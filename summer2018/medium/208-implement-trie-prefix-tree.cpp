// 59ms

struct node {
    int end_of_string;
    struct node *child[26];
};

class Trie {
public:
    
    struct node *root = NULL;
    /** Initialize your data structure here. */
    Trie() {
        root = newNode();
    }
    
    struct node *newNode()
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->end_of_string = 0;
        
        int i;
        for (i = 0; i < 26; i++) {
            newnode->child[i] = NULL;
        }
        
        return newnode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.length();
        int i, index;
        struct node *ptr = root;
        
        for (i = 0; i < n; i++) {
            index = word[i]-'a';
            if (!ptr->child[index])
                ptr->child[index] = newNode();
            ptr = ptr->child[index];
        }
        
        ptr->end_of_string = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.length();
        int i, index;
        struct node *ptr = root;
        
        for (i = 0; i < n; i++) {
            index = word[i]-'a';
            if (ptr->child[index])
                ptr = ptr->child[index];
            else
                return false;
        }
        
        if (ptr != NULL && ptr->end_of_string == 1)
            return true;
        else
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.length();
        int i, index;
        struct node *ptr = root;
        
        for (i = 0; i < n; i++) {
            index = prefix[i]-'a';
            if (ptr->child[index])
                ptr = ptr->child[index];
            else
                return false;
        }
        
        if (ptr != NULL)
            return true;
        else
            return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */


