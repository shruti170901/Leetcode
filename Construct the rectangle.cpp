class Solution {
public:
    vector<int> constructRectangle(int area)
    {
     vector <int> arr;
     int i;                        //variable used to find width
     for(i=sqrt(area);i>0;i--)     // i initialised so to reduce loop iterations as well as keeping width close to and lower than length
         if(area%i==0)             // once condition is satisfied loop terminates and width is stored in i
             break;
     arr.push_back(area/i);        //length=area/width
     arr.push_back(i);
     return arr;
    }
};
