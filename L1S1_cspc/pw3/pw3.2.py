import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

L = 0.2  
g = 9.81 
theta0_small = np.radians(5)  
theta0_large = np.radians(90) 
omega0 = 0  
t_span = (0, 10)
t_eval = np.linspace(0, 10, 1000)
def pendulum_system(t, y):
    theta, omega = y
    dtheta_dt = omega
    domega_dt = - (g / L) * np.sin(theta)
    return [dtheta_dt, domega_dt]

sol_small = solve_ivp(pendulum_system, t_span, [theta0_small, omega0], t_eval=t_eval)
sol_large = solve_ivp(pendulum_system, t_span, [theta0_large, omega0], t_eval=t_eval)

def analytic_solution_small_angle(t, theta0):
    return theta0 * np.cos(np.sqrt(g / L) * t)

theta_analytic_small = analytic_solution_small_angle(t_eval, theta0_small)

plt.figure(figsize=(12, 6))

plt.subplot(2, 1, 1)
plt.plot(t_eval, sol_small.y[0], label='Numerical Solution (Small Angle)', color='blue')
plt.plot(t_eval, theta_analytic_small, '--', label='Analytic Solution (Small Angle)', color='red')
plt.title('Pendulum Motion: Small and Large Angles')
plt.xlabel('Time (s)')
plt.ylabel('Angle (rad)')
plt.legend()

plt.subplot(2, 1, 2)
plt.plot(t_eval, sol_large.y[0], label='Numerical Solution (Large Angle)', color='green')
plt.title('Numerical Solution for Large Angle (90 degrees)')
plt.xlabel('Time (s)')
plt.ylabel('Angle (rad)')
plt.legend()

plt.tight_layout()
plt.show()
