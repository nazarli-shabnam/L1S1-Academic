from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.metrics import accuracy_score, confusion_matrix
import numpy as np
import matplotlib.pyplot as plt

def decision_tree(train_file, test_file):
    train_data = np.loadtxt(train_file, delimiter=';')
    test_data = np.loadtxt(test_file, delimiter=';')
    
    X_train, y_train = train_data[:, :2], train_data[:, 2]
    X_test, y_test = test_data[:, :2], test_data[:, 2]

    tree = DecisionTreeClassifier()
    tree.fit(X_train, y_train)
    
    y_pred_test = tree.predict(X_test)

    plt.figure(figsize=(12, 8))
    plot_tree(tree, feature_names=["v0", "alpha"], class_names=["Miss", "Hit"], filled=True)
    plt.show()

    print(f"Test Accuracy: {accuracy_score(y_test, y_pred_test)}")
    print("Confusion Matrix:")
    print(confusion_matrix(y_test, y_pred_test))

if __name__ == "__main__":
    decision_tree("data/training_data.csv", "data/verification_data.csv")
