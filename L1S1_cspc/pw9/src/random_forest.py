from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, confusion_matrix
import numpy as np

def random_forest(train_file, test_file, n_estimators=10):
    train_data = np.loadtxt(train_file, delimiter=';')
    test_data = np.loadtxt(test_file, delimiter=';')
    
    X_train, y_train = train_data[:, :2], train_data[:, 2]
    X_test, y_test = test_data[:, :2], test_data[:, 2]
    
    rf = RandomForestClassifier(n_estimators=n_estimators)
    rf.fit(X_train, y_train)
    
    y_pred_test = rf.predict(X_test)

    print(f"Test Accuracy: {accuracy_score(y_test, y_pred_test)}")
    print("Confusion Matrix:")
    print(confusion_matrix(y_test, y_pred_test))

if __name__ == "__main__":
    random_forest("data/training_data.csv", "data/verification_data.csv", n_estimators=50)
