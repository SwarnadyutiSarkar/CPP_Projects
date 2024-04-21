#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QVector>
#include <QMap>
#include <QDebug>

class ChessGame : public QWidget {
    Q_OBJECT

public:
    ChessGame(QWidget* parent = nullptr) : QWidget(parent) {
        // Initialize the chess board
        initializeBoard();

        // Create the game labels and buttons
        currentPlayerLabel = new QLabel("Current Player: White", this);
        moveStatusLabel = new QLabel("Move Status: ", this);
        QPushButton* newGameButton = new QPushButton("New Game", this);

        // Connect signals and slots
        connect(newGameButton, &QPushButton::clicked, this, &ChessGame::newGame);

        // Set up the layout
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(currentPlayerLabel);
        layout->addWidget(moveStatusLabel);
        layout->addWidget(newGameButton);
        setLayout(layout);
    }

private slots:
    void newGame() {
        initializeBoard();
    }

private:
    enum PieceType {
        EMPTY,
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING
    };

    enum PieceColor {
        NONE,
        WHITE,
        BLACK
    };

    struct Piece {
        PieceType type;
        PieceColor color;
    };

    Piece board[8][8];
    QLabel* currentPlayerLabel;
    QLabel* moveStatusLabel;
    PieceColor currentPlayer = WHITE;

    void initializeBoard() {
        // Initialize empty board
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j].type = EMPTY;
                board[i][j].color = NONE;
            }
        }

        // Initialize pawns
        for (int j = 0; j < 8; j++) {
            board[1][j].type = PAWN;
            board[1][j].color = BLACK;
            board[6][j].type = PAWN;
            board[6][j].color = WHITE;
        }

        // Initialize other pieces
        PieceType initialPieces[] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
        for (int i = 0; i < 8; i++) {
            board[0][i].type = initialPieces[i];
            board[0][i].color = BLACK;
            board[7][i].type = initialPieces[i];
            board[7][i].color = WHITE;
        }

        updateStatusLabel();
    }

    void updateStatusLabel() {
        QString status = "Move Status: ";
        status += (currentPlayer == WHITE) ? "White's turn" : "Black's turn";
        moveStatusLabel->setText(status);
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    ChessGame game;
    game.resize(400, 400);
    game.show();

    return app.exec();
}
