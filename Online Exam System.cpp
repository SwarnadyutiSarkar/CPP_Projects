#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

class OnlineExamSystem : public QWidget {
    Q_OBJECT

public:
    OnlineExamSystem(QWidget* parent = nullptr) : QWidget(parent) {
        // Create the question label
        questionLabel = new QLabel("What is the capital of France?", this);

        // Create the options buttons
        optionAButton = new QPushButton("A. London", this);
        optionBButton = new QPushButton("B. Berlin", this);
        optionCButton = new QPushButton("C. Paris", this);
        optionDButton = new QPushButton("D. Madrid", this);

        // Connect signals and slots
        connect(optionAButton, &QPushButton::clicked, this, &OnlineExamSystem::checkAnswer);
        connect(optionBButton, &QPushButton::clicked, this, &OnlineExamSystem::checkAnswer);
        connect(optionCButton, &QPushButton::clicked, this, &OnlineExamSystem::checkAnswer);
        connect(optionDButton, &QPushButton::clicked, this, &OnlineExamSystem::checkAnswer);

        // Set up the layout
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(questionLabel);
        layout->addWidget(optionAButton);
        layout->addWidget(optionBButton);
        layout->addWidget(optionCButton);
        layout->addWidget(optionDButton);
        setLayout(layout);
    }

private slots:
    void checkAnswer() {
        QObject* sender = QObject::sender();
        if (sender == optionCButton) {
            QMessageBox::information(this, "Result", "Correct Answer!");
        } else {
            QMessageBox::information(this, "Result", "Wrong Answer!");
        }
    }

private:
    QLabel* questionLabel;
    QPushButton* optionAButton;
    QPushButton* optionBButton;
    QPushButton* optionCButton;
    QPushButton* optionDButton;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    OnlineExamSystem examSystem;
    examSystem.resize(400, 300);
    examSystem.show();

    return app.exec();
}
