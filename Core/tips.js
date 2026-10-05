const intervals = []
const sorted = intervals.sort((a, b) => {
  if (a[0] === b[0]) return a[1] - b[1]
  return a[0] - b[0]
})

const sorted1 = intervals.sort((a, b) => a[0] - b[0] || a[1] - b[1])
