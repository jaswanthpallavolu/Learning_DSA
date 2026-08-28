let attempts = 0

async function unstableAPI() {
  attempts++

  console.log(`Attempt ${attempts}`)

  if (attempts < 4) {
    throw new Error(`Failed on attempt ${attempts}`)
  }

  return `Success on attempt ${attempts}`
}

retry(unstableAPI, 5)
  .then((result) => console.log("Result:", result))
  .catch((err) => console.error("Error:", err.message))

function retry(task, retries) {
  function execute(resolve, reject, retryCount) {
    try {
      Promise.resolve(task())
        .then((res) => {
          resolve(res)
        })
        .catch((err) => {
          if (retryCount === 0) reject(err)
          else execute(resolve, reject, retryCount - 1)
        })
    } catch (err) {
      if (retryCount === 0) reject(err)
      else execute(resolve, reject, retryCount - 1)
    }
  }
  return new Promise((resolve, reject) => execute(resolve, reject, retries))
}
