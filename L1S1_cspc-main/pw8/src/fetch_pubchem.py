import urllib.request

def fetch_pubchem_data(molecule_name, property_name):
    base_url = "https://pubchem.ncbi.nlm.nih.gov/rest/pug/compound/name/"
    formatted_name = molecule_name.lower().replace(" ", "%20")
    url = f"{base_url}{formatted_name}/property/{property_name}/TXT"
    
    try:
        with urllib.request.urlopen(url) as response:
            return response.read().decode().strip()
    except:
        return "N/A"

if __name__ == "__main__":
    print(fetch_pubchem_data("lysine", "MolecularFormula"))
    print(fetch_pubchem_data("lysine", "MolecularWeight"))
