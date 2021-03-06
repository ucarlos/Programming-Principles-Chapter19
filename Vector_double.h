/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 02/23/2020
 * 
 * Vector_double.h
 * Implementation of vector as defined in Chapter 19 of Bjarne Stroustrup's
 * Principles and Practice Using C++ (2014)
 * This implementation of vector is at the end of Section 19.2, before the 
 * introduction of templates.
 * -----------------------------------------------------------------------------
 */

#ifndef VECTOR_DOUBLE_H
#define VECTOR_DOUBLE_H

#include <new>

class vector{
public:
    vector() : sz{0}, elem{nullptr}, space{0} { }
    explicit vector(int s) : sz{s}, elem{new double[s]}, space{s}{
		for (int i = 0; i < sz; i++) elem[i] = 0;
    }

    vector(const vector&); // Copy constructor
    vector& operator=(const vector&); // Copy assignment

    vector(vector&&); // move constructor
    vector& operator=(vector&&); // move assignment

    ~vector() { delete[] elem;} // destructor

    double& operator[](int n) { return elem[n]; }
    const double& operator[](int n) const { return elem[n]; }

    int size() const { return sz; }
    int capacity() const { return space; }

    void resize(int newsize);
    void push_back(double d);
    void reserve(int newalloc);
    

    
private:
    int sz;
    double *elem;
    int space;


};


#endif
