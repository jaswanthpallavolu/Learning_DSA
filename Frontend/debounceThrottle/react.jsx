import React, { useState, useEffect, useRef, useCallback } from "react"

function APP() {
  const [text, setText] = useState(0)

  const debounceLog = useDebounce(() => {
    console.log(text)
  })
}

function useDebounce(cb, delay = 1000) {
  const timeoutRef = useRef(null)
  const callbackRef = useRef(null)

  const debouncedCallback = useCallback(
    (...args) => {
      clearTimeout(timeoutRef.current)
      timeoutRef.current = setTimeout(() => {
        callbackRef.current?.(args)
      }, delay)
    },
    [delay],
  )

  useEffect(() => {
    callbackRef.current = cb
  }, [cb])

  useEffect(() => {
    return () => clearTimeout(timeoutRef.current)
  }, [])

  return debouncedCallback
}

function useThrottle(cb, delay = 1000) {}
