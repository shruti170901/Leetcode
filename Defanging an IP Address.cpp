class Solution {
public:
    string defangIPaddr(string address) {
        for(int i=0;i<address.length();i++){
            if(address[i]=='.'){
                address.insert(i,"[");
                address.insert(i+2,"]");
                i+=2;
            }
        }
        return address;
    }
};
