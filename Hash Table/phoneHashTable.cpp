#include <iostream>
#include <vector>

using namespace std;

int hashString(string str, int n) {
	long long nn = n;
	long long sum = 0;
	for (int i = 0; i < (int) str.size(); ++i)
    {
        int charValue;
        if(str[i]>'a'&& str[i]<'z')
        charValue = str[i]-'a';
        else if(str[i]>'A' && str[i]<'Z')
        charValue = str[i]-'A';
        else
        charValue = str[i]-'0';
        
		sum = (sum * 26 + charValue) % nn;

    }
	return sum % nn;
}

class phoneEntry{

    public:

    const static int LIMIT = 65407 ;
    string name;
    string phoneNumber; 

    phoneEntry(string name , string phoneNumber):name(name),phoneNumber(phoneNumber){

    }

    int hash()
    {
        return hashString(name,LIMIT);
    }

    void print()
    {
        cout<<"name : "<<name<<" phone Number : "<<phoneNumber<<endl;
    }

};

class phoneEntryTableChainig{
    private:

    int tableSize;
    vector<vector<phoneEntry>> table;

    public:

    phoneEntryTable(int tableSize):tableSize(tableSize){
        table.resize(tableSize);
    }

    void put(phoneEntry phone) 
    {
        int idx = phone.hash() % tableSize; // o(L)

        for(int i = 0 ; i<(int)table[idx].size() ; i++)
        {
            if(table[idx][i].name == phone.name)
            {
            table[idx][i] = phone;
            return ;
            }

        }
        table[idx].push_back(phone);
    }

   bool remove(phoneEntry phone)
   {
     int idx = phone.hash() % tableSize;

     for(int i = 0 ; i < (int)table[idx].size() ; i++)
     {
        if(table[idx][i].name == phone.name)
        {
            swap(table[idx][i],table[idx].back());
            table[idx].pop_back();
            return true;
        }
     }
     return false;

   }

   bool get(phoneEntry phone)
   {
     int idx = phone.hash() % tableSize;

     for(int i = 0 ; i<(int)table[idx].size() ; i++)
     {
        if(table[idx][i].name == phone.name)
        {
        phone = table[idx][i];
        return true;
        }
        
     }

     return false;
     

   }

   void printAll()
   {
     for(int hash = 0  ; hash < tableSize ; hash++)
     {
        if(table[hash].size()==0)
        continue;

        cout<<"hash : "<<hash<<endl;

        for(int i = 0 ; i < (int)table[hash].size() ; i++)
        {
            table[hash][i].print();
        }
     }
   }














};

class phoneEntryTableProbing{
    private:

    int tableSize;
    vector<phoneEntry*> table;
    phoneEntry* deleted = new phoneEntry("","");

    public:

    phoneEntryTableProbing(int tableSize):tableSize(tableSize){
        table.resize(tableSize);
    }

    void put(phoneEntry phone) 
    {
        int idx = phone.hash() % tableSize; // o(L)

        for(int i = 0 ; i<tableSize ; i++)
        {
            if(table[idx]== deleted || !table[idx])
            {
                table[idx]=new phoneEntry(phone.name,phone.phoneNumber);
                return true;
            }


            idx = (idx +1 )%tableSize;
        }

        return false;
       
    }

   bool remove(phoneEntry phone)
   {
     int idx = phone.hash() % tableSize;

     for(int i = 0 ; i < tableSize ; i++)
     {
        if(!table[idx])
        break;
        
        else if(table[idx]!=deleted && table[idx]->name == phone.name)
        {
            delete table[idx];
            table[idx] = deleted;
            return true;
        }

        idx =(idx+1)%tableSize;
     }
     return false;
   }

   bool get(phoneEntry phone)
   {
     int idx = phone.hash() % tableSize;

     for(int i = 0 ; i< tableSize ; i++)
     {
        if(!table[idx])
        break;
        else if(table[idx]!=deleted && table[idx]->name == phone.name)
        return true;

        idx = (idx+1)%tableSize;
        
     }

     return false;
     

   }

   void printAll()
   {
     for(int hash = 0  ; hash < tableSize ; hash++)
     {
       if(!table[hash] || table[hash]==deleted)
       continue;

        table[hash]->print();
        
     }
   }














};





int main()
{
    /*
    phoneEntryTable table(3);
	table.put(phoneEntry("mostafa", "604-401-120"));
	table.put(phoneEntry("mostafa", "604-401-777"));	// update
	table.put(phoneEntry("ali", "604-401-343"));
	table.put(phoneEntry("ziad", "604-401-17"));
	table.put(phoneEntry("hany", "604-401-758"));
	table.put(phoneEntry("belal", "604-401-550"));
	table.put(phoneEntry("john", "604-401-223"));

    phoneEntry e("mostafa", "");
	if (table.get(e))
		cout << e.phoneNumber << "\n";	// 604-401-777

    table.printAll();

    cout << table.remove(phoneEntry("smith", "")) << "\n"; // 0
	cout << table.remove(phoneEntry("hany", "")) << "\n";  // 1
	cout << table.remove(phoneEntry("belal", "")) << "\n";  // 1
	table.printAll();

    */

   cout<<hashString("abc",7)<<endl<<hashString("ABC",7)<<endl<<hashString("023",7)<<endl;









    return 0;
}
