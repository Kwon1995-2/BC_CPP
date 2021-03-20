//학번
//이름
//Github ID:
//2019년 1학기 실습코드-coding exam
/*
testing items:
1) virtual function, dynamic binding
2) operator overloading
3) code reuse for private data access
*/
#include <iostream>
using namespace std;
enum ObjectPiece {EMPTY, WALL, BISHOP, XBISHOP, ROOK, XROOK, QUEEN, XQUEEN};
//XROOK, XBISHOP, XQUEEN은 ROOK, BISHOP, QUEEN에 의해 다른 piece를 put할 수 없음을 표시
ObjectPiece board[10][10];//[0], [9]: boundary
class Piece;
class ChessBoard {
public:
	ChessBoard();
	int AddPiece(Piece *);//board[i][j]에 piece를 추가
	int MoreAddPiece();//board[][]에 piece를 더 이상 추가할 수 없는지를 check
	friend ostream& operator<<(ostream& stream, ChessBoard& cb);//need to implement <<()
};
class Piece {
protected:
	int x;
	int y;
	ObjectPiece PieceType;
public:
	virtual int CheckBoard(int, int);
	virtual ObjectPiece MarkPiece(int row, int col) { x = row; y = col; }
	friend ostream & operator<<(ostream & stream, Piece& p);//함수 구현
};
class Bishop : public Piece {
	//move any number of squares in a diagonal direction
public:
	Bishop() { PieceType = BISHOP; }
	~Bishop() {}
	int CheckBoard(int row, int col) {
		//current location(x,y)의 대각선에 다른 객체 여부를 조사, XBISHOP, XROOK, XQUEEN은 무시함
		return 0;//no checked piece
	}
	ObjectPiece MarkPiece(int row, int col);
	friend ostream & operator<<(ostream & stream, Bishop& p);
};
class Rook : public Piece {
public:
	Rook() { PieceType = ROOK; }
	~Rook() {}
	//move any number of squares in a straight line along any row or column
	int CheckBoard(int row, int col) {
		//current location(x,y)의 수직, 수평선에 다른 객체 여부를 조사, XBISHOP, XROOK, XQUEEN은 무시함
		return 0;//no checked piece
	}
	ObjectPiece MarkPiece(int, int);
	friend ostream & operator<<(ostream & stream, Rook& p);
};
class Queen : public Piece {
public:
	Queen() { PieceType = QUEEN; }
	~Queen() {}
	/*
	chessboard queen can attack horizontally and vertically and diagonally.
	The N queen is the problem of placing N chess queens on an 8 x 8 chessboard so that
	no two queens attack each other
	*/
	int CheckBoard(int row, int col) {
		//current location(x,y)의 수직, 수평선, 대각선에 다른 객체 여부를 조사 - return 1;//checked piece
		//XBISHOP, XROOK, XQUEEN은 무시함
		return 0;//no checked piece
	}
	ObjectPiece MarkPiece(int, int);
	friend ostream & operator<<(ostream & stream, Queen& p);
};

int ChessBoard::AddPiece(Piece *p) {
	do {
		int row = 0, col = 0;
		//random number 생성하여 1<=row<=8, 1<=col<=8
		if (board[row][col] == EMPTY) {
			if (!p->CheckBoard(row, col)) {//board[row][col]에 piece를 추가할 수 있는지를 check
				ObjectPiece op = p->MarkPiece(row, col);//piece가 eat 할 수 있는 room을 marking
				board[row][col] = op;//add piece to board[row][col]
				break;
			}
		}
	} while (MoreAddPiece());//add되는 piece를 추가할 수 있는 공간이 있으면 반복
	return 1;
}
ChessBoard::ChessBoard() {//초기화 설정
	for (int i = 0; i <= 10; i++)
		for (int j = 0; j <= 10; j++)
			if (i == 0 || i == 10 || j == 0 || j == 10)
				board[i][j] = WALL;
			else board[i][j] = EMPTY;
}
int ChessBoard::MoreAddPiece() {
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			if (board[i][j] == EMPTY)
				return 1;
			else return 0;
}
ObjectPiece Bishop::MarkPiece(int row, int col) {
	Piece::MarkPiece(row, col);
	//check diagonal - board[i][j] = XBISHOP;
		//if conflicted with Rook, Bishop, priority order: Queen > Rook > Bishop
	return BISHOP;
}
ObjectPiece Rook::MarkPiece(int row, int col) {
	Piece::MarkPiece(row, col);
	//check vertical and horizontal line - board[][] = XROOK;
		//if conflicted with Rook, Bishop, priority order: Queen > Rook > Bishop
	return ROOK;
}
ObjectPiece Queen::MarkPiece(int row, int col) {
	Piece::MarkPiece(row, col);
	//check diagonal, vertical, horizontal line: board[][] = XQUEEN;
	//if conflicted with Rook, Bishop, priority order: Queen > Rook > Bishop
	return QUEEN;
}
ostream & operator<<(ostream & stream, Piece& p) {
	//
}
ostream & operator<<(ostream & stream, Queen& p) {
	cout << (Piece)p;
	//
}
ostream & operator<<(ostream & stream, Rook& p) {
	cout << (Piece)p;
	//
}
ostream & operator<<(ostream & stream, Bishop& p) {
	cout << (Piece)p;
	//
}
int main() {
	ChessBoard cb;
	Piece* p[20];
	int random;
	for (int i = 0; i < 20; i++)
		//rand() 호출하여 0<=random<=2 결정
		if (random == 0)
			p[i] = new Bishop;
		else if (random == 1)
			p[i] = new Rook;
		else p[i] = new Queen;
	int index = 0;
	do
	{
		//rand() 호출하여 0<= index<= 20 생성
		cb.AddPiece(p[index++]);
	} while (cb.MoreAddPiece());
	for (int i = 0; i < 20; i++)
		cout << " Piece object Type = " << *p[i] << endl;//piece 는 queen, rook, bishop으로 표기
	cout << "ChessBoard[][] = " << cb << endl;//piece 는 queen, rook, bishop, xqueen, xrook, xbishop으로 표기
	system("pause");
	return 1;
}