#!/usr/bin/env python
# coding: utf-8


class LinearModel(object):
    
    def __init__(self, step_size=0.2, max_iter=100, eps=1e-5, theta_0=None, verbose=True):
        """
        Args:
            step_size: step size for iterative solvers only
            max_iter: maximum number of iterations for the solver
            eps: threshold for termining convergence 
            theta_0: init guess for theta. Use zero vector if None
            verbose: Print loss values during training
        """
        self.theta = theta_0 
        self.step_size = step_size
        self.max_iter = max_iter
        self.eps = eps
        self.verbose = verbose
        
    def fit(self, x, y):
        """
        Run solver to fit linear model. 
        
        Args:
            x: Training examples. Shape (m, n)
            y: Training examples labels. Shape (m)
        """
        raise NotImplementedError("Subclass of LinearModel must implement fit method.")
        
    def predict(self, x):
        """
        Make prediction given new inputs x
        
        Args: 
            x: inputs of shape (m, n)
            
        Returns: 
            outputs of shape (m)
        """
        
        raise NotImplementedError("Subclass of LinearModel must implement predict method.")

