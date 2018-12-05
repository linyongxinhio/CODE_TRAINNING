# 构建二叉树节点
class Node:
    def __init__(self,item):
        self.item = item
        self.leftchild = None
        self.rightchild = None

class Tree:
    def __init__(self):
        self.root = None

    # 构建二叉树，添加二叉树节点
    def add(self, item):
        node = Node(item)
        if self.root is None:#第一个结点设为树根
            self.root = node
        else:
            q = [self.root] # q的列表里存入树根

            while True:
                # 左孩子不空就加到左孩子上，右孩子不空就加到右孩子上
                # 下一循环里，q中存储了左孩子和右孩子（根节点在上一次循环里已经出栈了），然后左孩子出列表（pop(0)），把它当根节点继续
                pop_node = q.pop(0)
                if pop_node.leftchild is None:
                    pop_node.leftchild = node
                    return
                elif pop_node.rightchild is None:
                    pop_node.rightchild = node
                    return
                else: # 都不为空就代表左右孩子都赋值结束了，把左右孩子纳入q.root的树中
                    q.append(pop_node.leftchild)
                    q.append(pop_node.rightchild)


# 递归求最大深度
def maximum_depth(t):
    if t is None or t.item=="#":  # 当遇到叶子节点的时候返回0，递归的返回条件，此时为当前的最深节点
        return 0
    return max(maximum_depth(t.leftchild),maximum_depth(t.rightchild))+1  # 递归，最大深度等于左右子树中的最大深度最大值加1

if __name__ == '__main__':
    p = Tree()
    tree=[3,9,20,'#','#',15,7]
    for i in tree:  # 构建二叉树，按层次遍历来构建
        p.add(i)
    max_depth=maximum_depth(p.root)  # 求最大深度
    print('最大深度:',max_depth)

