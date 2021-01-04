class Solution {
public:
    
    bool isValid(vector<int> &p1,vector<int> &p2,vector<int>&p3){
        int x1 = p1[0]-p2[0];
        int x2 = p3[0] - p2[0];
        
        int y1 = p1[1] -p2[1];
        int y2 = p3[1] -p2[1];
        
        
        if((y1==0 && x2==0) || (y2==0 && x1==0)){
            return true;
        }
        else if(y1==0 || x1==0 || y2==0 || x2==0)
            return false;
        
        else if(x1*x2==-y1*y2){
            return true;
        }
        return false;
    }
    
    double dist(vector<int> &p1,vector<int> &p2){
        return sqrt((pow(p1[0]-p2[0],2))+ pow(p1[1]-p2[1],2));
    }
    
    double Area(vector<int> &p1,vector<int> &p2,vector<int>&p3){
        return dist(p1,p2) * dist(p2,p3);
    }
    
    double minAreaFreeRect(vector<vector<int>>& points) {
        set<pair<int,int> > hmap;
        
        int n = points.size();
        
        if(n<3)
            return 0;
        
        for(int i=0;i<n;i++){
            hmap.insert({points[i][0],points[i][1]});
        }
        
        double sol=INT_MAX;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(isValid(points[i],points[j],points[k])){
                        int x = points[i][0] + points[k][0] - points[j][0];
                        int y = points[i][1] + points[k][1] - points[j][1];
                        if(hmap.find({x,y})!=hmap.end()){
                            sol = min(sol,Area(points[i],points[j],points[k]));
                        }
                    }
                   else  if(isValid(points[i],points[k],points[j])){
                        int x = points[i][0] + points[j][0] - points[k][0];
                        int y = points[i][1] + points[j][1] - points[k][1];
                        if(hmap.find({x,y})!=hmap.end()){
                            sol = min(sol,Area(points[i],points[k],points[j]));
                        }
                    }
                   else if(isValid(points[j],points[i],points[k])){
                        int x = points[j][0] + points[k][0] - points[i][0];
                        int y = points[j][1] + points[k][1] - points[i][1];
                        if(hmap.find({x,y})!=hmap.end()){
                            sol = min(sol,Area(points[j],points[i],points[k]));
                        }
                    }
                    
                }
            }
        }
        return sol==INT_MAX?0:sol;
    }
};
