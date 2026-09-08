class MinPQ {
  push() {}
  pop() {}
}

function Dijkstra(n, edges) {
  const graph = Array.from({ length: n }, () => [])
  for (const [u, v, w] of edges) {
    graph[u].push([v, w])
  }

  const heap = new MinPQ()
  const distList = new Array(n).fill(Infinity)
  heap.push([0, 0])

  while (!heap.isEmpty()) {
    const [node, currWeight] = heap.pop()
    if (currWeight > distList[node]) continue

    for (const [neighbor, weight] of graph[node]) {
      const newWeight = currWeight + weight
      if (newWeight < distList[neighbor]) {
        distList[node] = newWeight
        heap.push([newWeight, neighbor])
      }
    }
  }

  return distList
}
