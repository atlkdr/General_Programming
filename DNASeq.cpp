#include <set>
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> out;
        set<string> fin;
        string seq="";
        for(int i=0;i<10;i++){
            seq+=s[i];
        }
        set<string> ex;
        ex.insert(seq);
        for(int i=10;i<s.size();i++){
            seq=seq.substr(1,seq.size()-1);
            seq+=s[i];
            if(ex.find(seq)!=ex.end()){
                fin.insert(seq);
            }
            ex.insert(seq);
        }
        for(auto it=fin.begin();it!=fin.end();it++){
            out.push_back(*it);
        }
        return out;
    }
};
