// 3. Reverse first k elements of  queue.


#include <stdio.h>
#include "../Queue/queue.h"

void reverse_k(Queue *q, uint32_t k) {
    if (k == 0 || k > q->count) {
        printf("Invalid k\n");
        return;
    }

    int32_t stack[MAX_QUEUE_LEN];
    uint32_t top = 0;
    uint32_t n = q->count;
    QueueResult result;

    for (int i = 0; i < k; i++) {
        queue_remove(q, &result);
        stack[top++] = result.data;
    }

    while (top > 0) {
        queue_add(q, stack[--top], &result);
    }

    for (int i = 0; i < n - k; i++) {
        queue_remove(q, &result);
        int data = result.data;
        queue_add(q, data, &result);
    }
}

void display(Queue *q) {
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->q[(q->head + i) % q->size]);
    }
    printf("\n");
}

int main() {
    Queue q = queue_new(10);
    QueueResult result;

    queue_add(&q, 10, &result);
    queue_add(&q, 20, &result);
    queue_add(&q, 30, &result);
    queue_add(&q, 40, &result);
    queue_add(&q, 50, &result);
    queue_add(&q, 60, &result);

    printf("Original Queue: ");
    display(&q);

    reverse_k(&q, 3);

    printf("After reversing first 3 elements: ");
    display(&q);

    return 0;
}

