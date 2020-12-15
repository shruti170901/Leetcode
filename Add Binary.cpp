class Solution {
public:
    string addBinary(string a, string b) {
        if(a==" "){
            return b;
        }
        if(b==" "){
            return a;
        }
        int carry=0;
        string ans="";
        int i=a.length()-1,j=b.length()-1;
        while(i>=0&&j>=0){
            if(a[i]=='1'&&b[j]=='1'){
                if(carry==0){
                ans+=to_string(0);
                    carry=1;
                }
               else{
                ans+=to_string(1);
                    carry=1;
                }
            }
            else if((a[i]=='1'&&b[j]=='0')||(a[i]=='0'&&b[j]=='1')){
                 if(carry==0){
                ans+=to_string(1);
                    carry=0;
                }
                else{
                ans+=to_string(0);
                    carry=1;
                }
            }
            else{
                 if(carry==0){
                  ans+=to_string(0);
                    carry=0;
                }
                else{
                ans+=to_string(1);
                    carry=0;
                }
            }
           
            i--;j--;
        }
        while(i>=0){
            if(carry==1){
                if(a[i]=='0'){
                    ans+=to_string(1);
                    carry=0;
                }
                else{
                    ans+=to_string(0);
                    carry=1;
                }
            }
            else{
               if(a[i]=='0'){
                    ans+=to_string(0);
                    carry=0;
                }
                else{
                    ans+=to_string(1);
                    carry=0;
                }  
            }
            i--;
        }
          while(j>=0){
            if(carry==1){
                if(b[j]=='0'){
                    ans+=to_string(1);
                    carry=0;
                }
                else{
                    ans+=to_string(0);
                    carry=1;
                }
            }
            else{
               if(b[j]=='0'){
                    ans+=to_string(0);
                    carry=0;
                }
                else{
                    ans+=to_string(1);
                    carry=0;
                }  
              } 
              j--;
        }
        if(carry){
            ans+=to_string(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
