/*
  main_links.c
  $LastChangedDate: 2008-03-25 18:02:36 -0500 (Tue, 25 Mar 2008) $
  $Revision: 124 $
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <gsl/gsl_rng.h>

#include "tools.h"
#include "graph.h"
#include "missing.h"

int
main(int argc, char **argv)
{
  char *netF;
  FILE *infile=NULL;
  FILE *outfile1=NULL, *outfile2=NULL;
  struct node_gra *net=NULL;
  gsl_rng *rand_gen;
  double **scores;
  struct node_gra *p1, *p2;
  long int seed;
  int K, k;
  struct query **queries=NULL;
  int nquery=0, q;
  int niter;

  /*
    ---------------------------------------------------------------------------
    Command line parameters
    ---------------------------------------------------------------------------
  */
  if (argc < 3) {
    printf("\nUse: drugraph K net_file niterations seed\n\n");
    return;
  }
  K = atoi(argv[1]);
  netF = argv[2];
  niter = atoi(argv[3]);
  seed = atoi(argv[4]);
  rand_gen = gsl_rng_alloc(gsl_rng_mt19937);
  gsl_rng_set(rand_gen, seed);

  /*
    ---------------------------------------------------------------------------
    Build the network
    ---------------------------------------------------------------------------
  */
  infile = fopen(netF, "r");
  net = FBuildNetwork(infile, 1, 0, 0, 1);
  fclose(infile);

  /*
    ---------------------------------------------------------------------------
    Get link reliabilities
    ---------------------------------------------------------------------------
  */
  scores = LSMultiLinkScoreKState(K, net, niter, rand_gen, 'v', -1,
				  &queries, &nquery);
  
  /*
    ---------------------------------------------------------------------------
    Output
    ---------------------------------------------------------------------------
  */
  outfile1 = fopen("predictions.dat", "w");
  for (q=0; q<nquery; q++) {
    if (IsThereLink(queries[q]->n1, queries[q]->n2) == 0) {
      fprintf(outfile1, "%s %s",
	      ((queries[q])->n1)->label,
	      ((queries[q])->n2)->label);
      for (k=0; k<K; k++)
	fprintf(outfile1, " %lf", scores[k][q]);
      fprintf(outfile1, "\n");
    }
  }
  fclose(outfile1);

  /*
    ---------------------------------------------------------------------------
    Finish
    ---------------------------------------------------------------------------
  */
  RemoveGraph(net);
  gsl_rng_free(rand_gen);
  return 0;
}
