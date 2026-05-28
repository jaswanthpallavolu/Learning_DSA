const n = 6

const edges = [
  [5, 2],
  [5, 0],
  [4, 0],
  [4, 1],
  [2, 3],
  [3, 1],
]

// T.C O(V + E), S.C O(V + E)

// DFS eplore all the nodes only at once

// BFS - kahn's algorithm
function topologicalSortBFS(n, edges) {
  const graph = Array.from({ length: n }, () => [])
  const indegree = new Array(n).fill(0)

  for (const [u, v] of edges) {
    graph[u].push(v)
    indegree[v]++
  }

  const queue = []
  let head = 0
  for (let i = 0; i < n; i++) {
    if (indegree[i] === 0) queue.push(i)
  }

  const result = []
  while (head < queue.length) {
    const node = queue[head++]
    result.push(node)
    for (const neighbor of graph[node]) {
      indegree[neighbor]--
      if (indegree[neighbor] === 0) queue.push(neighbor)
    }
  }
  return result
}

console.log(topologicalSortBFS(n, edges))
