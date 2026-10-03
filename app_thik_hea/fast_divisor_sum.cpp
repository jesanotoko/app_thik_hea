#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e6; // 10^6
vector<long long> arr(MAXN + 1, 0);

// Precomputation function
void precompute_divisor_sum() {
    for (int i = 2; i * i <= MAXN; i++) {
        for (int j = i * i; j <= MAXN; j += i) {
            arr[j] += i;
            if (j / i != i) {
                arr[j] += j / i;
            }
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ১ থেকে ১০^৬ পর্যন্ত প্রি-কম্পিউটেশন
    precompute_divisor_sum();

    int n;
    cout << "Enter a number (1 to 1000000): ";
    if (cin >> n) {
        if (n < 1 || n > MAXN) {
            cout << "Out of bounds!\n";
            return 0;
        }

        cout << "--- " << n << " এর জন্য ফলাফল ---\n";
        cout << "১ এবং " << n << " ব্যতীত গুণনীয়কগুলোর যোগফল: " << arr[n] << "\n";
        
        if (n > 1) {
            cout << "প্রোপার গুণনীয়কের যোগফল (১ সহ): " << arr[n] + 1 << "\n";
            cout << "সব গুণনীয়কের মোট যোগফল (১ এবং " << n << " সহ): " << arr[n] + 1 + n << "\n";
        }
    }

    return 0;
}