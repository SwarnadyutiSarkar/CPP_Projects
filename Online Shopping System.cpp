#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QMap>

class OnlineShoppingSystem : public QWidget {
    Q_OBJECT

public:
    OnlineShoppingSystem(QWidget* parent = nullptr) : QWidget(parent) {
        // Initialize products
        products["Electronics"] = {{"Laptop", 1000}, {"Smartphone", 800}, {"Tablet", 500}};
        products["Clothing"] = {{"T-Shirt", 20}, {"Jeans", 50}, {"Dress", 70}};

        // Create the category labels, product labels, and add to cart buttons
        for (const auto& [category, productList] : products) {
            QLabel* categoryLabel = new QLabel(category + ":", this);
            QVBoxLayout* productLayout = new QVBoxLayout;

            for (const auto& [product, price] : productList) {
                QLabel* productLabel = new QLabel(product + ": $" + QString::number(price), this);
                QPushButton* addToCartButton = new QPushButton("Add to Cart", this);

                // Connect signals and slots
                connect(addToCartButton, &QPushButton::clicked, this, &OnlineShoppingSystem::addToCart);

                // Add to product layout
                QVBoxLayout* itemLayout = new QVBoxLayout;
                itemLayout->addWidget(productLabel);
                itemLayout->addWidget(addToCartButton);
                productLayout->addLayout(itemLayout);
            }

            // Add to main layout
            QVBoxLayout* categoryLayout = new QVBoxLayout;
            categoryLayout->addWidget(categoryLabel);
            categoryLayout->addLayout(productLayout);
            mainLayout->addLayout(categoryLayout);
        }

        // Set up the main layout
        setLayout(mainLayout);
    }

private slots:
    void addToCart() {
        QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
        if (senderButton) {
            QString productCategory = senderButton->parentWidget()->layout()->itemAt(0)->widget()->property("text").toString().split(":").first();
            QString productName = senderButton->parentWidget()->layout()->itemAt(0)->widget()->layout()->itemAt(0)->widget()->property("text").toString().split(":").first();
            if (products[productCategory].contains(productName)) {
                QMessageBox::information(this, "Cart", "Added " + productName + " to cart");
            }
        }
    }

private:
    QMap<QString, QMap<QString, int>> products;
    QVBoxLayout* mainLayout = new QVBoxLayout;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    OnlineShoppingSystem shoppingSystem;
    shoppingSystem.resize(600, 400);
    shoppingSystem.show();

    return app.exec();
}
