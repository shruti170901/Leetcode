class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        bool flag = true;
        int size = input.length();
            for(size_t i=0;i<size;i++){
                char ch = input[i];
                if(ch == '+' || ch == '-' || ch=='*'){
                    flag = false;
                    vector<int> ans_left = diffWaysToCompute(input.substr(0,i));
                    vector<int> ans_right = diffWaysToCompute(input.substr(i+1));
                    
                    for(int n =0; n < ans_left.size();n++){
                        for(int m =0; m< ans_right.size();m++){
                            switch(ch){
                                case '+':
                                    ans.push_back(ans_left[n] + ans_right[m]);
                                        break;
                                    case '-':
                                    ans.push_back(ans_left[n] - ans_right[m]);
                                        break;
                                    case '*':
                                    ans.push_back(ans_left[n] * ans_right[m]);
                                        break;
                            }
                        }
                    }
                    
                }
            }
        if(flag){
            ans.push_back(stoi(input));
            return ans;
        }
        return ans;
    }
};
