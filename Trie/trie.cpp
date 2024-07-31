#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <assert.h> 
#include <cstring>


using namespace std ; 

class Trie{
    private :
    
    static const int MAX_CHAR = 26;
    Trie* child[MAX_CHAR];
    bool isLeaf {};

    public :

    Trie()
    {
        memset(child, 0, sizeof(child));
    }

    void insert(string str , int idx = 0 )
    {
        if(idx == (int)str.size())
        isLeaf = true;
        else {
        int cur = str[idx] - 'a';
        if(child[cur] == 0)
        child[cur] = new Trie();
        
        child[cur]->insert(str,idx+1);
        }
    }

    bool prefixExist(string str , int idx = 0)
    {
        if(idx == (int)str.size())
        {
            return true;
        }

        int cur = str[idx] - 'a';
        if(!child[cur])
        return false;

        return child[cur]->prefixExist(str,idx+1);
    }

   ////////////////////////////////// homework 1 ///////////////////////////////////////////

   //  hw1 p2 : 
   string firstWordPrefix(string str)
   {
     Trie* cur = this;
     
     for(int idx = 0 ; idx<(int)str.size() ; idx++)
     {
        int pos = str[idx] - 'a';

        if(!cur->child[pos])
        break;

        if(cur->child[pos]->isLeaf)
        return str.substr(0,idx+1);

        cur = cur->child[pos];
     }

     return str;

   }


   //////////////////////// homewrok 2 /////////////////////////////////////////////

   // hw2 p1 : 

   void get_all_strings(vector<string>& res , string str = "") //o(NL) time , N is number of words while L is the length of the word 
   {

    if(isLeaf)
        res.push_back(str);
    
    for(int i = 0 ; i<MAX_CHAR ; i++)
    {
        if(child[i])
        {
            child[i]->get_all_strings(res,str+(char)(i+'a'));
        }
    }

   }
   
   // hw2 p2 : 

   void auto_complete(const string &str, vector<string>&res)
   {
     Trie* cur = this ; 
     for(int idx = 0 ; idx < (int)str.size() ; idx++)
     {
        int pos = str[idx] - 'a';
        if(!cur->child[pos])
        return;


        cur = cur->child[pos];
       
     }
     
     
      
    cur->get_all_strings(res,str);


   }

   // hw2 p3 : 
   















   
 


};


 // hw1  p 3 : 
   class suffixTrie{
    private : 

    static const int MAX_CHAR=26;
    suffixTrie* child[MAX_CHAR];
    bool isLeaf {};


    public : 

    
    suffixTrie()
    {
        memset(child, 0, sizeof(child));
    }

    void insert(string str)
    {
        suffixTrie* cur = this ;
         
        for(int idx = (int)str.size()-1; idx >=0 ; --idx )
        {
            int pos = str[idx] - 'a';

            if(cur->child[pos] == 0)
            cur->child[pos] = new suffixTrie();

            cur = cur->child[pos];
        }
        cur->isLeaf = true;
       
    }

    bool suffixExist(string str )
    {
        suffixTrie* cur = this;
        for(int idx = (int)str.size()-1; idx>=0; --idx)
        {
            int pos = str[idx] - 'a';
            if(!cur->child[pos])
            return false;

          cur = cur->child[pos];
        }

        return true;
    }

   };


 // hw1 P4 :

   class Trie_using_map {
    private :

    map<int,Trie_using_map*> child;
    bool isLeaf{};

    public: 

    Trie_using_map(){

    }

    void insert(string str)
    {
        Trie_using_map* cur = this ;

        for(int idx = 0 ; idx < (int)str.size() ; idx++)
        {
            int pos = str[idx] - 'a';

            if(!cur->child.count(pos))
            cur->child[pos] = new Trie_using_map();

            cur = cur->child[pos];
        }
        cur->isLeaf = true ;
    }

    bool wordExist(string str)
    {
        Trie_using_map* cur = this ;

        for(int idx = 0  ; idx<(int)str.size() ; idx++)
        {
            int pos = str[idx] - 'a';
            if(!cur->child.count(pos))
            return false;

            cur = cur->child[pos];
        }

        return cur->isLeaf;
    }

   };

// hw1 p5 : 

   class OsPathTrie {
    private :

    map<string , OsPathTrie*> child;
    bool isLeaf{};

    public: 

    OsPathTrie(){

    }

    void insert(vector<string> path)
    {
        OsPathTrie* cur = this ;

        for(int p = 0 ; p < (int)path.size() ; p++)
        {
            string subPath = path[p];
            if(!cur->child.count(subPath))
            cur->child[subPath] = new OsPathTrie();

            cur = cur->child[subPath];
        }
        cur->isLeaf = true ;
    }

    bool subPathExist(vector<string> subPath)
    {
        OsPathTrie* cur = this ;

        for(int s = 0  ; s <(int)subPath.size() ; s++)
        {
            string word = subPath[s];
            if(!cur->child.count(word))
            return false;

            cur = cur->child[word];
        }

        return true;
    }


   };


   

int main ()
{
    /*
    OsPathTrie t;
    t.insert({"opt", "software", "python"});
    t.insert({"opt", "software", "java"});
    t.insert({"opt", "games"});

    assert(t.subPathExist({"opt"}) == true);  
    assert(t.subPathExist({"opt", "software"}) == true);  
    assert(t.subPathExist({"opt", "software", "python"}) == true);  
    assert(t.subPathExist({"opt", "software", "ruby"}) == false); 

    cout<<"all test cases  passed :)"<<endl;
    */

   Trie t;
   t.insert("abcd");
   t.insert("ab");
   t.insert("abx");
   t.insert("abyz");
   t.insert("xyz");
   t.insert("a");
   t.insert("bcd");

   vector<string> res;
   t.auto_complete("ab",res);

   for(int i = 0 ; i<(int)res.size();i++)
   {
    cout<<res[i]<<endl;
   }


    







    return 0 ;
}