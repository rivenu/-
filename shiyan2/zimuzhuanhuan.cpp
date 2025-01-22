#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
// 要求字典序,in优先考虑
bool flag = 0;
char s1[200], s2[200];
char res[200];
void dfs(stack<char> s, int m, int n, int index);
void output();
bool str_same(std::vector<char> p1, std::vector<char> p2);
void clear();
int main()
{
    while (cin >> s1 >> s2)
    {
        stack<char> s;
        cout << "[" << endl;
        dfs(s, 0, 0, 0);
        cout << "]" << endl;
        memset(s1, '\0', sizeof(s1));
        memset(s2, '\0', sizeof(s2));
        memset(res, '\0', sizeof(res));
    }
}

void dfs(stack<char> s, int m, int n, int index) //s为当前栈，m为s1下标，n为s2下标，index为res下标
{
	//递归终止条件1：s1，s2 都遍历完，且栈为空，表示已经找到了一组满足条件的进栈出栈序列
	if(m >= strlen(s1) && n >= strlen(s2) && s.empty())
	{
		output();
		return;
	}
	//递归终止条件2：s1已经遍历完，栈不为空，且栈顶元素不等于s2的指针所指的元素，即没找到满足条件的进栈出栈序列
	if (m >= strlen(s1) && s.top() != s2[n])
	{
		return;
	}
 
	//栈空，或栈顶与s2的当前下标值不匹配，则s1当前下标值进栈，s1下标后移
	if(s.empty() || s.top() != s2[n])
	{
		s.push(s1[m]);
		res[index] = 'i';
		dfs(s, m+1, n, index+1);
	}
	//栈顶与s2当前下标的值匹配
	else
	{
		//分支1：进栈
		s.push(s1[m]);
		res[index] = 'i';
		dfs(s, m+1, n, index+1);
		
		s.pop();	//回溯
 
		//分支2：出栈
		s.pop();
		res[index] = 'o';
		dfs(s, m, n+1, index+1);
 
	}
 
}


void output()
{

    for (int i = 0; i < strlen(res) - 1; ++i)
    {
        cout << res[i] << " ";
    }
    cout << res[strlen(res) - 1] << endl;
}

// bool str_same(std::vector<char> p1, std::vector<char> p2)
// {
//     // 如果长度不同，直接返回 false
//     if (p1.size() != p2.size())
//         return false;

//     // 对两个向量进行排序
//     std::sort(p1.begin(), p1.end());
//     std::sort(p2.begin(), p2.end());

//     // 比较两个排序后的向量
//     for (size_t i = 0; i < p1.size(); i++)
//     {
//         if (p1[i] != p2[i])
//             return false;
//     }

//     return true;
// }