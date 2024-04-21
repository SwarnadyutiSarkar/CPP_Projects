#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QMap>

class TicketReservationSystem : public QWidget {
    Q_OBJECT

public:
    TicketReservationSystem(QWidget* parent = nullptr) : QWidget(parent) {
        // Initialize tickets
        tickets["Concert Ticket"] = 10;
        tickets["Movie Ticket"] = 20;
        tickets["Sports Ticket"] = 15;

        // Create the ticket labels and reserve buttons
        for (const auto& [ticket, quantity] : tickets) {
            QLabel* ticketLabel = new QLabel(ticket + ": " + QString::number(quantity) + " available", this);
            reserveButtons[ticket] = new QPushButton("Reserve", this);

            // Connect signals and slots
            connect(reserveButtons[ticket], &QPushButton::clicked, this, &TicketReservationSystem::reserveTicket);

            // Add to layout
            QVBoxLayout* ticketLayout = new QVBoxLayout;
            ticketLayout->addWidget(ticketLabel);
            ticketLayout->addWidget(reserveButtons[ticket]);
            mainLayout->addLayout(ticketLayout);
        }

        // Set up the main layout
        setLayout(mainLayout);
    }

private slots:
    void reserveTicket() {
        QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
        if (senderButton) {
            QString ticketName = senderButton->parentWidget()->layout()->itemAt(0)->widget()->property("text").toString().split(":").first();
            if (tickets.contains(ticketName) && tickets[ticketName] > 0) {
                tickets[ticketName]--;
                QMessageBox::information(this, "Reservation", "Reserved " + ticketName);
                updateTicketLabels();
            } else {
                QMessageBox::warning(this, "Reservation", "No available " + ticketName + "s");
            }
        }
    }

    void updateTicketLabels() {
        for (const auto& [ticket, quantity] : tickets) {
            QLabel* ticketLabel = dynamic_cast<QLabel*>(mainLayout->itemAt(0)->layout()->itemAt(0)->layout()->itemAt(0)->widget());
            ticketLabel->setText(ticket + ": " + QString::number(quantity) + " available");
        }
    }

private:
    QMap<QString, int> tickets;
    QMap<QString, QPushButton*> reserveButtons;
    QVBoxLayout* mainLayout = new QVBoxLayout;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    TicketReservationSystem reservationSystem;
    reservationSystem.resize(400, 300);
    reservationSystem.show();

    return app.exec();
}
