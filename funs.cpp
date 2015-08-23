/*
 *  funs.cpp
 *  
 *  Created by Ania M. Kedzierska on 11/11/11.
 *  Copyright 2011 Politecnic University of Catalonia, Center for Genomic Regulation.  This is program can be redistributed, modified or else as given by the terms of the GNU General Public License. 
 *  
 */


#include <cstdlib>
#include <iostream>
#include <cmath>

#include "funs.h"
#include "matrix.h"
#include "miscelania.h"

// This computes the joint probability for a choice of states on the hidden nodes (idhid) and
// on the leaves (idleaf).
double joint_prob(Tree &T, Parameters &Par, long idleaf, long idhid) {
	double p;
	long i;
	long a,b;
	
	// Computes the states and stores them in the auxiliar members of the tree T
	index2state(idhid, T.shidden);
	index2state(idleaf, T.sleaves);
	
	// root distribution. The root is the first hidden node 
	p = Par.r[T.shidden.s[0]];
	
	// product of transition matrices
	for(i=0; i < T.nedges; i++) {
		a = T.shidden.s[T.edges[i].s - T.nleaves];      // state on the source node
		if (T.edges[i].t < T.nleaves){                  // if the edge connects to a leaf
			b = T.sleaves.s[T.edges[i].t];                // state on the target leaf
		} else {
			b = T.shidden.s[T.edges[i].t - T.nleaves];    // state on the target node
		}
		p = p*Par.tm[i][a][b];
	}
	return p;
}

// Computes the joint probability on the leaves only, marginalizing for the hidden nodes.
double joint_prob_leaves(Tree &T, Parameters &Par, long idleaf) {
  long i;
  double p;
  p = 0;
  for(i=0; i < T.nsthidden; i++) {
    p = p + joint_prob(T, Par, idleaf, i);
  }
  return p;
}

// Faster joint probability with precomputed list of states
double joint_prob_fast(Tree &T, Parameters &Par, StateList &sl, long idleaf, long idhid) {
  double p;
  long i;
  int a,b;

  // root distribution. The root is the first hidden node !
  p = Par.r[sl.h[idhid][0]];

  // product of transition matrices
  for(i=0; i < T.nedges; i++) {
    a = sl.h[idhid][T.edges[i].s - T.nleaves];      // state on the source node
    if (T.edges[i].t < T.nleaves){                  // if the edge connects to a leaf
      b = sl.l[idleaf][T.edges[i].t];               // state on the target leaf
    } else {
      b = sl.h[idhid][T.edges[i].t - T.nleaves];    // state on the target node
    }
    p = p*Par.tm[i][a][b];
  }
  return p;
}


// Fast marginalization of the joint probability to the leaves, using a precomputed
// list of states
double joint_prob_leaves_fast(Tree &T, Parameters &Par, StateList &sl, long idleaf) {
  long i;
  double p;
  p = 0;
  for(i=0; i < T.nsthidden; i++) {
    p = p + joint_prob_fast(T, Par, sl, idleaf, i);
  }
  return p;
}


// Sets a fixed initial parameters of JC type.
void initial_parameters(Model &Mod, Parameters &Par) {
  long i,j,k;
  for (k=0; k < Par.nedges; k++) {
    for(i=0; i < Par.nalpha; i++) {
      for(j=0; j < Par.nalpha; j++) {
        if (i==j) Par.tm[k][i][j] = 0.7;
        else Par.tm[k][i][j] = 0.3 / (double)(Par.nalpha-1);
      }
    }
  }
  for (i=0; i < Par.nalpha; i++) {
    Par.r[i] = 1/(double)Par.nalpha;
  }
}
