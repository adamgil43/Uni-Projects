class Node(object):
    def __init__ (self, value):
        self.value = value
        self.AdjList = []
    def addEdge(self, n):
        #to add weight, put n and w into a touple and then add that to adjlist
        #access first edge, adglist[0][1];
        #self.AdjList.append((n,w))
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
            
    def DFS(self, start):
        stack = []
        visited = []
        stack.append(start)
        visitedNumbers = []

        while len(stack) != 0:
            u = stack.pop()
            if u not in visited:
                visited.append(u)
                for e in start.AdjList:
                    stack.append(e)
        for i in range(0, len(visited)):
            visitedNumbers.append((visited[i].value))
        with open("DFS.txt", "w") as output:
            output.write(str(visitedNumbers))

        
def main():
    L = Graph()
    n0 = Node(0)
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n4 = Node(4)
    
    n0.addEdge(n1)
    n1.addEdge(n2)
    n1.addEdge(n3)
    n2.addEdge(n3)
    n4.addEdge(n0)
    n4.addEdge(n1)
    n4.addEdge(n3)
    dfsList = L.DFS(n3)
    L.printGraph()

main()
