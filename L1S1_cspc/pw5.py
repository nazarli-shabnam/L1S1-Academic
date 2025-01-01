import numpy as np
import matplotlib.pyplot as plt

A0 = 50
B0 = 50
AB0 = 0
kf = 0.1
kr = 0.05
max_time = 10
# notes for myself:

# a(forward)=kf*A*B
# a(reverse)=kr*A*B
# a(total)=a(forward)+a(reverse)

# If r<aforwardr<aforward​, the forward reaction occurs: decrease AA and BB by 1, and increase ABAB by 1.
# Otherwise, the reverse reaction occurs: increase AA and BB by 1, and decrease ABAB by 1.


A, B, AB = A0, B0, AB0
time = 0.0
times = [time]
A_values = [A]
B_values = [B]
AB_values = [AB]

while time < max_time:
    a_forward = kf * A * B
    a_reverse = kr * AB
    a_total = a_forward + a_reverse

    if a_total == 0:
        break

    delta_t = np.random.exponential(1 / a_total)
    time += delta_t

    r = np.random.uniform(0, a_total)
    if r < a_forward:
        if A > 0 and B > 0:
            A -= 1
            B -= 1
            AB += 1
    else:
        if AB > 0:  # Ensuring that there enough AB
            A += 1
            B += 1
            AB -= 1

    times.append(time)
    A_values.append(A)
    B_values.append(B)
    AB_values.append(AB)

plt.plot(times, A_values, label='A')
plt.plot(times, B_values, label='B')
plt.plot(times, AB_values, label='AB')
plt.xlabel('Time')
plt.ylabel('Molecule Count')
plt.legend()
plt.show()
