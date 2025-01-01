import re
from parse_formula import parse_formula
from parse_equation import parse_equation

def is_equation_balanced(equation):
    reactants, products = parse_equation(equation)
    
    def get_total_atoms(compounds):
        total_atoms = {}
        for compound in compounds:
            count, formula = re.match(r'(\d*)([A-Za-z0-9]+)', compound).groups()
            count = int(count) if count else 1
            atoms = parse_formula(formula)
            for atom, n in atoms.items():
                total_atoms[atom] = total_atoms.get(atom, 0) + n * count
        return total_atoms

    return get_total_atoms(reactants) == get_total_atoms(products)
