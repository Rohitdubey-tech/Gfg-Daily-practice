// User function Template for C++

bool prime(int n) {

    // Write your code here
    
    // returns a boolean value
    if (n <= 1) return false;            // 0 and 1 are not prime
    if (n == 2 || n == 3) return true;   // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false; // Eliminate multiples of 2 and 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
    
}