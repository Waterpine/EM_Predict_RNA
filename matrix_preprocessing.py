import pickle

path = 'mat_21/'

def readnonzero():
    with open(path + "TCC_matrix.dat", 'rb') as f:
        D = pickle.load(f, encoding='latin1')
        # print(len(D))
        return D


if __name__ == '__main__':
    D = readnonzero()
    print(D.toarray().T.shape)
    A = D.toarray().T
    file = open("matrix.txt", 'w')
    for i in range(len(A)):
        for j in range(len(A[i])):
            if j != len(A[i]) - 1:
                file.write(str(A[i][j]) + ' ')
            else:
                file.write(str(A[i][j]) + '')
        if i != len(A) - 1:
            file.write('\n')
        print(i)
    file.close()


# import numpy as np
# from scipy.sparse import csr_matrix
# file = open('try.txt', 'w')
# arr = np.array([[0, 1, 0, 2, 0], [1, 1, 0, 2, 0], [2, 0, 5, 0, 0]])
# b = csr_matrix(arr)
# print(type(b))
# a = b.toarray()
# for i in range(len(a)):
#     for j in range(len(a[i])):
#         if j != len(a[i]) - 1:
#             file.write(str(a[i][j]) + ' ')
#         else:
#             file.write(str(a[i][j]) + '')
#     if i != len(a) - 1:
#         file.write('\n')
# file.close()
