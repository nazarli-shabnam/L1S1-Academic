import pandas as pd
from parse_formula import parse_formula

def filter_molecules(csv_file):
    df = pd.read_csv(csv_file)
    matching_molecules = []
    for formula in df['formula']:
        atom_counts = parse_formula(formula)
        if atom_counts.get('H') == 5 and atom_counts.get('C') == 2:
            matching_molecules.append(formula)
    return matching_molecules

if __name__ == "__main__":
    molecules = filter_molecules('data/formula.csv')
    print("Molecules with 5H and 2C:", molecules)
