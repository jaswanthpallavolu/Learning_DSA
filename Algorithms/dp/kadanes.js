// choices
// const nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
const maxSubArray = function (nums) {
  let res = nums[0]
  let maxEnding = 0
  for (let i = 0; i < nums.length; i++) {
    maxEnding = Math.max(maxEnding + nums[i], nums[i])
    res = Math.max(res, maxEnding)
  }
  return res
}

// console.log(maxSubArray(nums))
