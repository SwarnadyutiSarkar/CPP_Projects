#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    model(new QSqlTableModel(this))
{
    ui->setupUi(this);
    setupDatabase();
    refreshRecipeList();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("recipes.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Error", "Failed to open database.");
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS recipes (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, category TEXT, ingredients TEXT, instructions TEXT, image BLOB)");

    model->setTable("recipes");
    model->select();
    ui->recipesTableView->setModel(model);
}

void MainWindow::refreshRecipeList() {
    model->select();
}

void MainWindow::on_addRecipeButton_clicked() {
    QString name = ui->nameLineEdit->text();
    QString category = ui->categoryLineEdit->text();
    QString ingredients = ui->ingredientsTextEdit->toPlainText();
    QString instructions = ui->instructionsTextEdit->toPlainText();
    QString imagePath = QFileDialog::getOpenFileName(this, "Select Recipe Image", "", "Images (*.png *.jpg *.bmp)");

    if (name.isEmpty() || category.isEmpty() || ingredients.isEmpty() || instructions.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill all fields.");
        return;
    }

    QFile file(imagePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Image Error", "Failed to open image file.");
        return;
    }
    QByteArray imageData = file.readAll();

    QSqlQuery query;
    query.prepare("INSERT INTO recipes (name, category, ingredients, instructions, image) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(category);
    query.addBindValue(ingredients);
    query.addBindValue(instructions);
    query.addBindValue(imageData);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to add recipe.");
    }

    refreshRecipeList();
}

void MainWindow::on_searchButton_clicked() {
    QString searchText = ui->searchLineEdit->text();
    model->setFilter(QString("name LIKE '%%1%'").arg(searchText));
    model->select();
}
