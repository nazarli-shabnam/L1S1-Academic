import pandas as pd
from is_balanced import is_equation_balanced

def check_balanced_equations(csv_file):
    df = pd.read_csv(csv_file)
    balanced_lines = []
    
    for i, equation in enumerate(df['equation'], start=1):
        if is_equation_balanced(equation):
            balanced_lines.append(i)
    
    return balanced_lines

if __name__ == "__main__":
    balanced_lines_1 = check_balanced_equations('data/balanceequation1.csv')
    print("Balanced lines in file 1:", balanced_lines_1)
