# Overview
**GenNon-H** is an efficient tool to generate DNA MSAs on a given phylogenetic tree.

A number of software packages are available to generate DNA multiple sequence alignments (MSAs) evolving under continuous-time Markov processes on phylogenetic trees. On the other hand, methods of simulating the DNA MSA directly from the transition matrices do not exist. Moreover, existing software restricts to the time-reversible models and it is not optimized to generate non-homogeneous data (i.e. placing distinct substitution rates at different lineages).
**GenNon-H** generates MSAs evolving under discrete-time Markov processes on phylogenetic trees, directly from probability substitution matrices. Based on the input model and a phylogenetic tree in the Newick format (with branch lengths measured as the expected number of substitutions per site), the algorithm produces DNA alignments of desired length. **GenNon-h** provides the user with the nonstationary or non-homogeneous phylogenetic data that is wellsuited for testing complex biological hypotheses, exploring the limits of the reconstruction algorithms and theirrobustness to such models.

### Dependencies

The package used version 1.47.0 of the [boost] library for parts of the code involving maths and random generation (downloaded from: [boost source]). As such, use, modification and distribution are subject to the Boost Software License, Version 1.0. (See [boost license]).

### Compilation and command line use
To compile this code you need a development environment with the GNU gcc compiler ('make').
The following command simulates fasta alignments of a given <length> with random parameters for a given model (jc, k80, k81, ssm, gmm) and tree topology:
```
GenNon-h <tree file> <output file> <length> <model>.
```
Branch lengths should be included in the [Newick] format within the <tree file>. The parameters used for the simulations are saved in a file with the same name as the fasta  and suffix ".dat”.
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
The nodes are labeled in the following order:  first the leaves (edges leading to the cherries), then  the top-down search starting from the node labeled as the root (the node of highest depth), proceeding left to right as  indicated in the Newick format.

##### Output files
Fasta MSA (.fa) and parameters used for the simulations (.dat): Line 1:  # of leaves,  # of edges,  Line 2: equilibrium frequencies of a node chosen as the root

Output matrices are listed acc. to the order outlined above:
1. matrices are first assigned to the leaf edges (bottom branches)
2. top-down left to right branch order.

[boost]:	     http://www.boost.org/
[boost source]: http://sourceforge.net/projects/boost/files/boost/1.47.0/
[boost license]: http://www.boost.org/LICENSE_1_0.txt
[Newick]: http://evolution.genetics.washington.edu/phylip/newicktree.html

### Publications
> Kedzierska A.M. and Casanellas M.: “ GenNon-h: Simulating multiple sequence alignments under the non-homogeneous dna models. " (BMC Bioinformatics 2012, 13:216)

For methods of parameter estimation of non-homogeneous alignments:
> Kedzierska A.M. and Casanellas M.: “ EM for parameter estimation of Markov models on trees. ” (revision).

<sub> *This is a free software and it can be redistributed, modified or else as given by the terms of the GNU General Public License.* </sub>
