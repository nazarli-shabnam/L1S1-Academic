import pandas as pd

def load_data(file_path):
    df = pd.read_csv(file_path)
    print("Initial DataFrame:")
    print(df.head())
    return df

if __name__ == "__main__":
    df = load_data("data/AminoAcids.csv")
