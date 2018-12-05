# 构建节点
class Node:
    def __init__(self,item):
        self.item = item
        self.child1 = None
        self.child2 = None

# 递归搜索
class solution():
    def search(self,tree,k):
        if  tree is None:
            return
        if tree.item==k:
            return tree
        elif tree.item>k:
            return self.search(tree.child1,k)
        elif tree.item<k:
            return self.search(tree.child2,k)

class Tree:
    def __init__(self):
        self.root = None

    # 往树里添加元素
    def add(self, item):
        node = Node(item)
        if self.root is None:
            self.root = node
        else:
            q = [self.root]

            while True:
                pop_node = q.pop(0)
                if pop_node.child1 is None:
                    pop_node.child1 = node
                    return
                elif pop_node.child2 is None:
                    pop_node.child2 = node
                    return
                else:
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
    k=solution()
    p = Tree()
    l1=[4,2,7,1,3]
    for i in l1:
        p.add(i)
    t=Tree()
    t.root=k.search(p.root,2) # 递归查找要查找的节点
    print('层序遍历:',t.traverse())
