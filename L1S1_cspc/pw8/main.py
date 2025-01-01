from data_mining import load_data, enrich_dataframe, display_results

def main():
    input_file = "data/AminoAcids.csv"
    output_file = "data/AminoAcids_Enriched.csv"
    
    df = load_data(input_file)
    
    enriched_df = enrich_dataframe(df)
    enriched_df.to_csv(output_file, index=False)
    
    display_results(enriched_df)

if __name__ == "__main__":
    main()
