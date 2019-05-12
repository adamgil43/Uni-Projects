class Node(object):
    def __init__ (self, value):
        self.value = value
        self.AdjList = []
    def addEdge(self, n):
        #to add weight, put n and w into a touple and then add that to adjlist
        #access first edge, adglist[0][1];
        #self.AdjList.append((n,w))
        self.AdjList.append(n)
        n.AdjList.append(self)

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
def main():
    L = Graph()
    n0 = Node(0)
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n4 = Node(4)
    L.AddVer(n0)
    L.AddVer(n1)
    L.AddVer(n2)
    L.AddVer(n3)
    L.AddVer(n4)
    n0.addEdge(n1)
    n0.addEdge(n3)
    n0.addEdge(n4)
    n1.addEdge(n2)
    n1.addEdge(n3)
    n2.addEdge(n3)
    n3.addEdge(n4)
    L.printGraph()

main()
