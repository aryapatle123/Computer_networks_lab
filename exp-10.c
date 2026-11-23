
#include <stdio.h>

#define MAX_NODES 10
#define INF 999

struct node {
    int dist[MAX_NODES];
    int via[MAX_NODES];
} rt[MAX_NODES];

int main() {
    int cost[MAX_NODES][MAX_NODES];
    int nodes, i, j, k, count = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("\nEnter the Cost Matrix (%d x %d):\n", nodes, nodes);
    printf("(Enter 999 for infinity / no direct link)\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &cost[i][j]);
            cost[i][i] = 0;
            rt[i].dist[j] = cost[i][j];
            rt[i].via[j] = j;
        }
    }

    do {
        count = 0;
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                for (k = 0; k < nodes; k++) {
                    if (rt[i].dist[k] + rt[k].dist[j] < rt[i].dist[j]) {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].via[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);

    for (i = 0; i < nodes; i++) {
        printf("\n=================================");
        printf("\n   Routing Table for Node %d", i + 1);
        printf("\n=================================");
        printf("\n Destination | Next Hop | Distance ");
        printf("\n-------------|----------|----------");
        for (j = 0; j < nodes; j++) {
            printf("\n     %d       |    %d     |    %d", j + 1, rt[i].via[j] + 1, rt[i].dist[j]);
        }
        printf("\n");
    }

    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement and simulate the Distance Vector Routing (DVR) algorithm using
   the Bellman-Ford optimization equation in C to compute least-cost paths across
   all network nodes.

2. THEORY:
   - Distance Vector Routing: A dynamic, decentralized intra-domain routing
     algorithm employed in protocols such as RIP (Routing Information Protocol).
   - Core Principles:
     * Distributed: Each node receives routing vectors only from its directly
       connected immediate neighbors.
     * Iterative: Exchange and update process continues until no more routing
       updates occur (convergence).
     * Asynchronous: Nodes do not need to operate in lockstep.
   - Bellman-Ford Equation:
     $$D_x(y) = \min_v \{ c(x, v) + D_v(y) \}$$
     Where:
     * $D_x(y)$ = Shortest estimated distance from source node $x$ to destination $y$.
     * $c(x, v)$ = Direct link cost from node $x$ to adjacent neighbor $v$.
     * $D_v(y)$ = Neighbor $v$'s advertised distance to destination $y$.
     * Metric update: If $c(x,v) + D_v(y) < D_x(y)$, then update distance and set
       Next Hop = $v$.

3. EXPLANATION / ALGORITHM:
   - Step 1: Define structure node containing distance array dist[MAX] and next-hop
     array via[MAX].
   - Step 2: Prompt user for number of nodes in the network graph.
   - Step 3: Input cost adjacency matrix cost[i][j]. Use 999 to represent infinity
     (no direct link) and 0 for self-links (cost[i][i] = 0).
   - Step 4: Initialize routing tables: for each node $i$, set initial distance to
     direct cost ($rt[i].dist[j] = cost[i][j]$) and next hop ($rt[i].via[j] = j$).
   - Step 5: Execute relaxation loop (Bellman-Ford):
     * For every source node $i$, destination $j$, and intermediate neighbor $k$:
       - Check condition: if ($rt[i].dist[k] + rt[k].dist[j] < rt[i].dist[j]$)
       - If true: $rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j]$; $rt[i].via[j] = k$;
         increment update counter.
     * Repeat outer do-while loop until update counter remains 0 (system converged).
   - Step 6: Print converged routing tables displaying Destination, Next Hop,
     and Minimum Distance for each node.

4. CONCLUSION:
   Successfully implemented and verified the Distance Vector Routing algorithm in C.
   Demonstrated distributed route discovery using the Bellman-Ford equation and
   verified convergence of optimal least-cost routing tables for all network nodes.
================================================================================
*/
