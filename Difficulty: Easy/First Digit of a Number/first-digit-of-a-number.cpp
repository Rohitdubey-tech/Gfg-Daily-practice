int firstDigit(int n) {
    // code here
   while(n>=10){
       n = n/10;
   }
   return n;
}