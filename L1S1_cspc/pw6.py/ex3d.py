# # Load data for measurements E and F
# measurement_e = np.loadtxt("measurement_e.txt")  # Replace with actual path
# measurement_f = np.loadtxt("measurement_f.txt")  # Replace with actual path

# # Fit the model for measurement E
# popt_e, _ = curve_fit(fluorescence_signal, time, measurement_e, bounds=(0, np.inf))
# print("Measurement E Concentrations:", popt_e)

# # Fit the model for measurement F
# popt_f, _ = curve_fit(fluorescence_signal, time, measurement_f, bounds=(0, np.inf))
# print("Measurement F Concentrations:", popt_f)

# # Analysis: Compare E and F fits
# print("Difference between fits E and F:", np.abs(popt_e - popt_f))
