
from typing import List

class Solution:

    def sumOfPowers(self, a: int, b: int) -> int:

        def sieve_of_eratosthenes(limit):

            primes = [True] * (limit + 1)

            primes[0] = primes[1] = False

 

            for i in range(2, int(limit**0.5) + 1):

                if primes[i]:

                    for j in range(i*i, limit + 1, i):

                        primes[j] = False

 

            return [num for num in range(2, limit + 1) if primes[num]]

 

        def prime_factors_count_sieve(num, primes):

            factors_count = {}

            for prime in primes:

                if prime * prime > num:

                    break

                while num % prime == 0:

                    num //= prime

                    factors_count[prime] = factors_count.get(prime, 0) + 1

            if num > 1:

                factors_count[num] = factors_count.get(num, 0) + 1

            return factors_count

 

        primes_up_to_b = sieve_of_eratosthenes(b)

        total_sum = 0

 

        for num in range(a, b + 1):

            factors_count = prime_factors_count_sieve(num, primes_up_to_b)

            total_sum += sum(factors_count.values())

 

        return total_sum

#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        a=int(input())
        b=int(input())
        
        obj = Solution()
        res = obj.sumOfPowers(a,b)
        
        print(res)
        

# } Driver Code Ends