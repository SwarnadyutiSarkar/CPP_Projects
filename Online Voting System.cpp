#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QMap>

class OnlineVotingSystem : public QWidget {
    Q_OBJECT

public:
    OnlineVotingSystem(QWidget* parent = nullptr) : QWidget(parent) {
        // Initialize candidates
        candidates["Candidate A"] = 0;
        candidates["Candidate B"] = 0;
        candidates["Candidate C"] = 0;

        // Create the candidate labels and vote buttons
        for (const auto& [candidate, votes] : candidates) {
            QLabel* candidateLabel = new QLabel(candidate + ": " + QString::number(votes) + " votes", this);
            voteButtons[candidate] = new QPushButton("Vote", this);

            // Connect signals and slots
            connect(voteButtons[candidate], &QPushButton::clicked, this, &OnlineVotingSystem::voteForCandidate);

            // Add to layout
            QVBoxLayout* candidateLayout = new QVBoxLayout;
            candidateLayout->addWidget(candidateLabel);
            candidateLayout->addWidget(voteButtons[candidate]);
            mainLayout->addLayout(candidateLayout);
        }

        // Set up the main layout
        setLayout(mainLayout);
    }

private slots:
    void voteForCandidate() {
        QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
        if (senderButton) {
            QString candidateName = senderButton->parentWidget()->layout()->itemAt(0)->widget()->property("text").toString().split(":").first();
            if (candidates.contains(candidateName)) {
                candidates[candidateName]++;
                QMessageBox::information(this, "Vote", "Voted for " + candidateName);
                updateCandidateLabels();
            }
        }
    }

    void updateCandidateLabels() {
        for (const auto& [candidate, votes] : candidates) {
            QLabel* candidateLabel = dynamic_cast<QLabel*>(mainLayout->itemAt(0)->layout()->itemAt(0)->layout()->itemAt(0)->widget());
            candidateLabel->setText(candidate + ": " + QString::number(votes) + " votes");
        }
    }

private:
    QMap<QString, int> candidates;
    QMap<QString, QPushButton*> voteButtons;
    QVBoxLayout* mainLayout = new QVBoxLayout;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    OnlineVotingSystem votingSystem;
    votingSystem.resize(400, 300);
    votingSystem.show();

    return app.exec();
}
