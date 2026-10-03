import random

def generate_test_case(n=100):
    max_val = (1 << 30) - 1  # 2^30 - 1
    
    # 0 থেকে 2^30 - 1 এর মধ্যে n টি র‍্যান্ডম সংখ্যা তৈরি
    numbers = [random.randint(0, max_val) for _ in range(n)]
    
    # ফাইল বা কনসোলে প্রিন্ট করা
    print(n)
    print(*numbers)

if __name__ == "__main__":
    generate_test_case(100)