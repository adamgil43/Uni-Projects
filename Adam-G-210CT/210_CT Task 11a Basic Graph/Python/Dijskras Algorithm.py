class Node(object):
    def __init__ (self, value):
        self.value = value
        self.AdjList = []
    def addEdge(self, n, w):
        #to add weight, put n and w into a touple and then add that to adjlist
        #access first edge, adglist[0][1];
        #self.AdjList.append((n,w))
        self.AdjList.append((n, w))
        

class Graph(object):
    def __init__ (self):
        self.vertices = []
    def AddVer(self, Node):
        self.vertices.append(Node)
    def printGraph(self):
        print("\nNode Adjacency List")

        for Node in self.vertices:
            StringToPrint = " "
            StringToPrint = str(Node) + " -> "
            for i in Node.AdjList:
                nodeVal = n1.AdjList[i][0]
                nodeWeight = n1.AdjList[i][1]
                StringToPrint = StringToPrint + "weight: " + str(nodeWeight) + "to node: " + str(nodeVal.value) + " -> "
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
    n1.addEdge(n2, 2)
    n1.addEdge(n3, 5)
    n1.addEdge(n4, 6)
    n2.addEdge(n4, 3)
    n3.addEdge(n4, 1)
    n3.addEdge(n5, 5)
    n4.addEdge(n5, 3)
    nodeVal = n1.AdjList[0][0]
    nodeWeight = n1.AdjList[0][1]
    print (str(n1.value) + "\n")
    print (str(nodeVal.value) + "\n")
    print (nodeWeight)
    L.printGraph()
    
