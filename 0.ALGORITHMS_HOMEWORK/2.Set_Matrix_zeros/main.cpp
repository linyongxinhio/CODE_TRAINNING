/**
* @description:�Ѿ�����0Ԫ�����ڵ��к��ж���Ϊ0������O(1)�Ŀռ临�Ӷ�
* @idea:1.�������
          a.��Ȼ�ռ临�Ӷ���O(1)����ô�������ԭ����Ŀռ���в�������������ʹ�ռ临�Ӷ�ΪO(1)
          b.�Ѿ����0�к͵�0����������־λ������0�к͵�0�����������������������
        2.������
          a.ɨ�軷�ڣ�
            ɨ����󣬰�0Ԫ������λ�õĵ�0�к͵�0����Ϊ0;
            �����ڵ�0�к͵�0�е�0Ԫ�أ���������Ѷ�Ӧ�Ĳ����������ΪTrue
          b.���㻷�ڣ�
            ��ɨ��һ�Σ��ѵ�0�л��ߵ�0�б����Ϊ0��λ�����ڵ��к���ȫ����Ϊ0
            �ж����������������Ե�0�к͵�0�н�����0����
* @author: ������
* @date: 2018/10/24
**/

#include <iostream>
#include <vector>
using namespace std;

void Set_Matrix_zeros(vector<vector<int> > &matrix,int m,int n)
{
     /* ������¼��0�е�Ԫ���Ƿ�Ӧ�ñ���Ϊ0�ı�־λ */
    bool ZeroRowZero = false;
    /* ������¼��0�е�Ԫ���Ƿ�Ӧ�ñ���Ϊ0�ı�־λ*/
    bool ZeroColumnZero = false;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            /* ���ĳ��Ԫ����0���ͽ���0�еĶ�Ӧ�У���0�еĶ�Ӧ����Ϊ0 */
            if (matrix[i][j] == 0)
            {
                if(i!=0 && j!=0)
                    matrix[i][0] = matrix[0][j] = 0;
                else if(i == 0)  /* ����ǵ�0�е�Ԫ����0����ô��־λZeroRowZeroӦ�ñ���Ϊ0 */
                    ZeroRowZero = true;
                else if (j == 0)  /* ����ǵ�0�е�Ԫ����0����ô��־λZeroColumnZeroӦ�ñ���Ϊ0 */
                    ZeroColumnZero = true;
            }
        }
    }

    /* ���������0�У������0�е�ĳ��Ԫ����0���ͽ���Ӧ�е�Ԫ����0������û�п��ǵ�0�е�0��*/
    for(int i = 1; i < m; ++i)
    {
        if(matrix[i][0] == 0)
        {
            for(int j = 1; j < n; ++j)
                matrix[i][j] = 0;
        }
    }

    /* ���������0�У������0�е�ĳ��Ԫ����0���ͽ���Ӧ�е�Ԫ����0������û�п��ǵ�0�е�0��*/
    for(int j = 1; j < n; ++j)
    {
        if(matrix[0][j] == 0)
        {
            for(int i = 1; i < m; ++i)
                matrix[i][j] = 0;
        }
    }

    /* ���õ�0�� */
    if(ZeroRowZero)
    {
        for(int j = 0; j < n; ++j)
            matrix[0][j] = 0;
    }
    /* ���õ�0�� */
    if(ZeroColumnZero)
    {
        for(int i = 0; i < m; ++i)
            matrix[i][0] = 0;
    }

}

int main()
{
    int m,n;
    /*����m*/
    cout << "������m��ֵ" << endl;
    cin >> m;

    /*����n*/
    cout << "������n��ֵ" << endl;
    cin >> n;

    /*����m*n����*/
    vector<vector<int> > matrix(m);
    cout << "���������" << endl;
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

    /*�����������*/
    Set_Matrix_zeros(matrix,m,n);

    /*��������ľ���*/
    cout << "��0��ľ���" << endl;
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
