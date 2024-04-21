#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QVector>
#include <QRandomGenerator>
#include <QDebug>

class BlackjackGame : public QWidget {
    Q_OBJECT

public:
    BlackjackGame(QWidget* parent = nullptr) : QWidget(parent) {
        // Initialize deck
        initializeDeck();

        // Create the game labels and buttons
        playerScoreLabel = new QLabel("Player Score: 0", this);
        aiScoreLabel = new QLabel("AI Score: 0", this);
        dealButton = new QPushButton("Deal", this);
        hitButton = new QPushButton("Hit", this);
        standButton = new QPushButton("Stand", this);

        // Connect signals and slots
        connect(dealButton, &QPushButton::clicked, this, &BlackjackGame::deal);
        connect(hitButton, &QPushButton::clicked, this, &BlackjackGame::hit);
        connect(standButton, &QPushButton::clicked, this, &BlackjackGame::stand);

        // Set up the layout
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(playerScoreLabel);
        layout->addWidget(aiScoreLabel);
        layout->addWidget(dealButton);
        layout->addWidget(hitButton);
        layout->addWidget(standButton);
        setLayout(layout);
    }

private slots:
    void deal() {
        playerHand.clear();
        aiHand.clear();

        // Deal initial cards
        playerHand.append(drawCard());
        playerHand.append(drawCard());
        aiHand.append(drawCard());
        aiHand.append(drawCard());

        // Update scores and labels
        updateScores();
    }

    void hit() {
        playerHand.append(drawCard());

        // Update scores and labels
        updateScores();

        // Check for bust
        if (calculateScore(playerHand) > 21) {
            endGame("Player busts! AI wins.");
        }
    }

    void stand() {
        // AI's turn
        while (calculateScore(aiHand) < 17) {
            aiHand.append(drawCard());
        }

        // Update scores and labels
        updateScores();

        // Determine winner
        int playerScore = calculateScore(playerHand);
        int aiScore = calculateScore(aiHand);
        if (playerScore > 21) {
            endGame("Player busts! AI wins.");
        } else if (aiScore > 21) {
            endGame("AI busts! Player wins.");
        } else if (playerScore > aiScore) {
            endGame("Player wins!");
        } else if (aiScore > playerScore) {
            endGame("AI wins.");
        } else {
            endGame("It's a tie!");
        }
    }

private:
    QVector<QString> deck;
    QVector<QString> playerHand;
    QVector<QString> aiHand;
    QLabel* playerScoreLabel;
    QLabel* aiScoreLabel;
    QPushButton* dealButton;
    QPushButton* hitButton;
    QPushButton* standButton;

    void initializeDeck() {
        deck.clear();
        QStringList suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
        QStringList ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

        for (const auto& suit : suits) {
            for (const auto& rank : ranks) {
                deck.append(rank + " of " + suit);
            }
        }
    }

    QString drawCard() {
        int index = QRandomGenerator::global()->bounded(deck.size());
        QString card = deck[index];
        deck.remove(index);
        return card;
    }

    int calculateScore(const QVector<QString>& hand) {
        int score = 0;
        int aceCount = 0;

        for (const auto& card : hand) {
            QString rank = card.split(" ").first();
            if (rank == "Ace") {
                score += 11;
                aceCount++;
            } else if (rank == "Jack" || rank == "Queen" || rank == "King") {
                score += 10;
            } else {
                score += rank.toInt();
            }
        }

        while (score > 21 && aceCount > 0) {
            score -= 10;
            aceCount--;
        }

        return score;
    }

    void updateScores() {
        int playerScore = calculateScore(playerHand);
        int aiScore = calculateScore(aiHand);
        playerScoreLabel->setText("Player Score: " + QString::number(playerScore));
        aiScoreLabel->setText("AI Score: " + QString::number(aiScore));
    }

    void endGame(const QString& message) {
        QMessageBox::information(this, "Game Over", message);
        dealButton->setEnabled(true);
        hitButton->setEnabled(false);
        standButton->setEnabled(false);
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    BlackjackGame game;
    game.resize(400, 300);
    game.show();

    return app.exec();
}
