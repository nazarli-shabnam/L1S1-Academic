import re

def parse_formula(formula):
    pattern = r'([A-Z][a-z]*)(\d*)'
    matches = re.findall(pattern, formula)
    atom_counts = {"C": 0, "H": 0, "N": 0, "O": 0, "S": 0}
    
    for element, count in matches:
        count = int(count) if count else 1
        if element in atom_counts:
            atom_counts[element] += count
    return atom_counts
from fetch_pubchem import fetch_pubchem_data
from parse_formula import parse_formula

def enrich_dataframe(df):
    df["Formula"] = df["FullName"].apply(lambda x: fetch_pubchem_data(x, "MolecularFormula"))
    df["MolecularWeight"] = df["FullName"].apply(lambda x: fetch_pubchem_data(x, "MolecularWeight"))
    
    atom_columns = ["C", "H", "N", "O", "S"]
    for col in atom_columns:
        df[col] = df["Formula"].apply(lambda x: parse_formula(x).get(col, 0))
    
    print("Enriched DataFrame:")
    print(df.head())
    return df

if __name__ == "__main__":
    df = load_data("data/AminoAcids.csv")
    enriched_df = enrich_dataframe(df)
    enriched_df.to_csv("data/AminoAcids_Enriched.csv", index=False)

def display_results(df):
    print("\nAll information about Lysine:")
    print(df[df["FullName"] == "Lysine"])
    
    print("\nThe heaviest amino acid:")
    print(df.loc[df["MolecularWeight"].astype(float).idxmax()])
    
    print("\nAmino acids with positive polarization:")
    print(df[df["Polarization"] == "Positive"])
    
    print("\nCount of molecules by polarization type:")
    print(df["Polarization"].value_counts())
    
    print("\nThe heaviest molecule for each type of polarization:")
    print(df.loc[df.groupby("Polarization")["MolecularWeight"].astype(float).idxmax()])
    
    print("\nMolecules containing sulfur:")
    print(df[df["S"] > 0])
    
    print("\nMolecule with the most hydrogens:")
    print(df.loc[df["H"].idxmax()])

if __name__ == "__main__":
    df = pd.read_csv("data/AminoAcids_Enriched.csv")
    display_results(df)
