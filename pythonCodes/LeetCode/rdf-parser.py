import os
import rdflib
from rdflib import Graph
import pprint

g = Graph()
g.parse("demo.nt", format="nt")

len(g)  # prints 2

logFile = open('out.txt', 'w')
man = [0, 0]




for stmt in g:
    pprint.pprint(stmt, logFile)

if __name__ == "__main__":
    os.system('ifconfig')
