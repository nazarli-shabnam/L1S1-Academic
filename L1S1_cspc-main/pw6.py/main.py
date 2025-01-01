import numpy as np
import struct
from scipy.optimize import curve_fit
import os

MOLECULE_LIFETIMES = [200.9, 5.8, 38.6, 516.2, 57.8, 8.9]

MOLECULE_NAMES = [
    "Naphthalene", "Anthracene", "Benzopyrene",
    "Pyrene", "Chrysene", "Benzofluoranthene"
]

def read_text_file(filepath):
    """
    This function loads fluorescence data from a plain text file.

    Parameters:
        filepath (str): Path to the text file.

    Returns:
        numpy.ndarray: Array of fluorescence signal values.
    """
    try:
        data = np.loadtxt(filepath)
        return data
    except Exception as e:
        raise ValueError(f"Error reading {filepath}: {e}")

def read_binary_file(filepath, scaling_factor=10):
    """
    this function reads and scales fluorescence data from a binary file.

    Parameters:
        filepath (str): Path to the binary file.
        scaling_factor (float): Scaling factor for fluorescence data.

    Returns:
        numpy.ndarray: Scaled fluorescence signal values.
    """
    try:
        with open(filepath, 'rb') as f:
            raw_data = struct.unpack(
                'H' * (os.path.getsize(filepath) // 2),
                f.read()
            )
        return np.array(raw_data) * scaling_factor / 65535
    except Exception as e:
        raise ValueError(f"Error reading binary file {filepath}: {e}")

def total_fluorescence_signal(time, *amplitudes):
    """
    This function calculates the total fluorescence signal for a mixture.

    Parameters:
        time (numpy.ndarray): Array of time values.
        amplitudes (tuple): Amplitudes (concentrations) of the molecules.

    Returns:
        numpy.ndarray: Total fluorescence signal over time.
    """
    signal = np.zeros_like(time)
    for i, amplitude in enumerate(amplitudes):
        signal += amplitude * np.exp(-time / MOLECULE_LIFETIMES[i])
    return signal

def fit_fluorescence_data(time_values, signal_data):
    """
    Thhis functionfits fluorescence signal data to determine molecular concentrations.

    Parameters:
        time_values (numpy.ndarray): Time values corresponding to the signal.
        signal_data (numpy.ndarray): Observed fluorescence signal.

    Returns:
        numpy.ndarray: Fitted amplitudes for each molecule.
    """
    if len(time_values) != len(signal_data):
        min_len = min(len(time_values), len(signal_data))
        time_values = time_values[:min_len]
        signal_data = signal_data[:min_len]

    initial_guess = [1.0] * len(MOLECULE_LIFETIMES)

    params, _ = curve_fit(
        total_fluorescence_signal,
        time_values, signal_data,
        p0=initial_guess,
        bounds=(0, np.inf),  
        maxfev=10000
    )
    return params

def analyze_datasets():
    """
    This function loads and fits fluorescence data.

    Returns:
        dict: Fitted parameters for each data.
    """
    time_array = np.linspace(0, 1000, 20000)

    data = {
        "Mixture A (Data1)": read_text_file('Data1.txt'),
        "Mixture B (Data2)": read_text_file('Data2.txt'),
        "Mixture C (Data3)": read_text_file('Data3.txt'),
        "Mixture D (Data4)": read_binary_file('Data4.dat'),
        "Measurement E (Data5)": read_text_file('Data5.txt'),
        "Measurement F (Data6)": read_text_file('Data6.txt')
    }

    results = {}
    for label, data in data.items():
        print(f"Fitting {label}...")
        results[label] = fit_fluorescence_data(time_array, data)

    return results

def display_results(results):
    """
    Display fitted results for all data.

    Parameters:
        results (dict): Fitted parameters for each data.
    """
    for data, params in results.items():
        print(f"\nResults for {data}:")
        for molecule, amplitude in zip(MOLECULE_NAMES, params):
            print(f"  {molecule}: Concentration = {amplitude:.3f}")


fitted_results = analyze_datasets()
display_results(fitted_results)