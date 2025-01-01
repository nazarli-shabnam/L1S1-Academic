# import numpy as np
# from scipy.optimize import curve_fit

# def fluorescence_signal(t, *concentrations):
#     lifetimes = [200.9, 5.8, 38.6, 516.2, 57.8, 8.9]  # Lifetimes in ns
#     return sum(c * np.exp(-t / tau) for c, tau in zip(concentrations, lifetimes))

# time = np.arange(0, 1000.2, 0.2)  # Time from 0 to 1000 ns with a step of 0.2 ns
# mixture_a_data = np.loadtxt("mixture_a.txt")  # Replace with actual path to data file

# popt_a, _ = curve_fit(fluorescence_signal, time, mixture_a_data, bounds=(0, np.inf))

# print("Mixture A Concentrations:", popt_a)

# # Repeat for mixtures B and C (load their respective data)
# mixture_b_data = np.loadtxt("mixture_b.txt")
# popt_b, _ = curve_fit(fluorescence_signal, time, mixture_b_data, bounds=(0, np.inf))
# print("Mixture B Concentrations:", popt_b)

# mixture_c_data = np.loadtxt("mixture_c.txt")
# popt_c, _ = curve_fit(fluorescence_signal, time, mixture_c_data, bounds=(0, np.inf))
# print("Mixture C Concentrations:", popt_c)




# import numpy as np
# from scipy.optimize import curve_fit

# # Load Data1.txt
# time = np.arange(0, 1000.2, 0.2)  # Time range based on the file description
# data_a = np.loadtxt("Data1.txt")

# # Define the fluorescence decay model
# def fluorescence_model(t, *concentrations):
#     lifetimes = [200.9, 5.8, 38.6, 516.2, 57.8, 8.9]
#     return sum(c * np.exp(-t / tau) for c, tau in zip(concentrations, lifetimes))

# # Fit the model
# popt_a, _ = curve_fit(fluorescence_model, time, data_a, bounds=(0, np.inf))
# print("Concentrations for Mixture A:", popt_a)
