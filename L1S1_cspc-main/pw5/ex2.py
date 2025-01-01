'''
Second Problem: Enzymatic Reaction
Gillespie's Algorithm
'''
import random
import pandas as pd


def gillespie_enzymatic(k1, km1, k2, E0, S0, P0, ES0, max_time):
    E, S, P, ES = E0, S0, P0, ES0
    time = 0
    results = {"time": [time], "E": [E], "S": [S], "P": [P], "ES": [ES]}

    while time < max_time:
        r1 = k1 * E * S
        r2 = km1 * ES
        r3 = k2 * ES
        total_rate = r1 + r2 + r3
        if total_rate == 0:
            break

        tau = random.expovariate(total_rate)
        time += tau
        prob = random.random()

        if prob < r1 / total_rate:
            # E + S -> ES
            E -= 1
            S -= 1
            ES += 1
        elif prob < (r1 + r2) / total_rate:
            # ES -> E + S
            E += 1
            S += 1
            ES -= 1
        else:
            # ES -> E + P
            E += 1
            P += 1
            ES -= 1

        results["time"].append(time)
        results["E"].append(E)
        results["S"].append(S)
        results["P"].append(P)
        results["ES"].append(ES)

    return pd.DataFrame(results)


k1, km1, k2 = 1, 0.01, 5
E0, S0, P0, ES0 = 10, 200, 0, 0
max_time = 5

enzymatic_results = gillespie_enzymatic(k1, km1, k2, E0, S0, P0, ES0, max_time)
print(enzymatic_results)
