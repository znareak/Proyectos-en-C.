#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, k, j, x = 0, current = 1;
  scanf("%d", & n);

  int board[n][n], y = n / 2, max_value = n * n;

  for (k = 0; k < n; k++) {
    for (j = 0; j < n; j++) {
      board[k][j] = 0;
    }
  }

  while (current < max_value) {
    board[x][y] = current;
    if (x == 0) {
      if (y == n - 1) {
        x++;
      } else {
        x = n - 1;
        y++;
      }
    } else {
      x--;
      y++;
      if (y >= n) {
        y = 0;
      } else if (board[x][y] != 0) {
        x += 2;
        y--;
      }
    }

    current++;
  }
  for (k = 0; k < n; k++) {
    for (j = 0; j < n; j++) {
      printf("%d ", board[k][j]);
    }
    printf("\n");
  }
  
  system("pause");
  return 0;
}