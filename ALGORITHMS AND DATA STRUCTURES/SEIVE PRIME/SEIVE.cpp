/// EFFICIENT
const int MAX = (int) 1e7 + 20;
typedef long long ll;

vector <ll> primes;
bool check [MAX + 7];

void sieve () {
    check [0] = check [1] = true;
    primes.push_back (2);

    for (ll i = 3; i <= MAX; i += 2) {
        if (check [i]) continue;
        primes.push_back (i);

        for (ll j = i * i; j <= MAX; j += 2 * i)
            check [j] = true;
    }
}
