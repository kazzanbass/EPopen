#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Epopen{
    private:
        vector <char> buff;
        FILE *f;
        short int err = 0;
    public:
    Epopen(string cmd){
        f = popen(cmd.c_str(), "r");
    }
    string get(){
         char c = (char)getc(f);
         while(c!=EOF){
            buff.push_back(c);
            c = (char)getc(f);
         }
         err = pclose(f);
         if(err!=0){
            return "";
         }
         string data(buff.begin(), buff.end());
         return data;        
    }
    short int getErr(){
        return err;
    }
};

int main(){
    Epopen foo("ls");
    cout<<foo.get();
    cout<<foo.getErr();

    return 0;
}