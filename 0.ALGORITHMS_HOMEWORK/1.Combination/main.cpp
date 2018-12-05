/**
* @description:����������Χ������Ϊ[1,n]���Ҹ���������Ԫ�صĸ���k�����[1,n]֮�����к�k��Ԫ�ص�������
* @idea:1.�ݹ� 2.�õ�C++���������,��Ϊ��Ҫһ�����Ȳ��̶�������
* @author: ������
* @date: 2018/10/17
**/
#include <iostream>
#include <vector>

using namespace std;

void combination(vector<int> current_array,int n,int k,int current_pos)
{
    if (current_array.size()==k)
    {
        unsigned int i;
        cout << "  [";
        for (i=0;i<k-1;i++)
        {
            cout << current_array[i] << ',';
        }
        cout << current_array[i] << "]," << endl;
        return;
    }
    unsigned int i;
    for (i=current_pos;i<=n;i++)
    {
        current_array.push_back(i);          //�������������λ�����һ��Ԫ��i
        combination(current_array,n,k,i+1);  //�ݹ����ֱ������k���������˳��ݹ�
        current_array.pop_back();
}      //�������������һ��Ԫ��ɾ����������һ�ֵı���
    }

int main()
{
    int n,k;
    cout << "����n��k��ֵ��" << endl;
    cin >> n >> k;

    cout << "[" << endl;
    combination(vector<int>(),n,k,1); //����һ��������n��k�͵�ǰλ��ֵ
    cout << "]" << endl;
    return 0;
}
