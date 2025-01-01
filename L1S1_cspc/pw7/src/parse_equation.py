def parse_equation(equation):
    reactants, products = equation.split("->")
    reactants = [compound.strip() for compound in reactants.split("+")]
    products = [compound.strip() for compound in products.split("+")]
    return reactants, products
