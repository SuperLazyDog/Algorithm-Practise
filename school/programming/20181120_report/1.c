#include <stdio.h>
#include <stdlib.h>

typedef struct point {
  int x;
  int y;
} Point;

typedef struct checkerboard { // 隣り合う碁石の間隔を 1 とみなす
  int n;
  int pointLimit;
  int pointCount;
  Point **points;
} Checkerboard;

typedef struct set {
  int capacity;
  int count;
  int *data;
} Set;

Checkerboard *createCheckerboard(int n); // 碁盤を作る
void deleteCheckerboard(Checkerboard *checkerboard); // 碁盤を削除
void processCheckerboard(Point startPoint, Point lastPoint, Checkerboard board, Set s);
void showCheckerboard(Checkerboard *checkerboard); // 碁石の配置一覧

Set *createSet(void);
void expendCapacity(Set *s);
void deleteSet(Set *s);
void addElementToSet(int newElement, Set *s);
int include(int element, Set *s);

int main(int argc, char const *argv[]) {
  int n, lx = 0, ly = 0, i;
  printf("please input n:");
  scanf("%d", &n);
  Checkerboard *board = createCheckerboard(n);
  Set *s = createSet();
  Point p, op;
  p.x = op.x = 0;
  for (i = 0; i < n; i++) {
    p.y = op.y = i;
    processCheckerboard(p, op, *board, *s);
  }
  deleteCheckerboard(board);
  deleteSet(s);
  return 0;
}


Checkerboard *createCheckerboard(int n) { // 碁盤を作る
  Checkerboard *newBoard = (Checkerboard *)malloc(sizeof(Checkerboard));
  newBoard->n = newBoard->pointLimit = n;
  newBoard->points = (Point **)malloc(sizeof(Point*)*n);
  newBoard->pointCount = 0;
  return newBoard;
}

void deleteCheckerboard(Checkerboard *checkerboard) { // 碁盤を削除
  if (checkerboard) {
    if (checkerboard->points) {
      free(checkerboard->points);
    }
    free(checkerboard);
  }
}

int count = 0; // TODO: delete
void processCheckerboard(Point startPoint, Point lastPoint, Checkerboard board, Set s) {
  Point p1, p2, p3;
  int canToP1 = 1, canToP2 = 1, canToP3 = 1, i, canAddPoint = 1;
  p1.x = p2.x = p3.x = startPoint.x;
  p1.y = p2.y = p3.y = startPoint.y;
  p1.x++;p2.y++;p3.y--;
  // 碁石追加
  int newDistants_2[board.pointCount];
  if (board.pointCount > 0) {
    for (int i = 0; i < board.pointCount; i++) {
      int dx = startPoint.x - board.points[i]->x, dy = startPoint.y - board.points[i]->y;
      newDistants_2[i] = dx*dx + dy*dy;
      if (include(newDistants_2[i], &s)) {
        canAddPoint = 0;
        break;
      }
    }
    if (canAddPoint) { // 途中の
      for (int i = 0; i < board.pointCount-1; i++) {
        for (int j = i+1; j < board.pointCount; j++) {
          if (newDistants_2[i] == newDistants_2[j]) {
            canAddPoint = 0;
            break;
          }
        }
      }
    }
    if (canAddPoint) {
      for (int i = 0; i < board.pointCount; i++) {
        addElementToSet(newDistants_2[i], &s);
      }
    }
  }
  if (board.pointCount < board.pointLimit && canAddPoint) {
    board.points[board.pointCount] = (Point *)malloc(sizeof(Point));
    board.points[board.pointCount]->x = startPoint.x;
    board.points[board.pointCount]->y = startPoint.y;
    board.pointCount++;
  }

  // 全部の追加完了するかどうか
  if (board.pointCount >= board.pointLimit) {
    showCheckerboard(&board);
    printf("count: %d\n", ++count);
    puts("");
    return;
  }

  // 完了していない場合次の追加へ
  for (int i = 0; i < board.pointCount; i++) { // すでに追加済み
    int x = board.points[i]->x, y = board.points[i]->y;
    if (x == p1.x && y == p1.y) {
      canToP1 = 0;
    }
    if (x == p2.x && y == p2.y) {
      canToP2 = 0;
    }
    if (x == p3.x && y == p3.y) {
      canToP3 = 0;
    }
  }
  if (lastPoint.x == p1.x && lastPoint.y ==p1.y) {
    canToP1 = 0;
  }
  if (lastPoint.x == p2.x && lastPoint.y ==p2.y) {
    canToP2 = 0;
  }
  if (lastPoint.x == p3.x && lastPoint.y ==p3.y) {
    canToP3 = 0;
  }

  lastPoint.x = startPoint.x; lastPoint.y = startPoint.y;
  if (p1.x < board.n && canToP1) {
    processCheckerboard(p1, lastPoint, board, s);
  }
  if (p2.y < board.n && canToP2) {
    processCheckerboard(p2, lastPoint, board, s);
  }
  if (p3.y >= 0 && canToP3) {
    processCheckerboard(p3, lastPoint, board, s);
  }
}

void showCheckerboard(Checkerboard *checkerboard) { // 碁石の配置一覧
  int i, j, n = checkerboard->pointLimit;
  char chr[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      chr[i][j] = '-';
    }
  }

  for (i = 0; i < checkerboard->pointCount; i++) { // TODO
    Point *p = checkerboard->points[i];
    // printf("(%d, %d)\n", p->x, p->y);
    chr[p->y][p->x] = 'o';
  }

  for (i = 0; i < n; i++) {
    for (j  = 0;  j< n; j++) {
      printf("%c ", chr[i][j]);
    }
    puts("");
  }
}

Set *createSet(void) {
  Set *s = (Set *)malloc(sizeof(Set));
  s->capacity = 128;s->count=0;
  s->data = (int *)malloc(sizeof(int)*s->capacity);
  return s;
}

void expendCapacity(Set *s) {
  s->capacity *= 2;
  s->data = (int *)realloc(s->data, sizeof(int)*s->capacity);
}

void deleteSet(Set *s) {
  if (s) {
    if (s->data) {
      free(s->data);
    }
    free(s);
  }
}

void addElementToSet(int newElement, Set *s) {
  int i, canAdd = 1;
  for(i = 0; i < s->count; i++) {
    if(s->data[i] == newElement) {
      canAdd = 0;
      break;
    }
  }
  if (canAdd) {
    if (s->count >= s->capacity) {
      expendCapacity(s);
    }
    s->data[s->count] = newElement;
    s->count++;
  }
}

int include(int element, Set *s) {
  int i;
  for (i = 0; i < s->count; i++) {
    if (s->data[i] == element) {
      return 1;
    }
  }
  return 0;
}
