#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QMap>

class JobPortal : public QWidget {
    Q_OBJECT

public:
    JobPortal(QWidget* parent = nullptr) : QWidget(parent) {
        // Initialize jobs
        jobs["Software Engineer"] = "3+ years experience";
        jobs["Data Analyst"] = "2+ years experience";
        jobs["Product Manager"] = "5+ years experience";

        // Create the job labels and apply buttons
        for (const auto& [jobTitle, requirements] : jobs) {
            QLabel* jobLabel = new QLabel(jobTitle + ": " + requirements, this);
            applyButtons[jobTitle] = new QPushButton("Apply", this);

            // Connect signals and slots
            connect(applyButtons[jobTitle], &QPushButton::clicked, this, &JobPortal::applyForJob);

            // Add to layout
            QVBoxLayout* jobLayout = new QVBoxLayout;
            jobLayout->addWidget(jobLabel);
            jobLayout->addWidget(applyButtons[jobTitle]);
            mainLayout->addLayout(jobLayout);
        }

        // Set up the main layout
        setLayout(mainLayout);
    }

private slots:
    void applyForJob() {
        QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
        if (senderButton) {
            QString jobTitle = senderButton->parentWidget()->layout()->itemAt(0)->widget()->property("text").toString().split(":").first();
            if (jobs.contains(jobTitle)) {
                QMessageBox::information(this, "Application", "Applied for " + jobTitle);
            }
        }
    }

private:
    QMap<QString, QString> jobs;
    QMap<QString, QPushButton*> applyButtons;
    QVBoxLayout* mainLayout = new QVBoxLayout;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    JobPortal jobPortal;
    jobPortal.resize(400, 300);
    jobPortal.show();

    return app.exec();
}
