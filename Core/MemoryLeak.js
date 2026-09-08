// >> Event listeners
function setupButton() {
  const massiveData = new Array(5000000).fill("💾")

  const handleClick = () => {
    // This function closes over 'massiveData'
    console.log("Clicked!")
  }

  document.getElementById("my-button").addEventListener("click", handleClick)
}

setupButton()
// Later in your app, you delete "#my-button" from the UI.
// LEAK: The event listener is still attached to the global event system.
// The browser cannot delete 'massiveData' because 'handleClick' might run again!

// >> Interval Timer
function startTrackingUser() {
  let heavyUserData = {
    id: 101,
    History: [
      /* millions of items */
    ],
  }

  setInterval(() => {
    // This runs every second, forever.
    console.log("App is still alive")
  }, 1000)
}

startTrackingUser()
// Even if the user logs out and you don't need 'heavyUserData' anymore,
// LEAK: The setInterval loop keeps the entire parent scope alive!

// >> Detached DOM Nodes
// Step 1: Grab a reference to a list
let listElement = document.getElementById("heavy-list")

// Step 2: Delete the list from the user's screen
document.body.removeChild(listElement)

// LEAK: The list is gone from the UI, but it still lives in your computer's RAM.
// Why? Because the variable 'listElement' is still pointing directly to it!
