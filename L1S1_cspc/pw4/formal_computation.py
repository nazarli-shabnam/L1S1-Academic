import sympy as sp

# Formal Computation Method
def formal_computation():
    """
    Solve the equations using symbolic computation (SymPy).

    Returns:
        dict: Analytical solutions for VA, VB, VC, VD as functions of input variables.
        dict: Numerical solutions for VA, VB, VC, VD with given inputs.
    """
    # Define variables
    VA, VB, VC, VD, VCC, R1, R2, R3, R4 = sp.symbols('VA VB VC VD VCC R1 R2 R3 R4')

    # Define equations
    eq1 = sp.Eq(VA, (VCC/R1 + VC/R3 + VB/R3 + VD/R4) / (1/R1 + 2/R3 + 1/R4))
    eq2 = sp.Eq(VB, (VCC/R2 + VD/R3 + VA/R3) / (1/R2 + 2/R3))
    eq3 = sp.Eq(VC, (VA/R3 + VD/R3) / (1/R2 + 2/R3))
    eq4 = sp.Eq(VD, (VB/R3 + VC/R3 + VA/R4) / (1/R1 + 2/R3 + 1/R4))

    """Solve analytically"""
    solutions = sp.solve([eq1, eq2, eq3, eq4], (VA, VB, VC, VD))
    
    """Substitute numerical values"""
    numerical_values = {VCC: 15, R1: 1000, R2: 2000, R3: 10000, R4: 500}
    numerical_solutions = {var: expr.subs(numerical_values) for var, expr in solutions.items()}
    
    return solutions, numerical_solutions
analytical, numerical = formal_computation()
print("Formal Computation Analytical Solutions:", analytical)
print("Formal Computation Numerical Solutions:", numerical)
