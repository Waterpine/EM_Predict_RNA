import pickle
import numpy as np


def readmatrix(D):
    with open("TCC_21/matrix.ec", 'r', encoding='latin1') as file:
        f = open('type.txt', 'w')
        count = 1
        for line in file:
            new_array = line[:-1].split()
            type_array = new_array[1].split(',')
            if count in D:
                # f.write(new_array[0] + ' ')
                for i in range(len(type_array)):
                    if i != len(type_array) - 1:
                        f.write(type_array[i] + ' ')
                    else:
                        f.write(type_array[i])
                if count != D[len(D) - 1]:
                    f.write('\n')
            count = count + 1
            print(count)
        f.close()
        # print(count)
        # D = pickle.load(file, encoding='latin1')


def readnonzero():
    with open("mat_21/nonzero_ec.dat", 'rb') as file:
        D = pickle.load(file, encoding='latin1')
        # print(len(D))
        return D


if __name__ == '__main__':
    A = readnonzero()
    # print(A)
    readmatrix(A)


