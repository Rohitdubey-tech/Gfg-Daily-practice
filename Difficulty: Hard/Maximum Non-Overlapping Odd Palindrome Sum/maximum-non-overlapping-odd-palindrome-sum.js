
function manacherArray(s) {
  // Transform string with sentinels to handle even/odd palindromes uniformly
  const ms = "@#" + s.split("").join("#") + "#$";
  const n = ms.length;
  const p = new Array(n).fill(0);

  let l = 0,
    r = 0; // current rightmost palindrome [l ... r]
  for (let i = 1; i < n - 1; i++) {
    const mirror = l + r - i;
    if (mirror >= 0 && mirror < n) {
      p[i] = Math.max(0, Math.min(r - i, p[mirror]));
    }
    while (
      i + p[i] + 1 < n &&
      i - p[i] - 1 >= 0 &&
      ms[i + 1 + p[i]] === ms[i - 1 - p[i]]
    ) {
      p[i]++;
    }
    if (i + p[i] > r) {
      l = i - p[i];
      r = i + p[i];
    }
  }
  return { p, ms };
}

// Helper: get length of longest palindrome (odd/even) centered at a given original index
function getLongest(cen, odd, p) {
  const pos = 2 * cen + 2 + (odd === 0 ? 1 : 0); // mapping to transformed index
  return p[pos];
}

class Solution {
  maxSum(s) {
    const n = s.length;
    if (n < 2) return 0;

    const leftMark = new Array(n).fill(1);
    const rightMark = new Array(n).fill(1);

    const { p } = manacherArray(s);

    // Longest odd-length palindrome ending at or before each index
    for (let i = 0; i < n; i++) {
      const val = getLongest(i, 1, p); // odd palindromes only
      const li = i + Math.floor(val / 2);
      if (li < n) leftMark[li] = Math.max(leftMark[li], val);
    }
    // Shrink values by 2 moving leftwards to respect end boundary
    for (let i = n - 2; i >= 0; i--) {
      leftMark[i] = Math.max(leftMark[i], leftMark[i + 1] - 2);
    }
    // Prefix max
    for (let i = 1; i < n; i++) {
      leftMark[i] = Math.max(leftMark[i], leftMark[i - 1]);
    }

    // Longest odd-length palindrome starting at or after each index
    for (let i = n - 1; i >= 0; i--) {
      const val = getLongest(i, 1, p);
      const ri = i - Math.floor(val / 2);
      if (ri >= 0) rightMark[ri] = Math.max(rightMark[ri], val);
    }
    // Shrink values by 2 moving rightwards to respect start boundary
    for (let i = 1; i < n; i++) {
      rightMark[i] = Math.max(rightMark[i], rightMark[i - 1] - 2);
    }
    // Suffix max
    for (let i = n - 2; i >= 0; i--) {
      rightMark[i] = Math.max(rightMark[i], rightMark[i + 1]);
    }

    // Combine — choose split i between left and right palindromes
    let ans = 0;
    for (let i = 0; i + 1 < n; i++) {
      ans = Math.max(ans, leftMark[i] + rightMark[i + 1]);
    }

    return ans;
  }
}