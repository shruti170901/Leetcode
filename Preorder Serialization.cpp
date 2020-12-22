/* Given a string of comma separated values, verify whether it is a
   correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
   
     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

*/
class Solution {
public:
    bool calcans(string preorder,int &pos,int length)
    {
        if(pos>=length)
            return false;
        if(preorder[pos]=='#')
        {
           pos+=2;
            return true;
        }
        while(pos<length&&(preorder[pos]>=48&&preorder[pos]<=57))
            pos++;
        pos++;
        bool left=calcans(preorder,pos,length);
        bool right=calcans(preorder,pos,length);
        return left&&right;
    }
    bool isValidSerialization(string preorder) {
        int l=preorder.length();
        int pos=0;
        return calcans(preorder,pos,l)&&pos>=l;
    }
};
