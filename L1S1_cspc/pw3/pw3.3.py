# The double pendulum
# a. Convert the DE of the double pendulum into a set of 4 1st-order DE
# b. Use scipy.integrate to solve numerically the differential equation with 𝐿 = 1 m for 𝜃1 =
# 45° and 𝜃2 = −45° and for 𝜃1 = 30° and 𝜃2 = 0°
# c. Compare the trajectory (𝑥2 and 𝑦2) of the second mass for 𝜃1 = 89°, 90° and 91° and
# 𝜃2 = 15° . What can you say about the type of system?


import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

g = 9.81  
L1, L2 = 1.0, 1.0 
m1, m2 = 1.0, 1.0 

def double_pendulum_ode(t, y):
    theta1, theta2, omega1, omega2 = y

    delta_theta = theta1 - theta2

    num1 = -g * (2 * m1 + m2) * np.sin(theta1)
    num2 = -m2 * g * np.sin(theta1 - 2 * theta2)
    num3 = -2 * np.sin(delta_theta) * m2 * (omega2**2 * L2 + omega1**2 * L1 * np.cos(delta_theta))
    den = L1 * (2 * m1 + m2 - m2 * np.cos(2 * delta_theta))

    omega1_dot = (num1 + num2 + num3) / den

    num1 = 2 * np.sin(delta_theta)
    num2 = omega1**2 * L1 * (m1 + m2) + g * (m1 + m2) * np.cos(theta1)
    num3 = omega2**2 * L2 * m2 * np.cos(delta_theta)
    den = L2 * (2 * m1 + m2 - m2 * np.cos(2 * delta_theta))

    omega2_dot = num1 * (num2 + num3) / den

    return [omega1, omega2, omega1_dot, omega2_dot]

initial_conditions_1 = [np.radians(45), np.radians(-45), 0, 0]  # for θ1 = 45°, θ2 = -45°
initial_conditions_2 = [np.radians(30), np.radians(0), 0, 0]  # for θ1 = 30°, θ2 = 0°

t_span = (0, 10)
t_eval = np.linspace(0, 10, 1000)

sol_1 = solve_ivp(double_pendulum_ode, t_span, initial_conditions_1, t_eval=t_eval)
sol_2 = solve_ivp(double_pendulum_ode, t_span, initial_conditions_2, t_eval=t_eval)

theta1_1, theta2_1 = sol_1.y[0], sol_1.y[1]
theta1_2, theta2_2 = sol_2.y[0], sol_2.y[1]

x2_1 = L1 * np.sin(theta1_1) + L2 * np.sin(theta2_1)
y2_1 = -L1 * np.cos(theta1_1) - L2 * np.cos(theta2_1)

x2_2 = L1 * np.sin(theta1_2) + L2 * np.sin(theta2_2)
y2_2 = -L1 * np.cos(theta1_2) - L2 * np.cos(theta2_2)

plt.figure(figsize=(12, 6))

plt.subplot(2, 1, 1)
plt.plot(x2_1, y2_1, label="θ1 = 45°, θ2 = -45°", color="blue")
plt.xlabel("x (m)")
plt.ylabel("y (m)")
plt.legend()
plt.title("Trajectory of the second mass for different initial angles")

plt.subplot(2, 1, 2)
plt.plot(x2_2, y2_2, label="θ1 = 30°, θ2 = 0°", color="green")
plt.xlabel("x (m)")
plt.ylabel("y (m)")
plt.legend()

plt.tight_layout()
plt.show()
