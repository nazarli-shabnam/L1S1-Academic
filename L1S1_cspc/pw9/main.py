from display_data import display_data
from knn_classifier import knn_classifier
from decision_tree import decision_tree
from random_forest import random_forest

def main():
    print("Displaying Training Data:")
    display_data("data/training_data.csv", "Training Data")
    
    print("\nK-Nearest Neighbors:")
    knn_classifier("data/training_data.csv", "data/verification_data.csv", n_neighbors=5)
    
    print("\nDecision Tree Classifier:")
    decision_tree("data/training_data.csv", "data/verification_data.csv")
    
    print("\nRandom Forest Classifier:")
    random_forest("data/training_data.csv", "data/verification_data.csv", n_estimators=50)

if __name__ == "__main__":
    main()
