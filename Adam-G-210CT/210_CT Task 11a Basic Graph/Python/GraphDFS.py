class Node(object):
    def __init__ (self, value):
        self.value = value
        self.AdjList = []
    def addEdge(self, n):
        self.AdjList.append(n)
        

class Graph(object):
    def __init__ (self):
        self.vertices = []
    def AddVer(self, Node):
        self.vertices.append(Node)
    def printGraph(self):
        print("\nNode Adjacency List")
        for Node in self.vertices:
            StringToPrint = " "
            StringToPrint = str(Node.value) + " -> "
            for i in Node.AdjList:
                StringToPrint = StringToPrint + str(i.value) + " -> "

            print (StringToPrint)
            
    def DFS(self, vertex):
        stack = []
        visited = []
        stack.append(vertex)

        while len(stack) is not 0:
            topNode = stack.pop()
            if topNode not in visited:
                visited.append(topNode)
                for e in topNode.AdjList:
                    stack.append(e)
        return visited

    def inPath(self, start, end):
        dfsResult = self.DFS(start)
        if end in dfsResult:
            return True
        return False
            
if __name__ == "__main__":
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n4 = Node(4)
    n5 = Node(5)

    L = Graph()
    
    L.AddVer(n1)
    L.AddVer(n2)
    L.AddVer(n3)
    L.AddVer(n4)
    L.AddVer(n5)
    n1.addEdge(n2)
    n2.addEdge(n3)
    n3.addEdge(n4)
    n4.addEdge(n1)
    n5.addEdge(n4)
    n1
    dfsList = L.DFS(n1)
    print (dfsList)
    L.printGraph()
    print(L.inPath(n1,n5))
