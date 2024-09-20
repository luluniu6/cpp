#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 将字符串转为十进制整数
int stringtoint(string s)
{
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0 && s[0] == '-')
            continue;
        num = num * 10 + (s[i] - '0');
    }
    if (s[0] == '-')
        num *= -1;
    return num;
}

//逆波兰表达式求值
int evalRPN(vector<string>& tokens)
{
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            int right = st.top(); st.pop();
            int left = st.top(); st.pop();
            switch (tokens[i][0])
            {
            case '+': st.push(left + right); break;
            case '-': st.push(left - right); break;
            case '*': st.push(left * right); break;
            case '/': st.push(left / right); break;
            }
        }
        else st.push(stringtoint(tokens[i]));
    }
    return st.top();
}

int Priority(char c)
{
	switch(c)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
	}
	return 0;
}

//中缀表达式变成后缀表达式
string InifToSuffix(string& s)
{
    string ret = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch >= '0' && ch <= '9')
        {
            ret += ch;
        }
        else if (st.empty() || ch == '(' || Priority(ch) > Priority(st.top()))
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ret += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && Priority(ch) <= Priority(st.top()))
            {
                ret += st.top();
                st.pop();

            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        ret += st.top();
        st.pop();
    }
    return ret;
}
int main()
{
    string s = "2*(3+5)+7/1-4";
    string ret = InifToSuffix(s);
    cout << ret;
}
