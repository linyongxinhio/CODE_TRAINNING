# 构建二叉树的节点
class Node:
    def __init__(self,item):
        self.item = item
        self.leftchild = None
        self.rightchild = None

class Tree:
    def __init__(self):
        self.root = None

    # 层次遍历
    def traverse(self):
        if self.root is None:
            return None
        q = [self.root]
        res = [self.root.item]
        while q != []:
            pop_node = q.pop(0)
            if pop_node.leftchild is not None:
                q.append(pop_node.leftchild)
                res.append(pop_node.leftchild.item)

            if pop_node.rightchild is not None:
                q.append(pop_node.rightchild)
                res.append(pop_node.rightchild.item)
        return res

# 构建二叉树最大子树，查找子树的根节点
def construct_subtree(A, start, end):
    if start > end:  # 遍历出错，返回None
        return None
    elif start == end:  # 遍历结束，返回当前节点
        return Node(A[start])
    maxVal = 0  # 存放最大值
    maxIndex = -1  # 存放最大值的数组下标索引
    for i in range(start, end + 1):  # 查找最大值节点并记录最大值和索引
        if A[i] > maxVal:
            maxVal, maxIndex = A[i], i
    root = Node(maxVal)  # 用最大值创建新节点
    root.leftchild = construct_subtree(A, start, maxIndex - 1)  # 递归构建最大左子树
    root.rightchild = construct_subtree(A, maxIndex + 1, end)  # 递归构建最大右子树
    return root  # 返回根节点

# 构建最大二叉树
def construct_maximum_tree(A):
    if A is None or len(A) == 0:  # 如果A为空，直接返回None
        return None
    return construct_subtree(A, 0, len(A) - 1)  # 递归构建最大子树

if __name__ == '__main__':
    A=[3,2,1,6,0,5]
    t=Tree()
    t.root=construct_maximum_tree(A)
    print('层序遍历:',t.traverse())

