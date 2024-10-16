#include <iostream>
#include <string>
#include <vector>
using namespace std;
void getNext(int *next, const string &s)
{
    // 初始化
    int j = 0; // 表示前缀末尾，同时表示i（包括i）之前字符串最长相同前缀和
    next[0] = 0;
    for (int i = 1; i < s.size(); i++)
    {
        // 前后缀不相同
        while (j > 0 && s[i] != s[j])
        {
            j = next[j - 1];
        }
        // 前后缀相同
        if (s[i] == s[j])
        {
            j++;
        }
        // 更新next
        next[i] = j;
    }
}
int strStr(string haystack, string needle, int pos = 0)
{
    if (needle.size() == 0)
        return 0;
    vector<int> next(needle.size(), 0);
    getNext(&next[0], needle);
    int j = 0;
    for (int i = pos; i < haystack.size(); i++)
    {
        while (j > pos && haystack[i] != needle[j])
        {
            j = next[j - 1];
        }
        if (haystack[i] == needle[j])
            j++;
        if (j == needle.size())
        {
            return i - needle.size() + 1;
        }
    }
    return -1;
}

void test_kmp()
{
    string haystack, needle;
    cin >> haystack;
    cin >> needle;
    cout << strStr(haystack, needle, 4);
}
// int main()
// {
//     test_kmp();
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 三元组类，表示矩阵中的一个非零元素
class Triple
{
public:
    int row, col, val;

    Triple(int r = 0, int c = 0, int v = 0) : row(r), col(c), val(v) {}

    // 排序用，按行列顺序排序
    bool operator<(const Triple &t) const
    {
        return row == t.row ? col < t.col : row < t.row;
    }
};

// 稀疏矩阵类
class TSMatrix
{
private:
    int rows, cols;
    vector<Triple> elements;

public:
    TSMatrix(int m = 0, int n = 0) : rows(m), cols(n) {}

    // 输入稀疏矩阵
    void inputMatrix(int len)
    {
        for (int i = 0; i < len; ++i)
        {
            int r, c, v;
            char tmp;
            cin >> tmp >> r >> tmp >> c >> tmp >> v >> tmp; //"(r,c,v)"
            elements.emplace_back(r, c, v);
        }
        sort(elements.begin(), elements.end()); // 按行列顺序排序
    }

    int getRows() const
    {
        return rows;
    }

    int getCols() const
    {
        return cols;
    }

    int getNonZeroCount() const
    {
        return elements.size();
    }

    const vector<Triple> &getElements() const
    {
        return elements;
    }

    // 矩阵相加
    TSMatrix add(const TSMatrix &B) const
    {
        TSMatrix result(rows, cols);
        int i = 0, j = 0;
        while (i < elements.size() && j < B.getElements().size())
        {
            const Triple &a = elements[i];
            const Triple &b = B.getElements()[j];
            if (a.row == b.row && a.col == b.col)
            {
                int sum = a.val + b.val;
                if (sum != 0)
                    result.elements.emplace_back(a.row, a.col, sum);
                i++;
                j++;
            }
            else if (a.row < b.row || (a.row == b.row && a.col < b.col))
            {
                result.elements.push_back(a);
                i++;
            }
            else
            {
                result.elements.push_back(b);
                j++;
            }
        }
        while (i < elements.size())
        {
            result.elements.push_back(elements[i++]);
        }
        while (j < B.getElements().size())
        {
            result.elements.push_back(B.getElements()[j++]);
        }
        return result;
    }

    // 矩阵相减
    TSMatrix subtract(const TSMatrix &B) const
    {
        TSMatrix result(rows, cols);
        int i = 0, j = 0;
        while (i < elements.size() && j < B.getElements().size())
        {
            const Triple &a = elements[i];
            const Triple &b = B.getElements()[j];
            if (a.row == b.row && a.col == b.col)
            {
                int diff = a.val - b.val;
                if (diff != 0)
                    result.elements.emplace_back(a.row, a.col, diff);
                i++;
                j++;
            }
            else if (a.row < b.row || (a.row == b.row && a.col < b.col))
            {
                result.elements.push_back(a);
                i++;
            }
            else
            {
                result.elements.emplace_back(b.row, b.col, -b.val);
                j++;
            }
        }
        while (i < elements.size())
        {
            result.elements.push_back(elements[i++]);
        }
        while (j < B.getElements().size())
        {
            const Triple &b = B.getElements()[j++];
            result.elements.emplace_back(b.row, b.col, -b.val);
        }
        return result;
    }

    // 输出矩阵
    void print() const
    {
        cout << rows << " " << cols << " " << elements.size() << endl;
        if (!elements.empty())
        {
            for (const auto &elem : elements)
            {
                cout << "(" << elem.row << "," << elem.col << "," << elem.val << ")";
            }
            // cout << endl;
        }
    }
};

// int main()
// {
//     // 输入矩阵A
//     int m, n, lenA;
//     cin >> m >> n >> lenA;
//     TSMatrix A(m, n);
//     A.inputMatrix(lenA);

//     // 输入矩阵B
//     int lenB;
//     cin >> m >> n >> lenB;
//     TSMatrix B(m, n);
//     B.inputMatrix(lenB);

//     // A+B
//     TSMatrix sum = A.add(B);
//     sum.print();
//     cout << endl;
//     // A-B
//     TSMatrix diff = A.subtract(B);
//     diff.print();
//     if (diff.getNonZeroCount() == 0)
//         cout << endl;

//     return 0;
// }

// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int>> matrix(m+1, vector<int>(n+1));
//     for (int i = 1; i <= m; i++) {
//         for (int j = 1; j <= n; j++) {
//             cin >> matrix[i][j];
//         }
//     }
//     //求马鞍点
//     vector<vector<int>> ret;
//     vector<int> path;
//     for (int i = 1; i <= m; i++) {
//         int rowmin = matrix[i][1];
//         for(int j = 1; j <= n; j++) {
//             if (matrix[i][j] < rowmin) {
//                 rowmin = matrix[i][j];
//             }
//         }
//         for (int j = 1; j <= n; j++) {
//             if(matrix[i][j] == rowmin) {
//                 for(int k = 1; k <= m; k++) {
//                     if(rowmin<matrix[k][j]) {
//                         break;
//                     }
//                     if(k==m) {
//                         path = {i,j,matrix[i][j]};
//                         ret.push_back(path);
//                     }
//                 }
//             }
//         }

//     }
//     if(ret.size() == 0) {
//         cout << "NONE";
//         return 0;
//     }
//     for(int i = 0; i < ret.size(); i++) {
//         cout << "(" << ret[i][0] << "," << ret[i][1] << "," << ret[i][2] << ")";
//     }
//     return 0;
// }
