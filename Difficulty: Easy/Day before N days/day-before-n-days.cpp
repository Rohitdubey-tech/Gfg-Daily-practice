// User function Template for C++

int nthDay(int d, int n) {

    // write your code here
    return (d - n % 7 + 7) % 7;
}