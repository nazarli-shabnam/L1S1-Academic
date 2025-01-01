import random
import pandas as pd
# First Problem: Simple Reaction
# Gillespie's Algorithm

def gillespie_simple_reaction(kf, kr, A0, B0, AB0, max_time):
    A, B, AB = A0, B0, AB0
    time = 0
    results = {"time": [time], "A": [A], "B": [B], "AB": [AB]}
    
    while time < max_time:
        r1 = kf * A * B
        r2 = kr * AB
        total_rate = r1 + r2
        if total_rate == 0:
            break
        
        tau = random.expovariate(total_rate)
        time += tau
        if random.random() < r1 / total_rate:
            A -= 1
            B -= 1
            AB += 1
        else:
            A += 1
            B += 1
            AB -= 1
        
        results["time"].append(time)
        results["A"].append(A)
        results["B"].append(B)
        results["AB"].append(AB)
    
    return pd.DataFrame(results)

kf, kr = 0.05, 0.005
A0, B0, AB0 = 800, 400, 100
max_time = 1
simple_reaction_results = gillespie_simple_reaction(kf, kr, A0, B0, AB0, max_time)
print(simple_reaction_results)
simulations = [gillespie_simple_reaction(kf, kr, A0, B0, AB0, max_time).iloc[-1] for _ in range(100)]
averages = pd.DataFrame(simulations).mean()
print("Averages over 100 simulations:")
print(averages)
