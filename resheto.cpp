#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> sieveOfEratosthenes(int n) {
    std::vector<bool> isPrime(n + 1, true); // Изначально все числа предполагаются простыми
    std::vector<int> primes; // Список простых чисел

    isPrime[0] = isPrime[1] = false; // 0 и 1 не являются простыми числами

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            // Зачеркиваем числа, начиная с p^2 с шагом p
            for (int multiple = p * p; multiple <= n; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    // Сохраняем все не зачеркнутые числа, которые являются простыми
    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

int main() {
    int n;
    std::cout << "Введите число n: ";
    std::cin >> n;

    std::vector<int> primes = sieveOfEratosthenes(n);

    std::cout << "Простые числа до " << n << ": ";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}