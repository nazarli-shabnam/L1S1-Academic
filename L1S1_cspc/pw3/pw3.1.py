import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

R = 1e3  # rezistor
C = 1e-9  # capacitor
V_in = 5  # input voltage=5
t_end = 10e-6  # 10 microseconds

t_span = (0, t_end)  # voltage calc
t_eval = np.linspace(0, t_end, 1000)    # evenly spaced points for the time

# how fast the voltage across the capacitor is changing at any moment.(in RC circuit)


def rc_circuit(t, V_C):
    return (V_in - V_C) / (R * C)


# solve_ivp solves the differential equation.
# rc_circuit is the equation to solve.
# [0] is the initial voltage across the capacitor (starting at 0).
# t_eval is the list of time points where we want to find the voltage.
sol = solve_ivp(rc_circuit, t_span, [0], t_eval=t_eval)

t_numeric = sol.t  # The time points from the numerical solution.
V_C_numeric = sol.y[0]

V_C_analytic = V_in * (1 - np.exp(-t_numeric / (R * C)))

relative_difference = np.abs(V_C_numeric - V_C_analytic) / V_C_analytic
#
plt.figure(figsize=(12, 6))


#
plt.subplot(2, 1, 1)
plt.plot(t_numeric * 1e6, V_C_numeric,
         label='Numerical Solution', color='blue')
plt.plot(t_numeric * 1e6, V_C_analytic, '--',
         label='Analytic Solution', color='red')
plt.title('Voltage Across the Capacitor in an RC Circuit')
plt.xlabel('Time (μs)')
plt.ylabel('Voltage (V)')
plt.legend()
#


plt.subplot(2, 1, 2)
plt.plot(t_numeric * 1e6, relative_difference,
         label='Relative Difference', color='green')
plt.title('Relative Difference Between Numerical and Analytic Solutions')
plt.xlabel('Time (μs)')
plt.ylabel('Relative Difference')

plt.tight_layout()
plt.show()
