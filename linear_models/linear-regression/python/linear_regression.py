#!/usr/bin/env python
# coding: utf-8

# # Linear Regression
# 
# Linear Regression is a linear model. In this case we are using OLS(Ordinary Least Squares)
# 
# ### Author
# - Frank Palma (**@knarfamlap**)

# In[26]:


import numpy as np


# In[27]:


class LinearRegression(object):
    
    def __init__(self):
        self.coefficients = []
    
    def _reshape_x(self, X):
        # if X only has 1 feature, 
        # turn it into a column vector
        return X.reshape(-1, 1)
    
    def _concatenate_ones(self, X):
        # create column vector of ones
        # has the same number of rows as X
        ones = np.ones(shape=X.shape[0]).reshape(-1, 1)
        # append it to the right side of X
        return np.concatenate((ones, X), 1)
    
    def predict(self, entry):
        # get the intercept
        b0 = self.coefficients[0]
        # get x1..xn
        other_betas = self.coefficients[1:]
        # prediction
        prediction = b0
        # calculate prediction
        for xi, bi in zip(entry, other_betas): prediction += (bi * xi)
        return prediction
    
    def fit(self, X, y):
        if (len(X.shape) == 1):
            X = self._reshape_x(X)
        
        X = self._concatenate_ones(X)
        self.coefficients = np.linalg.inv(X.transpose().dot(X)).dot(X.transpose()).dot(y)

