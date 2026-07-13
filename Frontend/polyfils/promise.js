function promiseAny(iterable) {
  const requests = [...iterable]
  const requestCount = requests.length
  if (!requestCount) return new AggregateError([])

  let rejectCount = 0
  const errors = new Array(requestCount)

  return new Promise((resolve, reject) => {
    iterable.forEach((request, index) => {
      Promise.resolve(request)
        .then((res) => {
          resolve(res)
        })
        .catch((err) => {
          errors[index] = err
          rejectCount++
          if (rejectCount === requestCount) reject(new AggregateError(errors))
        })
    })
  })
}

function promiseAll(iterable) {
  const requests = [...iterable]
  const size = requests.length
  if (!size) return Promise.resolve([])
  const result = new Array(size)
  let settledCount = 0

  return new Promise((resolve, reject) => {
    requests.forEach((request, index) => {
      Promise.resolve(request)
        .then((res) => {
          result[index] = res
          settledCount++
          if (settledCount === size) resolve(result)
        })
        .catch((err) => {
          reject(err)
        })
    })
  })
}

function promiseAllSettled(iterable) {
  const requests = [...iterable]
  const size = requests.length
  if (!size) return Promise.resolve([])
  const result = new Array(size)
  let settledCount = 0

  return new Promise((resolve) => {
    requests.forEach((request, index) => {
      Promise.resolve(request)
        .then((res) => {
          result[index] = res
        })
        .catch((err) => {
          result[index] = err
        })
        .finally(() => {
          settledCount++
          if (settledCount === size) resolve(result)
        })
    })
  })
}

// The native Promise.race([]) does not resolve. It returns a promise that remains pending forever.
function promiseRace(iterable) {
  return new Promise((resolve, reject) => {
    for (const value of iterable) {
      Promise.resolve(vale).then(resolve, reject)
    }
  })
}
