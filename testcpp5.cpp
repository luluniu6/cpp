#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <math.h>
#include <map>

using namespace std;
string removebs(string &s);
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

// 中缀转后缀之后就没有括号

// 逆波兰表达式求值（后缀）
int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            switch (tokens[i][0])
            {
            case '+':
                st.push(left + right);
                break;
            case '-':
                st.push(left - right);
                break;
            case '*':
                st.push(left * right);
                break;
            case '/':
                st.push(left / right);
                break;
            }
        }
        else
            st.push(stringtoint(tokens[i]));
    }
    return st.top();
}
int Priority(char c)
{
    switch (c)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    }
    return 0;
}

// 中缀表达式变成后缀表达式
string InifToSuffix(string &s)
{
    string ret = "";
    stack<char> st;
    s = removebs(s);
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '-' && (i == 0 || !((s[i - 1] >= '0' && s[i - 1] <= '9')||(s[i-1]=='.'))))
        {
            ret += ch;
            continue;
        }
        if ((ch >= '0' && ch <= '9')||(ch=='.')) 
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
        else
        {

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

// int main()
// {
//     string s = "-2*(-3+5)+7/1-4";
//     string ret = InifToSuffix(s);
//     cout << ret;
// }

// 为了处理有括号的情况，可以利用递归
// int dfs(string s, int &i)
// { // 防止递归后回到'('的位置，所以传引用
//     stack<int> st;
//     char op = '+';
//     int res = 0;
//     int num = 0;
//     for (i; i < s.size(); i++)
//     {
//         if (isdigit(s[i]))
//             num = num * 10 + (s[i] - '0'); // 加()防止溢出
//         if (s[i] == '(')
//         {
//             num = dfs(s, ++i); // 不能使用后置++因为cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
//             i++;               // 递归出来从')'的下一位再开始
//         }
//         if ((!isdigit(s[i]) && s[i] != ' ') || (i == s.size() - 1))
//         {
//             int pre = 0;
//             switch (op)
//             {
//             case '+':
//                 st.push(num);
//                 break;
//             case '-':
//                 st.push(-num);
//                 break;
//             case '*':
//                 pre = st.top();
//                 st.pop();
//                 st.push(num * pre);
//                 break;
//             case '/':
//                 pre = st.top();
//                 st.pop();
//                 st.push(pre / num);
//                 break;
//             }
//             op = s[i];
//             num = 0;
//         }
//         if (s[i] == ')')
//             break;
//     }
//     while (!st.empty())
//     {
//         res += st.top();
//         st.pop();
//     }
//     return res;
// }

// // 用栈实现基本计算器
// int calculate(string s)
// {
//     int begin = 0;
//     return dfs(s, begin);
// }

// 双指针删除空格函数
string removebs(string &s)
{
    int i = 0, j = 0;
    for (i, j; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            s[j] = s[i];
            j++;
        }
    }
    s.resize(j);
    return s;
}
// int main()
// {
//     string s = "haha la   ";
//     cout << removebs(s);
//     return 0;
// }

// 为了处理有括号的情况，可以利用递归
double dfs(const string& s, int& i)
{ // 防止递归后回到'('的位置，所以传引用
    stack<double> st;
    char op = '+';
    double res = 0;
    double num = 0;
    int begin = 0;
    int point = 0;
    for (i; i < s.size(); i++)
    {
        while (isdigit(s[i]) || s[i] == '.')
        {
            if (isdigit(s[i]))
            {
                if (point != 0 && i - begin > point)
                    num = num + pow(0.1, i-begin-point) * (s[i] - '0');
                else
                    num = num * 10 + (s[i] - '0'); // 加()防止溢出
            }
            if (s[i] == '.')
            {
                point = i - begin;
            }
            if (s[i] == ' ')
                i++;
            i++;
        }
        if (s[i] == '(')
        {
            num = dfs(s, ++i); // 不能使用后置++因为cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
            i++;               // 递归出来从')'的下一位再开始
        }
        if (!isdigit(s[i]) || i == s.size() - 1)
        {
            double pre = 0;
            switch (op)
            {
            case '+':
                st.push(num);
                break;
            case '-':
                st.push(-num);
                break;
            case '*':
                pre = st.top();
                st.pop();
                st.push(num * pre);
                break;
            case '/':
                pre = st.top();
                st.pop();
                st.push(pre / num);
                break;
            }
            op = s[i];
            num = 0;
            begin = i;
        }
        if (s[i] == ')')
            break;
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}
// 用栈实现基本计算器
double calculate(string& s)
{
    int begin = 0;
    s = removebs(s);
    return dfs(s, begin);
}
// int main()
// {
//     string s = "(   -1.0  5+2.  5)*2.25/2.25";
//     cout << calculate(s);
//     return 0;
// }

bool Legitimacy(string s)
{
	//判非法符号
	for (int i = 0; i < s.size(); i++)
	{
		if (!isdigit(s[i]) && s[i] != '+'&&s[i] != '-'&&s[i] != '*'&&s[i] != '/'&&s[i] != '('&&s[i] != ')'&&s[i] != '.'&&s[i] != ' ')
		{
			printf("Unknown symbol\n");
			return false;
		}
	}
	//判断表达式是否正确
	int left_bracket = 0;
	for (int i = 0; i < s.size(); i++)
	{
		//判括号
		if (s[i] == '(')
			left_bracket++;
		else if (s[i] == ')')
		{
			if (left_bracket == 0)
			{
				printf("Brackets do not match\n");
				return false;
			}
			left_bracket--;
		}
		//特判第一个
		if (i == 0)
		{
			if (s[i] != '+'&&s[i] != '-'&&s[i] != '(' && !isdigit(s[i]))
			{
				printf("Operator error\n");
				return false;
			}
		}
		//特判最后一个
		else if (i == s.size() - 1)
		{
			if (s[i] != ')' && !isdigit(s[i]))
			{
				printf("Operator error\n");
				return false;
			}
			if (s[i] == ')'&&s[i - 1] == '(')
			{
				printf("Operator error\n");
				return false;
			}
		}
		//中间字符，枚举ERROR情况
		else
		{
			if (isdigit(s[i]))
			{
				if (s[i - 1] == ')' || s[i + 1] == '(')
				{
					printf("Operator error\n");
					return false;
				}
			}
			else if (s[i] == '.')
			{
				if (!isdigit(s[i - 1]) || !isdigit(s[i + 1]))
				{
					printf("radix point error\n");
					return false;
				}
			}
			else if (s[i] == '*' || s[i] == '/')
			{
				if ((!isdigit(s[i - 1]) && s[i - 1] != ')') || (!isdigit(s[i + 1]) && s[i + 1] != '+'&&s[i + 1] != '-'&&s[i + 1] != '('))
				{
					printf("Operator error\n");
					return false;
				}
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				if (isdigit(s[i - 1]) || s[i - 1] == ')')
				{
					if (!isdigit(s[i + 1]) && s[i + 1] != '+'&&s[i + 1] != '-')
					{
						printf("Operator error\n");
						return false;
					}
				}
				else
				{
					if (!isdigit(s[i + 1]))
					{
						printf("#ERROR\n");
						printf("Operator error\n");
						return false;
					}
				}
			}
			else if (s[i] == '(')
			{
				if (isdigit(s[i - 1]) || s[i - 1] == ')' || s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == ')')
				{
					printf("Operator error\n");
					return false;
				}
			}
			else if (s[i] == ')')
			{
				if ((!isdigit(s[i - 1]) && s[i - 1] != ')') || (s[i + 1] != '+'&&s[i + 1] != '-'&&s[i + 1] != '*'&&s[i + 1] != '/'&&s[i + 1] != ')'))
				{
					printf("Operator error\n");
					return false;
				}
			}
		}
	}
    return true;
}
int main()
{
    string s = "(-1.05+2.5)*2.25/2.25";
    if (Legitimacy(s)) cout << calculate(s);
    else cout << "Legitimate expression";
    return 0;
}