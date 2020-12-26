class Solution
{
public:
    bool ispair(char a, char b)
    {
        return a == '(' && b == ')';
    }
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (!st.empty() && ispair(s[st.top()], s[i]))
                {
                    st.pop();
                }
                else
                    st.push(i);
            }
        }

        while (!st.empty())
        {
            int pos = st.top();
            st.pop();
            s.erase(pos, 1);
        }

        return s;
    }
};