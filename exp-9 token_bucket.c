
#include <stdio.h>

int main() {
    int bucket_size, n, rate, tokens = 0, incoming, i;

    printf("Token Bucket Algorithm Simulation\n");
    printf("Enter bucket size (capacity): ");
    scanf("%d", &bucket_size);
    printf("Enter token generation rate: ");
    scanf("%d", &rate);
    printf("Enter number of time units: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nTime unit %d:\n", i + 1);
        tokens += rate;
        if (tokens > bucket_size) tokens = bucket_size;

        printf("Enter number of packets to send: ");
        scanf("%d", &incoming);

        if (tokens >= incoming) {
            printf("Packets sent: %d\n", incoming);
            tokens -= incoming;
        } else {
            printf("Only %d tokens available, packets sent: %d, packets dropped: %d\n",
                    tokens, tokens, incoming - tokens);
            tokens = 0;
        }
        printf("Tokens left: %d\n", tokens);
    }

    printf("\nSimulation complete.\n");
    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement and simulate the Token Bucket Traffic Shaping Algorithm in C to
   allow regulated bursty transmissions while maintaining a bounded average rate.

2. THEORY:
   - Token Bucket vs. Leaky Bucket:
     * Leaky bucket enforces a rigid, constant output rate regardless of network
       idle time.
     * Token bucket stores transmission credits (tokens). It allows bursty packet
       transmissions up to the maximum capacity of accumulated tokens, while
       limiting the long-term average transmission rate to the token generation rate.
   - Token Bucket Mechanism:
     * Tokens are generated at a constant rate $r$ tokens/second and deposited into
       a bucket of maximum capacity $b$.
     * If the bucket is full of tokens ($tokens = b$), newly generated tokens are discarded.
     * To transmit $k$ packets, $k$ tokens must be removed from the bucket.
     * If sufficient tokens exist ($tokens \ge incoming$), all packets are transmitted
       immediately at line speed (burst).
     * If fewer tokens are available ($tokens < incoming$), packets equal to available
       tokens are sent, and remaining packets are dropped or queued.

3. EXPLANATION / ALGORITHM:
   - Step 1: Input token bucket capacity, token generation rate ($r$), and time units ($n$).
   - Step 2: Initialize tokens = 0.
   - Step 3: Loop for each time unit $i = 1$ to $n$:
     * Add newly generated tokens: tokens = min(bucket_size, tokens + rate).
     * Input number of incoming packets to send.
     * Check token sufficiency:
       - If tokens >= incoming: transmit all incoming packets; deduct tokens (tokens -= incoming).
       - If tokens < incoming: transmit tokens count of packets; drop/delay excess
         (incoming - tokens); reset tokens = 0.
     * Display packets transmitted, dropped, and remaining tokens in the bucket.
   - Step 4: Display simulation completion status.

4. CONCLUSION:
   Successfully simulated the Token Bucket algorithm in C. Demonstrated how token
   accumulation enables short-term traffic bursts without data loss while
   constraining the long-term average transmission rate to the token generation rate.
================================================================================
*/
