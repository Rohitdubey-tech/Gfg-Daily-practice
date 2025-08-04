void precise(float a, float b) {
    // perform a/b
    double result= a/b;

    cout << result/*output the result of a/b here*/ << " " << setprecision(3)/*use setprecision(3) here*/
         << fixed/*use fixed here*/ << result/*Output c here*/ << endl;
}