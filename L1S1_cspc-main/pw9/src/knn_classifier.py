import numpy as np
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix, accuracy_score
from display_data import display_data

def knn_classifier(train_file, test_file, n_neighbors=3):
    train_data = np.loadtxt(train_file, delimiter=';')
    test_data = np.loadtxt(test_file, delimiter=';')
    
    X_train, y_train = train_data[:, :2], train_data[:, 2]
    X_test, y_test = test_data[:, :2], test_data[:, 2]
    
    knn = KNeighborsClassifier(n_neighbors=n_neighbors)
    knn.fit(X_train, y_train)
    
    y_pred_train = knn.predict(X_train)
    y_pred_test = knn.predict(X_test)

    print(f"Training Accuracy: {accuracy_score(y_train, y_pred_train)}")
    print(f"Test Accuracy: {accuracy_score(y_test, y_pred_test)}")
    
    print("Confusion Matrix (Test Data):")
    print(confusion_matrix(y_test, y_pred_test))

if __name__ == "__main__":
    knn_classifier("data/training_data.csv", "data/verification_data.csv", n_neighbors=5)
