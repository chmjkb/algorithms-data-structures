from typing import Optional
from queue import Queue


class Graph:
    """Undirected graph implementation"""
    def __init__(self, adj_map: Optional[dict[int, int]] = None) -> None:
        if adj_map is not None:
            self._adj_map = adj_map
        else:
            self._adj_map = {}

    @classmethod
    def from_txt(cls, filename: str):
        temp_graph = cls()
        with open(filename) as f:
            for line in f.readlines():
                line = line.strip().split()
                temp_graph.add_edge(int(line[0]), int(line[1]))
        return temp_graph

    @property
    def adj_map(self):
        return self._adj_map

    def add_edge(self, vertex_a: int, vertex_b: int) -> None:
        if vertex_a in self._adj_map.keys():
            if vertex_b not in self._adj_map[vertex_a]:
                self._adj_map[vertex_a].append(vertex_b)
        else:
            self._adj_map[vertex_a] = []

        if vertex_b in self._adj_map.keys():
            if vertex_a not in self._adj_map[vertex_b]:
                self._adj_map[vertex_b].append(vertex_a)
        else:
            self._adj_map[vertex_b] = []

    def get_neighbours(self, node: int) -> list[int]:
        return self._adj_map[node]

    def bfs(self, start_node: int) -> list[int]:
        visited = [start_node]
        queue = Queue()
        queue.put(start_node)
        while not queue.empty():
            m = queue.get()
            for neighbour in self.get_neighbours(m):
                if neighbour not in visited:
                    visited.append(neighbour)
                    queue.put(neighbour)
        return visited

    def dfs(self, node: int, visited: Optional[list] = None) -> list[int]:
        if visited is None:
            visited = []
        if node not in visited:
            visited.append(node)
            for neighbour in self.get_neighbours(node):
                self.dfs(neighbour, visited)
        return visited
