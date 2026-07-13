const textInput = document.getElementById("textInput")
const defaultText = document.getElementById("defaultText")
const debounceText = document.getElementById("debounceText")
const throttleText = document.getElementById("throttleText")

const updateDebounceText = debounce((text) => {
  debounceText.textContent = text
})

const updateThrottleText = throttle((text) => {
  throttleText.textContent = text
})

textInput.addEventListener("input", (e) => {
  defaultText.textContent = e.target.value
  updateDebounceText(e.target.value)
  updateThrottleText(e.target.value)
})

function debounce(cb, delay = 1000) {
  let timeout
  return (...arg) => {
    clearTimeout(timeout)
    timeout = setTimeout(() => {
      cb(arg)
    }, delay)
  }
}

function throttle(cb, delay = 1000) {
  let shouldWait = false
  let waitingArgs = null

  const timeoutFunc = () => {
    if (waitArgs === null) {
      shouldWait = false
    } else {
      cb(waitArgs)
      waitingArgs = null
      setTimeout(timeoutFunc, delay)
    }
  }

  return (...args) => {
    if (shouldWait) {
      waitArgs = args
      return
    }
    cb(args)
    shouldWait = true

    setTimeout(timeoutFunc, delay)
  }
}
