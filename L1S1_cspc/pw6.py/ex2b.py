# import struct

# with open("mixture_d.bin", "rb") as file:  # Replace with actual path
#     binary_data = file.read()

# # Decode binary data
# fluorescence_data = np.array(struct.unpack(f'{len(binary_data)//2}H', binary_data))
# fluorescence_signal = fluorescence_data / 65535 * 10  # Apply scaling factor

# print("Decoded fluorescence data for mixture D:", fluorescence_signal)
