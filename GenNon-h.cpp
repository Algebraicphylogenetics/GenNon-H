/*
 *  GenNon-h.cpp
 *  
 *  Created by Ania M. Kedzierska on 11/11/11.
 *  Copyright 2011 Politecnic University of Catalonia, Center for Genomic Regulation.  This is program can be redistributed, modified or else as given by the terms of the GNU General Public License. 
 *  
 */

#include<iostream>
#include<cstdlib>
#include<fstream>


#include "sampling.h"
#include "miscelania.h"
#include "random.h"

void help(void) {
  std::cout << "Usage: GenNon-h <tree file> <output file> <length> <model>" << std::endl;
  std::cout << std::endl;
}


// Generates a simulated alignment with random parameters for a given
// model and a tree topology. The parameters used for simulations are saved into output file under the same base name as the fasta file 
//with a modified suffix ".dat"

int main(int argc, char* argv[]) {

  Tree T;
  Model Mod;
  Parameters Par;
  Alignment align;
  std::vector<double> br;
  std::string tree_filename; // Filenames.
  std::string fasta_filename;
  std::string parameters_filename;
  std::string model_name;
  long length;

  // initialize random number generator with time(0).
  random_initialize();
  // random_initialize(23);

  // Check for command line arguments
  if (argc == 1) {
    std::cout << "No input arguments." << std::endl;
    help();
    exit(1);
  } else if (argc >= 6) {
    std::cout << "Too many arguments." << std::endl;
    help();
    exit(1);
  }

  // Catch the command line arguments
  tree_filename.assign(argv[1]);
  fasta_filename.assign(argv[2]);
  parameters_filename = make_parameters_filename(fasta_filename);

  length = atoi(argv[3]);
  model_name.assign(argv[4]);

  // Creates the pointers to the model-specific functions.
  Mod = create_model(model_name);
 
  // Reads the tree.
  read_tree(T, tree_filename);

  // Initialize the parameters for simulation of K81 data for testing
  create_parameters(Par, T);

  // Generate random parameters
  random_parameters_length(T, Mod, Par);

  // Computes the branch lengths
  branch_lengths(Par, br);
 
  // Produces an alignment
  random_data(T, Mod, Par, length, align);
  
  // Prints some useful info
  std::cout << "Model: " << Mod.name << std::endl;
  std::cout << "Tree:" << std::endl;
  print_tree(T);                    
  //std::cout << "Branch lengths:" << std::endl;
  //print_vector(br);

  // Prints the fasta file into a file.
  save_alignment(align, fasta_filename);

  // Saves the parameters used for generating the data
  save_parameters(Par, parameters_filename);
}
