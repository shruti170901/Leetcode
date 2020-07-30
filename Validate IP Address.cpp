class Solution {
public:
    string validIPAddress(string IP) {
        istringstream is(IP);
        string t = "";
        int temp = 0;
        if (IP.find(':') == string::npos) { // Check IPv4
            while (getline(is, t, '.')) {
                ++temp;
                if (temp > 4 || t.empty() || (t.size() > 1 && t[0] == '0') || t.size() > 3) return "Neither";
                for (char c : t) {
                    if (c < '0' || c > '9') return "Neither";
                }
                int val = stoi(t);
                if (val < 0 || val > 255) return "Neither";
            }
            return (temp == 4 && IP.back() != '.') ? "IPv4" : "Neither";
        } else { // Check IPv6
            while (getline(is, t, ':')) {
                ++temp;
                if (temp > 8 || t.empty() || t.size() > 4) return "Neither";
                for (char c : t) {
                    if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return "Neither";
                }
            }
            return (temp == 8 && IP.back() != ':') ? "IPv6" : "Neither";
        }
    }
};
