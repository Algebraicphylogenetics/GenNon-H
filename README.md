
This is a readme for GenNon-h package for generating discrete-time data

----------------------------------------------------
This is a free software and it can be redistributed, modified or else as given by the terms of the GNU General Public License.


Dependencies
----------------------------------------------------

We use version 1.47.0 of the boost library (http://www.boost.org/) for some code involving maths and random generation (downloaded from http://sourceforge.net/projects/boost/files/boost/1.47.0/).
// Use, modification and distribution are subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt).


Overview
----------------------------------------------------

GenNon-h:        simulates a Multiple Seq. Alignment (MSA) on a given tree with assigned branches under the discrete-time models

To compile this code you need a development environment with the GNU gcc compiler. 
GenNon-h is compiled with the command 'make'.

Source Code
----------------------------------------------------

include             A piece of the boost library.
alignment.cpp       Managing alignments and vectors of counts.
em.cpp              The EM algorithm, KL-divergence, likelihoods ...
GenNon-h.cpp        The  main function.
matrix.cpp          Matrix creation and destruction.
miscelania.cpp, funs.cpp      Utility functions
model.cpp           Keeps the model dependent functions in a single place.
model_gmm.cpp       The GMM functions.
model_jc.cpp        The JC69 functions.
model_k80.cpp       The K80 functions.
model_k81.cpp       The K81 functions.
model_ssm.cpp       The Strand-Symmetric functions.
Newickform.cpp      Used for reading the tree  (adopted from the code of Yu-Wei Wu).
parameters.cpp      Data structure for the parameters
random.cpp          The random generation functions, for use parameter sampling and alignment
                    simulation.
permutation.cpp     To create the DLC matrices
read_fasta.cpp      Reading the fasta files.
sampling.cpp        Functions used for randomly sampling parameters.
seqUtil.cpp         Used for reading the tree (adopted from the code of Yu-Wei Wu).
state.cpp           Data structure for the states.
state_list.cpp      Data structure for a list of all states in a tree (on the leaves and the hidden)
tree.cpp            Data structure for trees (as a list of edges).


GenNon-h
----------------------------------------------------

Command:
GenNon-h <tree file> <output file> <length> <model>

Simulates fasta alignments with random parameters for a given model and tree topology.
The lengths in <tree file> are used . The parameters used for
the simulations are saved in a file with the same name as the fasta  and suffix ".dat"

  <tree file>   tree in a Newick format 
  <fasta file>  Output file for the simulated alignment. WARNING ! overwrites the existing files
  <length>      Length of the alignment
  <model>       The model: jc, k80, k81, ssm, gmm


Sample commands:

./GenNon-h test2.tree data.fa 10000 k81
./GenNon-h star.tree data.fa 5000 jc

./GenNon-h test2.tree data.fa 10000 k81

Tree format example:
test2.tree:   ((human:0.01,ape:0.2,hamster:0.3):0.5,bird:0.4,amoeba:0.7)


Output to the screen:

Model: Kimura 81
Tree:
nodes:   7
nleaves: 5
nedges:  6
Edges:
  (5, 6)  0.5
  (5, 3)  0.4
  (5, 4)  0.7
  (6, 0)  0.01
  (6, 1)  0.2
  (6, 2)  0.3

Labels of the leaves: human ape hamster bird amoeba  (node labels starting from 0)
The nodes are labeled in the following order:  first the leaves, proceeded by the top-down search starting from the node labeled as the root 
(the node of highest depth).  Left to right order of the nodes is indicated in the newick format.

Output files:
    Fasta MSA
    name-of_the_fasta_file.fa

    Parameters used for the simulations
    name-of_the_fasta_file.dat

.dat file details: 
Line 1:  # of leaves,  # of edges
Line 2: equilibrium frequencies of a node chosen as the root

Note: The order in which the output matrices are listed is in accordance with the order outlined above (the matrices assigned to the leaf edges followed by the top-down listing).

UPDATES:
25/05/2013 model_gmm.cpp - GMM_random_root
                      the root distribution was modified to have entries in [0.20, 0.30] approx.
		     
