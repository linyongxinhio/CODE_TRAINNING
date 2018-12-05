/**
* @description:�Ӷ�ά��ĸ��������ָ�����ַ����������������ģ�������������������
* @idea:1.�����������
* @author: ������
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
            if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) //b�߽�ֵ���ݹ�ķ�������
            {
              return false;
            }
            if (visited[i][j] || board[i][j] != word[curr_pos])  //�����־λΪtrue���߲�ƥ�䣬����ʧ��
            {
              return false;
            }
            visited[i][j] = true; //��ǵ�ǰλ���Ѿ����ҹ�
            ++curr_pos; //��ǰ����λ��������һλ������Ҫ�����ַ�����ÿһλ
            if (curr_pos == word.size())  //�����ǰ��λ�õ���Ҫ�����ַ����ĳ��ȴ����Ѿ��ҵ�������true
            {
              return true;
            }

            //������������
            return dfs(board, word, visited, i - 1, j, curr_pos) || // ��
                   dfs(board, word, visited, i + 1, j, curr_pos) || // ��
                   dfs(board, word, visited, i, j - 1, curr_pos)||   // ��
                   dfs(board, word, visited, i, j + 1, curr_pos);  // ��


        }

        bool exist(vector<vector<char>> &board, string word)
        {
            for (int i = 0; i < board.size(); ++i)
            {
              for (int j = 0; j < board[i].size(); ++j)
              {
                if (word[0] == board[i][j])
                {
                  vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(), false)); //bool���͵Ķ�ά����
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
    cout << "***������ĸ����***" << endl;
    cout << "��������ĸ�������: ";
    cin >> m;
    cout << "��������ĸ�������: ";
    cin >> n;
    cout << endl;

    vector<vector<char>> input_board;  //�����ά�����������ĸ��
    vector<char> v;  //����һά��������ŵ�ǰ����
    char temp;  //������ַ�����
    cout << "***������ĸ�������***" << endl;
    input_board.clear();
    for (int i = 0; i<m; i++)
    {
        v.clear(); //ÿ�μǵ�clear()
        cout << "��������ĸ���" << i+1 << "�е�����: ";
        for (int j = 0; j<n; j++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        input_board.push_back(v);
    }
	cout << endl;

	cout << "***��ӡ��ǰ��ĸ��***" << endl;
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
    cout << "***�����ַ���***" << endl;
    cout << "������Ҫ���ҵ��ַ���: ";
    cin >> need_search_word;
    while (word_search.exist(input_board,need_search_word)) //ѭ������Ҫ���ҵ��ַ�����ֱ������ʧ��
    {
        cout << "True" << endl;
        cout << "������Ҫ���ҵ��ַ���: ";
        cin >> need_search_word;
    }
    cout << "False" << endl;
    return 0;
}
