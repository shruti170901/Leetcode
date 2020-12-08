class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        bool f = true;
        int size = input.length();
            for(size_t i=0;i<size;i++){
                char chr = input[i];
                if(chr == '+' || chr == '-' || chr=='*'){
                    f = false;
                    vector<int> left_ans = diffWaysToCompute(input.substr(0,i));
                    vector<int> ans_right = diffWaysToCompute(input.substr(i+1));
                    
                    for(int n =0; n < left_ans.size();n++){
                        for(int m =0; m< ans_right.size();m++){
                            switch(chr){
                                case '+':
                                    ans.push_back(left_ans[n] + ans_right[m]);
                                        break;
                                    case '-':
                                    ans.push_back(left_ans[n] - ans_right[m]);
                                        break;
                                    case '*':
                                    ans.push_back(left_ans[n] * ans_right[m]);
                                        break;
                            }
                        }
                    }
                    
                }
            }
        if(f){
            ans.push_back(stoi(input));
            return ans;
        }
        return ans;
    }
};
