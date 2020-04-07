using System;

namespace Lab_1___Csh__
{
    class Matrix
    {
        public int row;
        public int colm;
        public int[,] matrix;
        public Matrix(int rows, int colms)
        {
            row = rows;
            colm = colms;
            matrix = new int[row, colm];
            for (int i = 0; i < row; i++)
            {
                for(int j = 0; j < colm; j++)
                {
                    matrix[i, j] = 0;
                }
            }
        }
        public int[,] Sum(Matrix m1, Matrix m2) // n1 == n2 | m1 == m2
        {
            int[,] mass = new int[m1.row, m1.colm];
            for (int i = 0; i < m1.row; i++)
            {
                for (int j = 0; j < m1.colm; j++)
                {
                    mass[i, j] = m1.matrix[i, j] + m2.matrix[i, j];
                }
            }
            return mass;
        }
        public int[,] Differ(Matrix m1, Matrix m2) // Same with Sum
        {
            int[,] masd = new int[m1.row, m1.colm];
            for (int i = 0; i < m1.row; i++)
            {
                for (int j = 0; j < m1.colm; j++)
                {
                    masd[i, j] = m1.matrix[i, j] - m2.matrix[i, j];
                }
            }
            return masd;
        }
        public int[,] Multipl(Matrix m1, Matrix m2)
        {
            int[,] masm = new int[m1.row, m2.colm];
            for (int i = 0; i < m1.row; i++)
            {
                for (int j = 0; j < m2.colm; j++)
                {
                    masm[i, j] = 0;
                    for (int k = 0; k < m1.colm; k++)
                    {
                        masm[i, j] += m1.matrix[i, k] * m2.matrix[k, j];
                    }
                }
            }
            return masm;
        }
        public int[,] Transp(Matrix m)
        {
            int[,] mastr = new int[m.colm, m.row];
            for (int i = 0; i < m.colm; i++)
            {
                for (int j = 0; j < m.row; j++)
                {
                    mastr[i, j] = m.matrix[j, i];
                }
            }
            return mastr;
        }
        public double Determinant(Matrix A)
        {
            double[,] copy = new double[A.row, A.colm];
            for (int i = 0; i < A.row; i++)
            {
                for (int j = 0; j < A.colm; j++)
                {
                    copy[i, j] = Convert.ToDouble(A.matrix[i, j]);
                }
            }
            for (int k = 1; k < A.row; k++)
            {
                for (int i = k; i < A.row; i++)
                {
                    double C = 1;
                    if (copy[k - 1, k - 1] != 0) { C = copy[i, k - 1] / copy[k - 1, k - 1]; }
                    for (int j = 0; j < A.row; j++)
                    {
                        copy[i, j] -= C * copy[k - 1, j];

                    }
                }
            }
            double det = 1;
            for (int i = 0; i < A.row; i++)
            {
                det *= copy[i, i];
            }
            return det;
        }
    }
}