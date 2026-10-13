#include <iostream>

using namespace std;

#define ROW 10
#define COL 10

struct Point {
    int x;
    int y;
    int dist;
};
class Queue {
private:
    Point arr[ROW * COL];
    int front;
    int rear;
    int count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(Point p) {
        if (count < ROW * COL) {
            rear = (rear + 1) % (ROW * COL);
            arr[rear] = p;
            count++;
        }
    }

    Point dequeue() {
        Point p = arr[front];
        front = (front + 1) % (ROW * COL);
        count--;
        return p;
    }

    bool isEmpty() const {
        return (count == 0);
    }
};

bool isValid(int row, int col, int mat[ROW][COL], bool visited[ROW][COL]) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && 
            mat[row][col] == 1 && !visited[row][col]);
}

int BFS(int mat[ROW][COL], Point src, Point dest) {
    if (mat[src.x][src.y] == 0 || mat[dest.x][dest.y] == 0)
        return -1;

    bool visited[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }

    visited[src.x][src.y] = true;

    Queue q;
    src.dist = 0;
    q.enqueue(src);

    int rowNum[] = {-1, 0, 1, 0};
    int colNum[] = {0, -1, 0, 1};

    while (!q.isEmpty()) {
        Point curr = q.dequeue();

        if (curr.x == dest.x && curr.y == dest.y)
            return curr.dist;

        for (int i = 0; i < 4; i++) {
            int nX = curr.x + rowNum[i];
            int nY = curr.y + colNum[i];

            if (isValid(nX, nY, mat, visited)) {
                visited[nX][nX] = true;
                visited[nX][nY] = true; 
                Point adjCell = {nX, nY, curr.dist + 1};
                q.enqueue(adjCell);
            }
        }
    }

    return -1;
}

int main() {
    int mat[ROW][COL] = {
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 1}
    };

    Point source = {0, 0, 0};
    Point destination = {7, 5, 0};

    int dist = BFS(mat, source, destination);

    if (dist != -1)
        cout << "Shortest Path Length is: " << dist << endl;
    else
        cout << "Path doesn't exist!" << endl;

    return 0;
}