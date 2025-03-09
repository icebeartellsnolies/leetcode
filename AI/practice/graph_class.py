# directed graph
class node:
    def __init__(self, value):
        self.val=value

class graph:
    def __init__(self):
        self.adj_list=dict()
    
    def add_node(self, n):
        self.adj_list[n.val]=[]
    
    def __str__(self):
        return f'{self.adj_list}'
    
    def add_edge(self, n, neighbor):
        self.adj_list[n.val].append(neighbor.val)
    
    def remove_edge(self,node,neigbor):
        self.adj_list[node.val].remove(neigbor.val)

    def remove_node(self, node):
        new_dict=dict()
        for edge in self.adj_list.items():
            n=edge[0]
            neighs=edge[1]
            if n==node.val:
                continue
            else:
                new_dict[n]=neighs
        self.adj_list=new_dict
        for edge in self.adj_list.items():
            n=edge[0]
            neighs=edge[1]
            if node.val in neighs:
                neighs.remove(node.val)
                self.adj_list[n]=neighs


            
            
def main():
    n2=node(2)
    n5=node(5)
    n1=node(1)
    n3=node(3)
    n6=node(6)
    n4=node(4)
    g=graph()
    g.add_node(n2)
    g.add_node(n1)
    g.add_node(n6)
    g.add_node(n3)
    g.add_node(n4)
    g.add_node(n5)
    g.add_edge(n2,n1)
    g.add_edge(n2,n6)
    g.add_edge(n2,n3)
    g.add_edge(n6, n1)
    g.add_edge(n6, n5)
    g.add_edge(n6, n4)
    g.add_edge(n4,n3)
    print(g)
    g.remove_node(n4)
    print(g)
    # g.remove_edge(n1,n2)
    # print(g)

main()