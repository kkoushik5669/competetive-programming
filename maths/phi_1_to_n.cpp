void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
//same approach as seives apparently so time complexity is O(nloglogn)
//divisor sum property summation of phi(every divisor of n)=n with this approach phi from 1 to n can be found in O(nlogn)
