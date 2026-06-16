class Graph:
    def __init__(self):
        self.adjacency_list={}
    def add_node(self,node):
        if node not in self.adjacency_list:
            self.adjacency_list[node]=[]
    def add_edge(self,node1,node2):
        self.add_node(node1)
        self.add_node(node2)
        self.adjacency_list[node1].append(node2)
        self.adjacency_list[node2].append(node1)
    def display(self):
        for node, neighbours in self.adjacency_list.items():
            print(f"{node} -> {neighbours}")
            #
            #queue
            #BFS = Breadth first search
    def bfs(self,start):
        visited=set()
        queue=[start]
        visited.add(start)
        result=[]
        while queue:
            node=queue.pop(0)
            result.append(node)
            for neighbour in self.adjacency_list[node]:
                if neighbour not in visited:
                    visited.add(neighbour)
                    queue.append(neighbour)
        return result
    #
    #Stack
    #DFS = Depth first search
    def dfs(self,start,visited=None):
        if visited is None:
            visited= set()
        visited.add(start)
        print(start,end=" ")
        for neighbour in self.adjacency_list[start]:
            if neighbour not in visited:
                self.dfs(neighbour,visited)
g=Graph()
g.add_edge("A","B")
g.add_edge("A","C")
g.add_edge("B","D")
g.add_edge("C","D")
print(g.bfs("A"))
g.dfs("A")
print()
g.display()