from filter_molecules import filter_molecules
from check_balanced_csv import check_balanced_equations

def main():
    molecules = filter_molecules('data/formula.csv')
    print("Molecules with 5H and 2C:", molecules)
    
    balanced_file1 = check_balanced_equations('data/balanceequation1.csv')
    balanced_file2 = check_balanced_equations('data/balanceequation2.csv')
    
    print("Balanced lines in balanceequation1.csv:", balanced_file1)
    print("Number of balanced equations in balanceequation2.csv:", len(balanced_file2))
    
    with open('results/balanced_results.txt', 'w') as f:
        f.write("Balanced lines in file 1:\n")
        f.write(str(balanced_file1) + "\n")
        f.write(f"Number of balanced equations in file 2: {len(balanced_file2)}\n")

if __name__ == "__main__":
    main()
