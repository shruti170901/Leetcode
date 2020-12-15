class ProductOfNumbers {
public:
    map<int, int> map;
    int cnt =0;
    ProductOfNumbers() {
        map[0]=1; 
        cnt=0;
    }
    
    void add(int num) {
        if(num==0){
            cnt=0;
            map.erase(map.begin(), map.end());
            map[0]=1; 
            return;
            
        } 
        cnt++;
        map[cnt]=map[cnt-1]*num; 
    }
    
    int getProduct(int k) {
        int last=map.size()-k-1;
        if(last<0) return 0;
        int total=map[cnt];
        int div=map[last];
       
      
        return total/div;
    }
};

