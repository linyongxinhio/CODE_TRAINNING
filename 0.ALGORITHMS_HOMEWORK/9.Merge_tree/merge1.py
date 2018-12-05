class Node:
    def __init__(self,item):
        self.item = item
        self.child1 = None
        self.child2 = None
class Solution(object):
    def mergeTrees(self, t1, t2):
        # 结点都为空时
        if t1 is None and t2 is None:
            return
        # 只有一个结点为空时
        if t1 is None or t1.item=="#":
            return t2
        if t2 is None or t2.item=="#":
            return t1
        # 结点重叠时
        t1.item += t2.item
        # 进行迭代
        t1.child1 = self.mergeTrees(t1.child1, t2.child1)
        t1.child2 = self.mergeTrees(t1.child2, t2.child2)
        return t1

class Tree:
    def __init__(self):
        self.root = None

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
                if pop_node.child1 is None:
                    pop_node.child1 = node
                    return
                elif pop_node.child2 is None:
                    pop_node.child2 = node
                    return
                else: # 都不为空就代表左右孩子都赋值结束了，把左右孩子纳入q.root的树中
                    q.append(pop_node.child1)
                    q.append(pop_node.child2)

    # 层次遍历
    def traverse(self):
        if self.root is None:
            return None
        q = [self.root]
        res = [self.root.item]
        while q != []:
            pop_node = q.pop(0)
            if pop_node.child1 is not None:
                q.append(pop_node.child1)
                res.append(pop_node.child1.item)

            if pop_node.child2 is not None:
                q.append(pop_node.child2)
                res.append(pop_node.child2.item)
        return res

if __name__ == '__main__':
    p = Tree()
    l1=[1,3,2,5]
    l2=[2,1,3,"#",4,"#",7]
    for i in l1:
        p.add(i)
    q=Tree()
    for i in l2:
        q.add(i)
    k=Solution()
    t=Tree()
    t.root=k.mergeTrees(p.root,q.root)
    print('层序遍历:',t.traverse())

