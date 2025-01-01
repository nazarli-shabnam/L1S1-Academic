import re

def parse_formula(formula):
    pattern = r'([A-Z][a-z]?)(\d*)'
    matches = re.findall(pattern, formula)
    atom_counts = {}
    for element, count in matches:
        count = int(count) if count else 1
        atom_counts[element] = atom_counts.get(element, 0) + count
    return atom_counts
