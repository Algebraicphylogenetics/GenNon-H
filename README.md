# Overview
GenNon-H is a package for generating discrete-time phylogenomic data.
It simulates Multiple Seq. Alignments (MSA) under discrete-time models for a pre-specified phylogenetic tree with assigned branch lengths.

### Dependencies

The package used version 1.47.0 of the [boost] library for parts of the code involving maths and random generation (downloaded from: [boost source]). As such, use, modification and distribution are subject to the Boost Software License, Version 1.0. (See [LICENSE]).

### Compilation and command line use
To compile this code you need a development environment with the GNU gcc compiler ( 'make').
Command:
```
GenNon-h <tree file> <output file> <length> <model>
```
simulates fasta alignments of a given <length> with random parameters for a given model (jc, k80, k81, ssm, gmm) and tree topology. Branch lengths should be included in the [Newick] format within the <tree file>. The parameters used for the simulations are saved in a file with the same name as the fasta  and suffix ".dat"
```
./GenNon-h test.nw data.fa 50000 jc
```
#### Output:
```
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
```
The nodes are labeled in the following order:  first the leaves (edges leading to the cherries), then  the top-down search starting from the node labeled as the root (the node of highest depth), proceeding left to right as  indicated in the newick format.

##### Output files:
Fasta MSA (.fa) and parameters used for the simulations (.dat): Line 1:  # of leaves,  # of edges,  Line 2: equilibrium frequencies of a node chosen as the root

Output matrices are listed acc. to the order outlined above:
1. matrices are first assigned to the leaf edges (bottom branches)
2. top-down left to right branch order.

	[boost]:	     http://www.boost.org/
	[boost source]: http://sourceforge.net/projects/boost/files/boost/1.47.0/
	[LICENSE]:http://www.boost.org/LICENSE_1_0.txt
	[Newick]: http://evolution.genetics.washington.edu/phylip/newicktree.html

<sub> *This is a free software and it can be redistributed, modified or else as given by the terms of the GNU General Public License.* </sub>
