/**
* @description:给定整数范围的区间为[1,n]，且给出子数组元素的个数k，输出[1,n]之间所有含k个元素的子数组
* @idea:1.递归 2.用到C++里面的容器,因为需要一个长度不固定的数组
* @author: 林永欣
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
        current_array.push_back(i);          //往容器里面最后位置添加一个元数i
        combination(current_array,n,k,i+1);  //递归调用直到满足k的数量才退出递归
        current_array.pop_back();
}      //把容器里面最后一个元数删除，进入下一轮的遍历
    }

int main()
{
    int n,k;
    cout << "输入n、k的值：" << endl;
    cin >> n >> k;

    cout << "[" << endl;
    combination(vector<int>(),n,k,1); //传入一个容器、n、k和当前位置值
    cout << "]" << endl;
    return 0;
}
