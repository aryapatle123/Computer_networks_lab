

#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 50

void sender(int frames[], int size, int window_size);
void receiver(int frames[], int start, int window_size, int size);

int main() {
    int n, window_size;
    int frames[MAX_FRAMES];

    printf("Sliding Window Protocol Simulation (Go-Back-N)\n");
    printf("Enter number of frames to send (max %d): ", MAX_FRAMES);
    if (scanf("%d", &n) != 1 || n > MAX_FRAMES || n <= 0) {
        printf("Invalid number of frames.\n");
        return 0;
    }

    printf("Enter window size: ");
    if (scanf("%d", &window_size) != 1 || window_size <= 0 || window_size > n) {
        printf("Invalid window size.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        frames[i] = i;
    }

    sender(frames, n, window_size);

    return 0;
}

void sender(int frames[], int size, int window_size) {
    int base = 0;
    char choice;

    while (base < size) {
        printf("\nSender window: ");
        for (int i = base; i < base + window_size && i < size; i++) {
            printf("[%d] ", frames[i]);
        }
        printf("\nSending frames...\n");
        for (int i = base; i < base + window_size && i < size; i++) {
            printf("Sent frame: %d\n", frames[i]);
        }

        printf("\nSimulating receiver...\n");
        receiver(frames, base, window_size, size);

        printf("\nDid all frames receive correctly? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            base += window_size;
        } else {
            printf("Resending from frame %d...\n", frames[base]);
        }
    }

    printf("\nAll frames sent successfully!\n");
}

void receiver(int frames[], int start, int window_size, int size) {
    for (int i = start; i < start + window_size && i < size; i++) {
        printf("Received frame: %d, sending ACK: %d\n", frames[i], frames[i] + 1);
    }
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================

1. AIM:
   To simulate the Go-Back-N (GBN) Sliding Window Protocol for flow control and
   error recovery in C, demonstrating pipelined transmission and window sliding.

2. THEORY:
   - Sliding Window Concept: A flow control and error control technique used at
     the Data Link Layer and Transport Layer. It allows the sender to transmit
     multiple consecutive frames before receiving an acknowledgment, maximizing
     channel bandwidth utilization (pipelining).
   - Go-Back-N (GBN) Mechanics:
     * Sender Window Size ($N$): Up to $2^m - 1$ frames (where $m$ is sequence
       number bit width).
     * Receiver Window Size: Always strictly 1. The receiver only accepts frames
       in strict sequential order. Any out-of-order frame is discarded.
     * Cumulative Acknowledgment: ACK $k$ confirms that all frames up to $k-1$
       have been received successfully.
     * Error Recovery ("Go Back $N$"): If frame $k$ is lost or corrupted, the
       receiver rejects frame $k$ and all subsequent frames ($k+1, k+2, \dots$).
       When the sender timer for frame $k$ expires, the sender must retransmit
       all frames in the current window starting from frame $k$.

3. EXPLANATION / ALGORITHM:
   - Step 1: Prompt user for total number of frames to transmit ($n \le 50$) and
     sender window size ($window\_size \le n$).
   - Step 2: Initialize frame array: frames[i] = i for i = 0 to n - 1.
   - Step 3: Maintain window pointer variable base = 0.
   - Step 4: Sender loop:
     * Transmit all frames currently within window: from base to min(base + window_size, n).
     * Display current sender window frames and transmission status.
   - Step 5: Receiver simulation:
     * For each frame in the window, receiver simulates reception and prints
       corresponding acknowledgment ACK = frame + 1.
   - Step 6: Error Simulation Prompt:
     * Ask user: "Did all frames receive correctly? (y/n)".
     * If 'y' / 'Y': Transmission successful! Advance window pointer by window size
       (base += window_size). Window slides forward.
     * If 'n' / 'N': Error detected! Sender initiates Go-Back-N retransmission;
       base remains unchanged, and the entire window is re-sent from frames[base].
   - Step 7: Repeat until all frames (base >= n) are acknowledged.

4. CONCLUSION:
   Successfully implemented and verified the Go-Back-N Sliding Window Protocol
   simulation in C. Demonstrated pipelined frame transmission, cumulative ACK
   generation, window sliding upon acknowledgment, and retransmission of the full
   window upon transmission error.
================================================================================
*/
