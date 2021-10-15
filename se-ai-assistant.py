import numpy as np
import csv

def main():
    build_input = "build.csv"
    build_cost = np.zeros((1,5))
    build_prod = np.zeros((1,6))
    with open(build_input, newline='') as csvfile:
        table = csv.reader(csvfile, delimiter=',', quotechar='|')
        for row in table:
            if row[0] == "Mina de Metal":
                print(row)
                


if __name__ == "__main__":
    main()
