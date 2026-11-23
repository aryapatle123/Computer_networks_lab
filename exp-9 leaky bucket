
#include <stdio.h>

int main() {
    int bucket_size, n, i, incoming, outgoing, stored = 0;

    printf("Leaky Bucket Algorithm Simulation\n");
    printf("Enter bucket size (capacity): ");
    scanf("%d", &bucket_size);
    printf("Enter outgoing rate: ");
    scanf("%d", &outgoing);
    printf("Enter number of time units: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nTime unit %d:\n", i + 1);
        printf("Enter number of incoming packets: ");
        scanf("%d", &incoming);

        if (incoming + stored > bucket_size) {
            printf("Bucket overflow! Packet loss = %d\n", incoming + stored - bucket_size);
            stored = bucket_size;
        } else {
            stored += incoming;
        }

        if (stored <= outgoing) {
            printf("Packets sent: %d\n", stored);
            stored = 0;
        } else {
            printf("Packets sent: %d\n", outgoing);
            stored -= outgoing;
        }
        printf("Packets remaining in bucket: %d\n", stored);
    }

    while (stored > 0) {
        printf("\nDraining remaining packets...\n");
        if (stored <= outgoing) {
            printf("Packets sent: %d\n", stored);
            stored = 0;
        } else {
            printf("Packets sent: %d\n", outgoing);
            stored -= outgoing;
        }
        printf("Packets left in bucket: %d\n", stored);
    }

    printf("\nSimulation complete.\n");
    return 0;
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To implement and simulate the Leaky Bucket Traffic Shaping Algorithm in C to
   regulate bursty network traffic into a uniform, constant transmission rate.

2. THEORY:
   - Traffic Shaping: A network congestion management mechanism at the Network /
     Transport layer that regulates the rate and volume of data injected into the
     network to prevent buffer overflow and router congestion.
   - Leaky Bucket Algorithm Concept:
     * Analogy: An open-top bucket with a small hole at the bottom.
     * Regardless of the burstiness and irregular arrival rate of incoming water
       (packets), water leaks out from the hole at a strictly constant rate.
     * Bucket Capacity ($C$): Finite buffer size that can hold accumulated packets.
     * If the bucket fills completely and incoming packets exceed remaining capacity,
       the excess packets overflow and are discarded (packet loss).
     * Outgoing Rate ($R$): Constant drain rate per discrete time unit.
   - Mathematical Formulation per Time Unit:
     * Free Space: $Space = Capacity - Stored$
     * If $Incoming \le Space$: $Stored = Stored + Incoming$
     * If $Incoming > Space$: $Dropped = Incoming - Space$; $Stored = Capacity$
     * Transmitted = $\min(Stored, R)$
     * Remaining = $Stored - Transmitted$

3. EXPLANATION / ALGORITHM:
   - Step 1: Input bucket capacity, constant outgoing drain rate, and simulation time units.
   - Step 2: Initialize stored = 0.
   - Step 3: For each time unit $i = 1$ to $n$:
     * Input incoming packet count for current time unit.
     * Check if (stored + incoming) exceeds bucket capacity:
       - If yes: calculate dropped packets = (stored + incoming) - bucket_size; set stored = bucket_size.
       - If no: add incoming to stored.
     * Drain packets: if stored <= outgoing rate, transmit all stored packets (stored = 0);
       otherwise transmit outgoing rate packets and decrement stored by outgoing rate.
     * Print transmitted, dropped, and remaining packets in bucket.
   - Step 4: After simulation units end, drain remaining buffered packets tick-by-tick
     at outgoing rate until stored becomes 0.

4. CONCLUSION:
   Successfully implemented and verified the Leaky Bucket traffic shaping algorithm
   in C. Demonstrated how bursty incoming packet flows are converted into a steady,
   constant outgoing transmission rate, and observed packet dropping when buffer
   capacity is exceeded.
================================================================================
*/
