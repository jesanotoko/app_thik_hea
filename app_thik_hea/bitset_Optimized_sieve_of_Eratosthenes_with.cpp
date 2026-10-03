/*
 * Algorithm Name : Bitset-Optimized Sieve of Eratosthenes with Trial Division
 * Problem Type   : Sum of Proper Divisors (SPOJ DIVSUM / DIVSUM2)
 *
 * Time Complexity:
 *   - Precomputation (Sieve) : O(MAXP * log(log(MAXP)))
 *   - Query Time per Testcase: O(sqrt(N) / log(sqrt(N)))
 * Space Complexity           : O(MAXP / 8) bytes (~12.5 MB for 10^8)
 */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

// ১০^৮ পর্যন্ত বিটসেট ও প্রাইম ভেক্টর
const int MAXP = 100000000; // 10^8
bitset<MAXP + 5> is_prime;
vector<int> primes;

// বিটসেট ও বিজোড় অপটিমাইজড সিভ (Odd-only Sieve of Eratosthenes)
void sieve() {
    is_prime.set(); // সব বিট প্রথমে 1 (true) করে নেওয়া
    is_prime[0] = is_prime[1] = 0;

    // ২-কে আলাদাভাবে যুক্ত করা
    primes.push_back(2);

    // ৩ থেকে শুরু করে শুধু বিজোড় সংখ্যা চেক করা
    for (int i = 3; i * i <= MAXP; i += 2) {
        if (is_prime[i]) {
            // j += 2*i করার মাধ্যমে শুধু বিজোড় গুণিতকগুলো কাটা হচ্ছে
            for (int j = i * i; j <= MAXP; j += 2 * i) {
                is_prime[j] = 0;
            }
        }
    }

    // সব বিজোড় প্রাইম ভেক্টরে জমা রাখা
    for (int i = 3; i <= MAXP; i += 2) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

void solve() {
    ull n;
    cin >> n;

    // ১-এর কোনো প্রোপার ডিভিজর নেই
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    ull temp = n;
    ull total_sum = 1;

    // ১০^৮ পর্যন্ত জমানো প্রাইমগুলো দিয়ে ট্রায়াল ডিভিশন
    for (int p : primes) {
        if ((ull)p * p > temp) break;

        if (temp % p == 0) {
            ull term_sum = 1;
            ull cur = 1;
            while (temp % p == 0) {
                cur *= p;          // p^1, p^2, p^3 তৈরি করা
                term_sum += cur;   // (1 + p^1 + p^2 + ...) যোগফল
                temp /= p;         // N-কে ছোট করা
            }
            total_sum *= term_sum; // সূত্রের প্রতিটি ব্র্যাকেটের গুণফল
        }
    }

    // ১০^৮ পর্যন্ত ভাগ করার পরও যদি temp > 1 থাকে,
    // তার মানে অবশিষ্ট temp নিজেই একটি বড় প্রাইম সংখ্যা
    if (temp > 1) {
        total_sum *= (temp + 1); // (1 + temp^1)
    }

    // প্রোপার ডিভিজর সাম = সব ডিভিজরের যোগফল - মূল সংখ্যা N
    cout << total_sum - n << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // প্রোগ্রাম শুরুর প্রথমেই ১০^৮ পর্যন্ত প্রাইম জেনারেট করা
    sieve();

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}