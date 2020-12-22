class Solution {
public:

    int X [4] = { 1 , 0 , -1 ,  0 } ;
    int Y [4] = { 0 , 1 ,  0 , -1 } ;

    int n , m ;
    bool Check ( int x , int y )
    {
        if ( x < 0 or y < 0 or x >= n or y >= m )
                return 0 ;
        return 1 ;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& arr )
    {


         n = arr.size() ;

        m = arr[ 0 ].size() ;

        vector< vector< int > > ans (  n ,vector <int > ( m , 0 ) ) ;

        queue < pair < int , int> > q ;
        for ( int i = 0 ; i < n ; i ++ )
        {
            for ( int j = 0 ; j < m ; j ++ )
            {
                if ( arr [ i ] [ j ] == 0 )
                {
                    ans [ i ][ j ] = 0 ;
                    q.push ( {  i , j }  ) ;

                }
                else
                    ans [ i ] [ j ] = INT_MAX ;
            }
        }



        while ( !q.empty() )
        {

            int x = q.front().first ;
            int y = q.front().second ;
            q.pop() ;
            for ( int i = 0 ; i < 4 ; i ++ )
            {
                int xx = x + X [ i ] ;
                int yy = y + Y [ i ] ;
                if ( Check ( xx , yy ) and ans  [ xx ] [ yy ] > ans [ x ][ y ] + 1  )
                {
                    ans [ xx ] [ yy ] =  ans [ x ][ y ] + 1 ;
                    q.push ( { xx , yy } ) ;

                }
            }


        }
        return ans ;

    }
};
