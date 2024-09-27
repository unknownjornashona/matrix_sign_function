import numpy as np
import pandas as pd
import logging
import sys

# Set up logging
logging.basicConfig(filename='matrix_sign.log', level=logging.INFO,
                    format='%(asctime)s - %(levelname)s - %(message)s')

class MatrixSignFunction:
    def __init__(self, matrix):
        """Initialize with a square matrix."""
        if not self.is_square_matrix(matrix):
            raise ValueError("Input must be a square matrix.")
        self.matrix = matrix

    def is_square_matrix(self, matrix):
        """Check if the given matrix is square."""
        return matrix.shape[0] == matrix.shape[1]

    def calculate_sign(self):
        """Calculates the sign function of the matrix."""
        try:
            eig_values, eig_vectors = np.linalg.eig(self.matrix)
            sign_eig_values = np.sign(eig_values)
            sign_matrix = np.diag(sign_eig_values)
            return eig_vectors @ sign_matrix @ np.linalg.inv(eig_vectors)
        except Exception as e:
            logging.error(f"Error during sign calculation: {e}")
            raise

    def save_to_csv(self, sign_matrix, filename='sign_matrix.csv'):
        """Save the sign matrix to a CSV file."""
        df = pd.DataFrame(sign_matrix)
        df.to_csv(filename, index=False)
        logging.info(f"Sign matrix saved to {filename}")

def parse_input(args):
    """Parse the input arguments into a square matrix."""
    try:
        matrix = []
        for arg in args:
            row = list(map(float, arg.split(',')))
            matrix.append(row)
        return np.array(matrix)
    except Exception as e:
        logging.error(f"Error parsing input: {e}")
        raise ValueError("Invalid input format. Please provide a square matrix as comma-separated values.")

def main():
    # Check for the right number of arguments
    if len(sys.argv) < 2:
        print("Usage: python matrix_sign_function.py <row1> <row2> ... <rowN>")
        print("Example: python matrix_sign_function.py '1,2' '3,4'")
        sys.exit(1)

    try:
        # Parse the command line arguments into a matrix
        input_matrix = parse_input(sys.argv[1:])
        
        msf = MatrixSignFunction(input_matrix)
        
        # Calculate the sign function
        sign_matrix = msf.calculate_sign()

        print("Original Matrix:")
        print(input_matrix)
        print("\nSign Function Matrix:")
        print(sign_matrix)

        # Save the sign matrix to a CSV file
        msf.save_to_csv(sign_matrix)
    
    except ValueError as ve:
        logging.error(f"ValueError: {ve}")
        print(ve)
    except Exception as e:
        logging.error(f"An error occurred: {e}")
        print("An error occurred. Please check the log for details.")

if __name__ == "__main__":
    main()
