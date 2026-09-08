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
function topologicalSortDFS(n, edges) {
  const graph = new Map()
  for (const [u, v] of edges) {
    if (!graph.has(u)) graph.set(u, new Array())
    graph.get(u).push(v)
  }

  const visited = new Set()
  const order = []

  const DFS = (node) => {
    visited.add(node)

    for (const neighbor of graph.get(node) ?? []) {
      if (visited.has(neighbor)) continue
      DFS(neighbor)
    }
    order.push(node)
  }

  for (let node = 0; node < n; node++) {
    if (visited.has(node)) continue
    DFS(node)
  }

  return order.reverse()
}

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

  if (result.length !== n) return []

  return result
}

console.log(topologicalSortBFS(n, edges))
