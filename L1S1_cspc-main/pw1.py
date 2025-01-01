import time
import math
from random import randint

# Time complexity O(n)
def trapezoidal_pi(N):
    def f(x):
        return 4 / (1 + x**2)
    
    h = 1.0 / N
    
    total_sum = 0.5 * (f(0) + f(1))
    
    for i in range(1, N):
        x = i * h
        total_sum += f(x)
    
    pi_estimate = h * total_sum
    
    return pi_estimate

# Time complexity O(n)
def stochastic_pi(N):
    count_red = 0
    count_green = 0
    for _ in range(N):
        x = randint(-1,1)
        y = randint(-1,1)
        if x**2 + y**2 <= 1:
            count_green+=1
        else:
            count_red+=1
    
    ratio_of_area = count_green/(count_green+count_red)

    pi_estimate = 4 * ratio_of_area

    return pi_estimate

def relative_error(estimated_value):
    pi_actual = math.pi
    return abs((estimated_value - pi_actual) / pi_actual)

def evaluate_trapezoidal(N):
    start_time = time.time()
    pi_estimate = trapezoidal_pi(N)
    end_time = time.time()
    
    computation_time = end_time - start_time
    error = relative_error(pi_estimate)
    
    print('Trapezoidal Method')
    print(f"Estimated π: {pi_estimate}")
    print(f"Relative Error: {error}")
    print(f"Computation Time: {computation_time:.6f} seconds\n")

def evaluate_stochastic(N):
    start_time = time.time()
    pi_estimate = stochastic_pi(N)
    end_time = time.time()

    computation_time = end_time - start_time
    error = relative_error(pi_estimate)
    
    print('Stochastic Method')
    print(f"Estimated π: {pi_estimate}")
    print(f"Relative Error: {error}")
    print(f"Computation Time: {computation_time:.6f} seconds\n")

for N in [10, 100, 1000, 10000, 100000, 1000000]:
    print('************************')
    print(f'N = {N}')
    evaluate_trapezoidal(N)
    print()
    evaluate_stochastic(N)
