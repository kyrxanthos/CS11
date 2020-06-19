/*!
 * File creator & Assignment info:
 * CS11 C++
 * Assignment 6
 * Kyriacos Xanthos
 * kxanthos@caltech.edu
 */ 


/*!
 * \file Creates a 1-row matrix by adding the column elements of
 * each row to the right of the initial 1st row. Implements all
 * functions from header file.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "matrix.h"
   using namespace std;

/*!
 * This is the default constructor.
 * All matrix elements are set to 0.
 * \param rows are the rows of the matrix
 * \param cols are the columns of the matrix
 * \param arr is the array we will use to manipulate all
 * elements of matrix
 */
Matrix::Matrix() {
    rows = 0;
    cols = 0;
    arr = NULL;
    
}

/*!
 * Throws invalid argument if negative values are input
 * Creates the array to be used.
 */
Matrix::Matrix(int rows, int cols) {
    if ((rows < 0) || (cols < 0)) {
        string ex1 = "Values of rows and columns should be positive";
        throw invalid_argument(ex1);
    } else {
        this->rows = rows;
        
        this->cols = cols;
    }
/*!
 * Initialize an array of dimension rows * columns
 * with every element of type int.
 */
    if ((rows >= 1) && (cols >= 1))
    {
        arr = new int [(rows*cols)]; 
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++) 
            {
                arr[(i * cols) + j] = 0;
            }
        }
    }
    
}

/*!
 * Copy-Constractor
 * performs a deep copy because the object
 * being initialized needs its own memory region
 * \param cp used to create copies
 */
Matrix::Matrix(const Matrix &cp) {
    rows = cp.rows;
    cols = cp.cols;
    arr = new int [(rows * cols)];
    
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
         {
            arr[(i * cols) + j] = cp.arr[(i * cols) + j];
        }
    }
}


/*!
 * write our own version of the copy-assignment operator
 * release the dynamically-allocated resources, then allocate new
 * resources to receive the values from the RHS.
 */
Matrix & Matrix::operator=(const Matrix &cp) {
    if (this == &cp) {
        return *this;
    }

    /*!
     * Release old memory
     */
    delete [] arr;

    rows = cp.rows;
    cols = cp.cols;

    /*!
     * Allocate new memory
     */
    arr = new int [(rows*cols)];

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
         {
            arr[(i * cols) + j] = cp.arr[(i * cols) + j];
        }
    }
    return *this;
}


/*!
 * Destrcutor operator
 */
Matrix::~Matrix() {
    /*!
     * Release old memory
     */
    delete [] arr;
}

int Matrix::numRows() const {
    return rows;
}

int Matrix::numCols() const {
    return cols;
}
/*!
 * \returns the value stored at the specified row and column
 * Throws invalid arg if row or column index is out of bounds
 */
int Matrix::get(const int r, const int c) const {

    if ((rows <= r) || (cols <= c) || (r < 0) || (c < 0)) 
    {
        string ex2 = "row or column index is out of bounds";
        throw invalid_argument(ex2);
    }
    return arr[(r * cols) +  c]; 
}

/*!
 * Sets the value stored at the specified row and column
 * Throws invalid arg if row or column index is out of bounds
 */

void Matrix::set(int r, int c, int value) {
    if ((rows < r) || (cols < c)) {
        string ex3 = "row or column index is out of bounds";
        throw invalid_argument(ex3);

    } else 
    { 
        arr[(r * cols) + c] = value;
    }
}
/*!
 * Compares whether two matrix objects have the same values or not
 * Returns boolian true/false accordingly
 */ 
bool Matrix::operator==(const Matrix &m) {
    if ((rows != m.numRows()) || (cols != m.numCols())) {
        return false;
    }

    for (int i = 0; i < rows; i++)
     {
        for (int j = 0; j < cols; j++) 
        {
            if (arr[(i * cols) + j] != m.arr[(i * cols) + j]) {
                return false;
            }
        }
    }
    return true;
}

/*!
 * performs the exact opposite of the above function
 */

bool Matrix::operator!=(const Matrix &m) {
    return !(*this == m); 
}


