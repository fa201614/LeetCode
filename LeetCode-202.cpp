/*bool isHappy(int n){
    while (n != 1) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10; 
            n = n / 10;
            sum += d * d;
        }
        if (sum == 4) return false;
        n = sum;
    }
    return true;
}*/

int get_next(int n) {
    int temp = 0;
    while (n) {
        temp += (n % 10) * (n % 10);
        n /= 10;
    }
    return temp;
}

bool isHappy(int n) {
    int p = n, q = n;
    while (q != 1) {
        p = get_next(p);
        q = get_next(get_next(q));
        if (p == q) break;
    }
    return q == 1;
}
