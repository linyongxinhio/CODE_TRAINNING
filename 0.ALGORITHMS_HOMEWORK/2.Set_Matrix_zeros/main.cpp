/**
* @description:把矩阵中0元数所在的行和列都置为0，采用O(1)的空间复杂度
* @idea:1.总体介绍
          a.既然空间复杂度是O(1)，那么最好是在原矩阵的空间进行操作，这样可以使空间复杂度为O(1)
          b.把矩阵第0行和第0列用来做标志位，而第0行和第0列用两个布尔变量来做标记
        2.处理步骤
          a.扫描环节：
            扫描矩阵，把0元素所在位置的第0行和第0列置为0;
            处理处于第0行和第0列的0元素，若存在则把对应的布尔变量标记为True
          b.置零环节：
            再扫描一次，把第0行或者第0列标记了为0的位置所在的列和行全部置为0
            判断两个布尔变量并对第0行和第0列进行置0处理
* @author: 林永欣
* @date: 2018/10/24
**/

#include <iostream>
#include <vector>
using namespace std;

void Set_Matrix_zeros(vector<vector<int> > &matrix,int m,int n)
{
     /* 用来记录第0行的元素是否应该被置为0的标志位 */
    bool ZeroRowZero = false;
    /* 用来记录第0列的元素是否应该被置为0的标志位*/
    bool ZeroColumnZero = false;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            /* 如果某个元素是0，就将第0行的对应列，第0列的对应行置为0 */
            if (matrix[i][j] == 0)
            {
                if(i!=0 && j!=0)
                    matrix[i][0] = matrix[0][j] = 0;
                else if(i == 0)  /* 如果是第0行的元素是0，那么标志位ZeroRowZero应该被置为0 */
                    ZeroRowZero = true;
                else if (j == 0)  /* 如果是第0列的元素是0，那么标志位ZeroColumnZero应该被置为0 */
                    ZeroColumnZero = true;
            }
        }
    }

    /* 遍历矩阵第0列，如果第0列的某个元素是0，就将对应行的元素置0，这里没有考虑第0行第0列*/
    for(int i = 1; i < m; ++i)
    {
        if(matrix[i][0] == 0)
        {
            for(int j = 1; j < n; ++j)
                matrix[i][j] = 0;
        }
    }

    /* 遍历矩阵第0行，如果第0行的某个元素是0，就将对应列的元素置0，这里没有考虑第0行第0列*/
    for(int j = 1; j < n; ++j)
    {
        if(matrix[0][j] == 0)
        {
            for(int i = 1; i < m; ++i)
                matrix[i][j] = 0;
        }
    }

    /* 设置第0行 */
    if(ZeroRowZero)
    {
        for(int j = 0; j < n; ++j)
            matrix[0][j] = 0;
    }
    /* 设置第0列 */
    if(ZeroColumnZero)
    {
        for(int i = 0; i < m; ++i)
            matrix[i][0] = 0;
    }

}

int main()
{
    int m,n;
    /*输入m*/
    cout << "请输入m的值" << endl;
    cin >> m;

    /*输入n*/
    cout << "请输入n的值" << endl;
    cin >> n;

    /*输入m*n矩阵*/
    vector<vector<int> > matrix(m);
    cout << "请输入矩阵" << endl;
    for(int i=0;i<m;i++)
    {
        matrix[i].resize(n);
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> matrix[i][j];
        }
    }

    /*进行置零操作*/
    Set_Matrix_zeros(matrix,m,n);

    /*输出置零后的矩阵*/
    cout << "置0后的矩阵" << endl;
    cout << "[" << endl;
    for (int i=0;i<m;i++)
    {
        cout << "  [" ;
        for (int j=0;j<n-1;j++)
        {
            cout << matrix[i][j] << ',';
        }
        cout << matrix[i][n-1] << "]," << endl;
    }
    cout << "]" << endl;

    return 0;
}
