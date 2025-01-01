
from scipy.integrate import odeint
import numpy as np
import pandas as pd
'''
 Deterministic Simulation
'''
def enzymatic_ode(y, t, k1, km1, k2):
    E, S, ES, P = y
    dE = -k1 * E * S + km1 * ES + k2 * ES
    dS = -k1 * E * S + km1 * ES
    dES = k1 * E * S - km1 * ES - k2 * ES
    dP = k2 * ES
    return [dE, dS, dES, dP]

time_points = np.linspace(0, 5, 500)
initial_conditions = [10, 200, 0, 0]
deterministic_results = odeint(enzymatic_ode, initial_conditions, time_points, args=(1, 0.01, 5))

deterministic_df = pd.DataFrame(deterministic_results, columns=["E", "S", "ES", "P"])
deterministic_df["time"] = time_points
print(deterministic_df)
