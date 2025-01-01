import numpy as np

# Linear Algebra Method
def linear_algebra():
    """
    Solve the equations using linear algebra (NumPy).

    Returns:
        np.ndarray: Numerical solutions for VA, VB, VC, VD.
    """
    """Define matrix A and vector B"""
    A = np.array([
        [1/(1/1000 + 2/10000 + 1/500), 1/10000, 1/10000, 1/500],
        [1/10000, 1/(1/2000 + 2/10000), 1/10000, 0],
        [0, 1/10000, 1/(1/2000 + 2/10000), 1/10000],
        [1/500, 1/10000, 1/10000, 1/(1/1000 + 2/10000 + 1/500)],
    ])
    B = np.array([15/1000, 15/2000, 0, 0])
    
    """ Solve Ax = B"""
    x = np.linalg.solve(A, B)
    return x

linear_results = linear_algebra()
print("Linear Algebra Solutions (VA, VB, VC, VD):", linear_results)
