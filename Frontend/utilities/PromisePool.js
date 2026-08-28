// Promise Pool (Concurrency Limiter)

// Concurrency: Multiple tasks are in progress at the same time by interleaving their execution.
//  A single CPU core can achieve this by rapidly switching between tasks.
// Parallelism: Multiple tasks execute simultaneously, usually on multiple CPU cores.

// Problem: You have many async tasks, but you only want to run N at a time.

function delay(ms, value) {
  return new Promise((resolve) => {
    setTimeout(() => resolve(value), ms)
  })
}

const tasks = [
  () => delay(3000, "A"),
  () => delay(1000, "B"),
  () => delay(2000, "C"),
  () => delay(500, "D"),
  () => delay(1500, "E"),
]

promisePool(tasks, 2).then(console.log).catch(console.error)

function promisePool(tasks, limit) {
  const totalTasks = tasks.length
  let running = 0
  let completed = 0
  let nextTaskIndex = 0
  let failed = false
  const result = new Array(totalTasks)

  function executeTasks(resolve, reject) {
    if (failed) return
    if (totalTasks === 0 || limit === 0) {
      resolve([])
      return
    }
    let freeSlots = limit - running
    while (!failed && freeSlots > 0 && nextTaskIndex < totalTasks) {
      const currIndex = nextTaskIndex
      const task = tasks[nextTaskIndex++]
      // to Handle both synchronus and asynchronus errors
      try {
        Promise.resolve(task())
          .then((res) => {
            result[currIndex] = res
          })
          .catch((err) => {
            reject(err)
            failed = true
          })
          .finally(() => {
            running--
            completed++
            if (completed === totalTasks) resolve(result)
            else executeTasks(resolve, reject)
          })
      } catch (err) {
        reject(err)
        running--
        failed = true
      }
      running++
      freeSlots--
    }
  }

  return new Promise(executeTasks)
}
