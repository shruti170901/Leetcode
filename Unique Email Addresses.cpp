class Solution {
public:

    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> dict;
        
        for (auto& email : emails) {
            string addr;

            for(int i=0; i<email.size(); i++) {
                if (email[i] == '.' ) continue;

                if (email[i] == '+') {
                    while( email[++i] != '@');
                }
                if (email[i] =='@') {
                    addr += email.substr(i);
                    break;
                }
                addr += email[i];
            }

            dict[addr]++;
        }
        return dict.size();
    }

};
