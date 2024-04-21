#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QMap>

class FoodOrderingSystem : public QWidget {
    Q_OBJECT

public:
    FoodOrderingSystem(QWidget* parent = nullptr) : QWidget(parent) {
        // Initialize menus
        menus["Restaurant A"] = {{"Pizza", 10}, {"Pasta", 12}, {"Salad", 8}};
        menus["Restaurant B"] = {{"Burger", 8}, {"Fries", 4}, {"Milkshake", 5}};

        // Create the restaurant labels, menu labels, and order buttons
        for (const auto& [restaurant, menu] : menus) {
            QLabel* restaurantLabel = new QLabel(restaurant + ":", this);
            QVBoxLayout* menuLayout = new QVBoxLayout;

            for (const auto& [item, price] : menu) {
                QLabel* menuItemLabel = new QLabel(item + ": $" + QString::number(price), this);
                QPushButton* orderButton = new QPushButton("Order", this);

                // Connect signals and slots
                connect(orderButton, &QPushButton::clicked, this, &FoodOrderingSystem::orderFood);

                // Add to menu layout
                QVBoxLayout* itemLayout = new QVBoxLayout;
                itemLayout->addWidget(menuItemLabel);
                itemLayout->addWidget(orderButton);
                menuLayout->addLayout(itemLayout);
            }

            // Add to main layout
            QVBoxLayout* restaurantLayout = new QVBoxLayout;
            restaurantLayout->addWidget(restaurantLabel);
            restaurantLayout->addLayout(menuLayout);
            mainLayout->addLayout(restaurantLayout);
        }

        // Set up the main layout
        setLayout(mainLayout);
    }

private slots:
    void orderFood() {
        QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
        if (senderButton) {
            QString restaurantName = senderButton->parentWidget()->layout()->itemAt(0)->widget()->property("text").toString().split(":").first();
            QString itemName = senderButton->parentWidget()->layout()->itemAt(0)->widget()->layout()->itemAt(0)->widget()->property("text").toString().split(":").first();
            if (menus[restaurantName].contains(itemName)) {
                QMessageBox::information(this, "Order", "Ordered " + itemName + " from " + restaurantName);
            }
        }
    }

private:
    QMap<QString, QMap<QString, int>> menus;
    QVBoxLayout* mainLayout = new QVBoxLayout;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    FoodOrderingSystem orderingSystem;
    orderingSystem.resize(600, 400);
    orderingSystem.show();

    return app.exec();
}
