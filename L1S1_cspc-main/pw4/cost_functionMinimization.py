from scipy.optimize import minimize

# Cost Function Minimization Method


def cost_function_minimization():
    """
    Solve the equations using cost function minimization (SciPy).

    Returns:
        np.ndarray: Numerical solutions for VA, VB, VC, VD.
    """
    def cost_function(x, VCC, R1, R2, R3, R4):
        VA, VB, VC, VD = x
        eq1 = VA - (VCC/R1 + VC/R3 + VB/R3 + VD/R4) / (1/R1 + 2/R3 + 1/R4)
        eq2 = VB - (VCC/R2 + VD/R3 + VA/R3) / (1/R2 + 2/R3)
        eq3 = VC - (VA/R3 + VD/R3) / (1/R2 + 2/R3)
        eq4 = VD - (VB/R3 + VC/R3 + VA/R4) / (1/R1 + 2/R3 + 1/R4)
        return eq1**2 + eq2**2 + eq3**2 + eq4**2
    x0 = [0, 0, 0, 0]
    result = minimize(
        cost_function, x0, args=(15, 1000, 2000, 10000, 500), method='BFGS'
    )
    return result.x
cost_results = cost_function_minimization()
print("Cost Function Minimization Solutions (VA, VB, VC, VD):", cost_results)
