import numpy as np
import matplotlib.pyplot as plt

def display_data(file_path, title="Dataset"):
    data = np.loadtxt(file_path, delimiter=';')
    v0 = data[:, 0]  
    alpha = data[:, 1]  
    hit = data[:, 2]  

    for i in range(len(hit)):
        marker = 'o' if hit[i] == 1 else 'x' 
        color = 'blue' if hit[i] == 1 else 'red'
        plt.scatter(v0[i], alpha[i], color=color, marker=marker)

    plt.xlabel("Initial Speed (v0)")
    plt.ylabel("Angle (alpha)")
    plt.title(title)
    plt.show()

if __name__ == "__main__":
    display_data("data/training_data.csv", "Training Dataset")
