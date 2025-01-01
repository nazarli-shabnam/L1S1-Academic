import sympy as sp
import numpy as np
from scipy.optimize import minimize

# Formal Computation Method
def formal_computation():
    """
    Solve the equations using symbolic computation (SymPy).

    Returns:
        dict: Analytical solutions for VA, VB, VC, VD as functions of input variables.
        tuple: Numerical solutions for VA, VB, VC, VD with given inputs.
    """
    # Define variables
    VA, VB, VC, VD, VCC, R1, R2, R3, R4 = sp.symbols('VA VB VC VD VCC R1 R2 R3 R4')

    # Define equations
    eq1 = sp.Eq(VA, (VCC/R1 + VC/R3 + VB/R3 + VD/R4) / (1/R1 + 2/R3 + 1/R4))
    eq2 = sp.Eq(VB, (VCC/R2 + VD/R3 + VA/R3) / (1/R2 + 2/R3))
    eq3 = sp.Eq(VC, (VA/R3 + VD/R3) / (1/R2 + 2/R3))
    eq4 = sp.Eq(VD, (VB/R3 + VC/R3 + VA/R4) / (1/R1 + 2/R3 + 1/R4))

    # Solve analytically
    solutions = sp.solve([eq1, eq2, eq3, eq4], (VA, VB, VC, VD))
    
    # Substitute numerical values
    numerical_solutions = {var: val for var, val in solutions.items()}
    numerical_values = {
        VCC: 15, R1: 1000, R2: 2000, R3: 10000, R4: 500
    }
    for var, val in numerical_values.items():
        for key in numerical_solutions:
            numerical_solutions[key] = numerical_solutions[key].subs(var, val)
    
    return solutions, numerical_solutions


# Linear Algebra Method
def linear_algebra():
    """
    Solve the equations using linear algebra (NumPy).

    Returns:
        np.ndarray: Numerical solutions for VA, VB, VC, VD.
    """
    # Matrix representation
    A = np.array([
        [1/(1/1000 + 2/10000 + 1/500), 1/10000, 1/10000, 1/500],
        [1/10000, 1/(1/2000 + 2/10000), 1/10000, 0],
        [0, 1/10000, 1/(1/2000 + 2/10000), 1/10000],
        [1/500, 1/10000, 1/10000, 1/(1/1000 + 2/10000 + 1/500)],
    ])
    B = np.array([15/1000, 15/2000, 0, 0])
    
    # Solve Ax = B
    x = np.linalg.solve(A, B)
    return x


# Cost Function Minimization Method
def cost_function_minimization():
    """
    Solve the equations using cost function minimization (SciPy).

    Returns:
        np.ndarray: Numerical solutions for VA, VB, VC, VD.
    """
    # Define cost function
    def cost_function(x, VCC, R1, R2, R3, R4):
        VA, VB, VC, VD = x
        eq1 = VA - (VCC/R1 + VC/R3 + VB/R3 + VD/R4) / (1/R1 + 2/R3 + 1/R4)
        eq2 = VB - (VCC/R2 + VD/R3 + VA/R3) / (1/R2 + 2/R3)
        eq3 = VC - (VA/R3 + VD/R3) / (1/R2 + 2/R3)
        eq4 = VD - (VB/R3 + VC/R3 + VA/R4) / (1/R1 + 2/R3 + 1/R4)
        return eq1**2 + eq2**2 + eq3**2 + eq4**2

    # Initial guess
    x0 = [0, 0, 0, 0]

    # Minimize cost function
    result = minimize(
        cost_function, x0, args=(15, 1000, 2000, 10000, 500), method='BFGS'
    )
    return result.x


if __name__ == "__main__":
    # Formal computation
    print("Formal Computation Results:")
    solutions, numerical = formal_computation()
    print("Analytical Solutions:", solutions)
    print("Numerical Solutions:", numerical)

    # Linear algebra
    print("\nLinear Algebra Results:")
    linear_results = linear_algebra()
    print("VA, VB, VC, VD:", linear_results)

    # Cost function minimization
    print("\nCost Function Minimization Results:")
    cost_results = cost_function_minimization()
    print("VA, VB, VC, VD:", cost_results)
