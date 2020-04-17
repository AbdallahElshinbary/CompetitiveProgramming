Power function:

ll power(ll n, ll p) {
    ll cur = n, res = 1;
    while(p) {
        if(p&1) {
            res *= cur;
            // res %= MOD;
        }
        p /= 2;
        cur *= cur;
        //cur %= MOD;
    }
    return res;
}

//###############################################################################//

Number Theory:

Sieve:     // O(N log log N)
vector<int> primes;
bool prime[100001]{1};
void sieve() {
    prime[0] = prime[1] = 0;
    for(int i = 2;i <= 100000;i++) {
        if(!prime[i]) continue;
        primes.push_back(i);
        for(int j=i*2; j<=100000; j+=i)
            prime[j] = 0;
    }
}

int numPF(int n) {
    int ans = 0;
    for(int i=2; i*i<=n; i++) {
        while(n%i == 0) {n /= i; ans++;}
    }
    if (n != 1) ans++;   //if n is prime
    return ans;
}

// N = a^i * b^j * c^k
// numDiv = (i+1) * (j+1) * (k+1)
int numDiv(int n) {
    int ans = 1;
    for(int i=2; i*i<=n; i++) {
        int power = 0;
        while(n%i == 0) {n /= i; power++;}
        ans *= (power + 1);
    }
    if(n != 1) ans *= 2;
    return ans;
}

// N = a^i * b^j
// sumDiv = ((a^i+1 - 1)/(a-1)) * ((b^i+1 - 1)/(b-1))
int sumDiv(int n) {
    int ans = 1;
    for(int i=2; i*i<=n; i++) {
        int power = 0;
        while(n%i == 0) {n /= i; power++;}
        ans *= ((ll)pow(i, power + 1) - 1) / (i - 1);
    }
    if(n != 1) ans *= ((ll)pow(n, 2.0) - 1) / (n - 1);
    return ans;
}

//a & b coprimes --> gcd(a,b)=1
//num of ints < N that are coprimes to N
//N = 36 = 2^2 * 3^2 --> φ(n) = 36 * (1 - 1/2) * (1 - 1/3) 
int EulerPhi(int n) {
    int ans = n;
    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) ans -= ans/i;  // unique factor only
        while(n%i == 0) n /= i;
    }
    if(n != 1) ans -= ans/n;
    return ans;
}

//EulerPhi with Modified Sieve
for (int i = 1; i <= MAX_N; i++) phi[i] = i;
for (int i = 2; i <= MAX_N; i++)
    if (phi[i] == i)
        for (int j = i; j <= MAX_N; j += i)
            phi[j] = (phi[j] / i) * (i - 1);

//numDiffPF with Modified Sieve
for (int i = 2; i < MAX_N; i++)
    if (numDiffPF[i] == 0) // prime
        for (int j = i; j < MAX_N; j += i)
            numDiffPF[j]++; // increase multiples of i

void pre_compute_product_of_divisors() {
    p[0] = 0; p[1] = 1;
    if(p[2] != 0) return;
    for(ll i = 2; i < mn; i += 1) {
        if(p[i] == 0) {
            p[i] = 2;
            for(ll j = i+i; j < mn; j += i) {
                if(p[j] == 0) p[j] = 1;
                ll tmp = j;
                ll cnt = 0;
                while(tmp % i == 0) {
                    cnt += 1;
                    tmp /= i;
                }
                p[j] *= (cnt + 1);
            }
        }
    }
    for(int i = 2; i < mn; i += 1) {
        p[i] = (power(i, p[i]/2)%mod * (p[i]&1 ? (ll)sqrt(i) : 1)%mod)%mod;
    }
}


//###############################################################################//

//Linear Diophantine Equation: ax + by = c
//if c % gcd(a,b) != 0 --> no solution
//else x = x0 + k*(b/g), y = y0 − k*(a/g)  "infinite solutions"

//get x,y,gcd for any a,b  -->  ax + by = gcd
int extended_eculid(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1, y = 0;
		return a;
	}

	int g = extended_eculid(b, a%b, y, x);
	y -= (a/b)*x;
 
	return g;
}

int dioph(int a, int b, int c, int &x, int &y) {
	int g = extended_eculid(a, b, x, y);
 
	if(c%g == 0)
		x *= c/g, y *= c/g;
 
	return g;
}

// a * b ≡ 1 mod m
int modInverse(int a, int m) {
    int x, y;
    int g = extended_eculid(a, m, x, y); 
  
    if (g != 1) return -1; 
    return (x%m + m) % m; 
}

int modDivide(int a, int b, int m) { 
    a = a % m;
    int inv = modInverse(b, m); 
    if (inv == -1) return INF;  //not defined
    else return (inv * a) % m; 
}

//###############################################################################//

Matrix Power:

#define MAX_N 2
struct Matrix { int mat[MAX_N][MAX_N]; };
// we will return a 2D array
Matrix matMul(Matrix a, Matrix b) {     // O(n^3)
    Matrix ans; int i, j, k;
    for (i = 0; i < MAX_N; i++)
        for (j = 0; j < MAX_N; j++)
            for (ans.mat[i][j] = k = 0; k < MAX_N; k++)
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];   // if necessary, use mod
    return ans; 
}

Matrix matPow(Matrix base, int p) {     // O(n^3 log p)
    Matrix ans; int i, j;
    for (i = 0; i < MAX_N; i++) 
        for (j = 0; j < MAX_N; j++)
            ans.mat[i][j] = (i == j);   // prepare identity matrix
    while(p) {
        if (p & 1) ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}

DP with matrix power:
f(n+1) = a*f(n) + b*f(n-1);
| a   b | x |  f(n)  | = | f(n+1) |
| 1   0 |   | f(n-1) |   |  f(n)  |

//###############################################################################//

sum of 2 powers: 2^0 + 2^1 + 2^2 + 2^3 + ... + 2^k = 2^k+1 - 1      //2^(k+1) > 2^k+...+2^0
sum of evens: 2 + 4 + 6 + 8 + 10 = 2*(1 + 2 + 3 + 4 + 5) = 2*(n*(n+1)/2);   //n = max/2
sum of odds: 1 + 3 + 5 + 7 + 9 = (n/2)*(l+r)

//###############################################################################//

(a + b)   % p = (a % p + b % p) % p
(a * b)   % p = (a % p * b % p) % p
(a - b)   % p = ((a % p - b % p) + p) % p
(a / b)   % p = ((a % p) * (b^(-1) % p)) % p
(a ^ p)   % p = a % p
(a ^ p-1) % p = 1

//###############################################################################//

logb(x * y) = logb(x) + logb(y)
logb(x / y) = logb(x) - logb(y)
logb(x^y) = y * logb(x)
logb(c) = 1 / logc(b)
logb(x) = log(x) / log(b) --> differenent bases
log(x)=m --> e^m=x
log10(x)=m --> 10^m=x

//###############################################################################//

num of decimals ==> log(x)+1
num of decimals factorial ==> (log(x)+log(x-1)+...+log(1))+1
nearest power of b < x: floor(log(x) / log(b))
nearest power of b > x: ceil(log(x) / log(b))
lower_power_of_two = 2 ^ floor(log2(n))
upper_power_of_two = 2 ^ ceil(log2(n))

num of paths between (1, 1) to (x, y) --> x+y-2Cx-1 // draw a grid

a^n + b^n = (a + b) × (a^n−1 + b^n−1) − (a × b) × (a^n−2 + b^n−2)

//###############################################################################//

XOR interval [1, n]:
if (n mod 4 == 0) f(1, n) = n;
if (n mod 4 == 1) f(1, n) = 1;
if (n mod 4 == 2) f(1, n) = n + 1;
if (n mod 4 == 3) f(1, n) = 0;

XOR interval [l, r] = f(1, r) ^ f(1, l-1)

//###############################################################################//

Combinations:

nC0 + nC1 + nC2 + ... + nCn = 2^n "num of subsets"

// first way:
long long C[501][501];
for(int i = 0;i <= 500;i++)
    C[i][i] = C[i][0] = 1;

for(int i = 1;i <= 500;i++)
    for(int j = 1;j < i;j++)
        C[i][j] = C[i-1][j-1] + C[i-1][j]; // % MOD

// second way:
long long fact[100005];
long long inv[100005];
void pre() {
    fact[0] = inv[0] = 1;
    for(int i = 1;i <= 100000;i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = power(fact[i], MOD-2); //modular exponentiation
    }
}

long long C(int n, int k) {
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

// sequence --> order matters, collection --> order doesn't matter
// sequence without repetition   --> n! / (n-k)!   "12*11*10*9"
// sequence with repetition      --> n^k           "12*12*12*12"
// collection without repetition --> nCk
// collection with repetition    --> (n+k-1)Ck     "dots with dividers"
// multinomials "multiple choice of a set" --> n! / (a!b!c!)

//###############################################################################//

Catalan Number:
Cat(0) = 1
Cat(n + 1) = ( ((2*n + 2) * (2*n + 1)) / ((n+2) * (n+1)) ) * Cat(n)

*num of distinct binary trees with "N" vertices
*num of ways "N" parentheses are correctly matched 
*num of ways "N+1" factors can be completely parenthesized
*num of ways convex polygon "N+2" sides can be triangulated

// Derangements: num of ways where no element appears in its original position.
// !n --> derangement of n
der(n) = (n-1) * (der(n-1) + der(n-2))

//###############################################################################//

