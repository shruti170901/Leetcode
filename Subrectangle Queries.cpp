class SubrectangleQueries {
public:
    vector<vector<int> > coords;
    vector<vector<int> > rectangle;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->rectangle = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        vector<int> tmp;
        tmp={row1,row2,col1,col2,newValue};
        coords.insert(coords.begin(),tmp);
    }
    
    int getValue(int row, int col) {
        int i;
        for(i=0;i<coords.size();++i){
            int row1=coords[i][0];
            int row2=coords[i][1];
            int col1=coords[i][2];
            int col2=coords[i][3];
            int val=coords[i][4];
            if(row<=row2&&row>=row1&&col<=col2&&col>=col1){
                return val;
            }
        }
        return rectangle[row][col];
    }
};