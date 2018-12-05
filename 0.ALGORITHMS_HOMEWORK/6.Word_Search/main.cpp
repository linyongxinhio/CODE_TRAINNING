/**
* @description:从二维字母表中搜索指定的字符串，必须是连续的，可以上下左右搜索。
* @idea:1.深度优先搜索
* @author: 林永欣
* @date: 2018/10/31
**/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Search
{
    public:
        bool dfs(vector<vector<char>> &board, string word,vector<vector<bool>> visited, int i, int j, int curr_pos)
        {
            if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) //b边界值，递归的返回条件
            {
              return false;
            }
            if (visited[i][j] || board[i][j] != word[curr_pos])  //如果标志位为true或者不匹配，查找失败
            {
              return false;
            }
            visited[i][j] = true; //标记当前位置已经查找过
            ++curr_pos; //当前查找位置往后移一位，遍历要查找字符串的每一位
            if (curr_pos == word.size())  //如果当前的位置等于要查找字符串的长度代表已经找到，返回true
            {
              return true;
            }

            //遍历上下左右
            return dfs(board, word, visited, i - 1, j, curr_pos) || // 上
                   dfs(board, word, visited, i + 1, j, curr_pos) || // 下
                   dfs(board, word, visited, i, j - 1, curr_pos)||   // 左
                   dfs(board, word, visited, i, j + 1, curr_pos);  // 右


        }

        bool exist(vector<vector<char>> &board, string word)
        {
            for (int i = 0; i < board.size(); ++i)
            {
              for (int j = 0; j < board[i].size(); ++j)
              {
                if (word[0] == board[i][j])
                {
                  vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(), false)); //bool类型的二维容器
                  if (dfs(board, word, visited, i, j, 0))
                  {
                    return true;
                  }
                }
              }
            }
            return false;
        }
};

int main()
{
    int m,n;
    cout << "***输入字母表规格***" << endl;
    cout << "请输入字母表的行数: ";
    cin >> m;
    cout << "请输入字母表的列数: ";
    cin >> n;
    cout << endl;

    vector<vector<char>> input_board;  //定义二维容器来存放字母表
    vector<char> v;  //定义一维容器来存放当前的行
    char temp;  //输入的字符变量
    cout << "***输入字母表的数据***" << endl;
    input_board.clear();
    for (int i = 0; i<m; i++)
    {
        v.clear(); //每次记得clear()
        cout << "请输入字母表第" << i+1 << "行的数据: ";
        for (int j = 0; j<n; j++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        input_board.push_back(v);
    }
	cout << endl;

	cout << "***打印当前字母表***" << endl;
	cout << "[" << endl;
    for (int i=0;i<m;i++)
    {
        cout << "  [" ;
        for (int j=0;j<n-1;j++)
        {
            cout << input_board[i][j] << ",";
        }
        cout << input_board[i][n-1] << "]," << endl;
    }
    cout << "]" << endl;
    cout << endl;

    Search word_search ;
    string need_search_word;
    cout << "***输入字符串***" << endl;
    cout << "请输入要查找的字符串: ";
    cin >> need_search_word;
    while (word_search.exist(input_board,need_search_word)) //循环输入要查找的字符串，直到查找失败
    {
        cout << "True" << endl;
        cout << "请输入要查找的字符串: ";
        cin >> need_search_word;
    }
    cout << "False" << endl;
    return 0;
}
