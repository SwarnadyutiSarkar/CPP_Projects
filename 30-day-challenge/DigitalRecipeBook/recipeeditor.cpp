// recipeeditor.cpp
#include "recipeeditor.h"
#include "ui_recipeeditor.h"

RecipeEditor::RecipeEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecipeEditor)
{
    ui->setupUi(this);
}

RecipeEditor::~RecipeEditor() {
    delete ui;
}

void RecipeEditor::setRecipe(const QSqlRecord &record) {
    ui->nameLabel->setText(record.value("name").toString());
    ui->categoryLabel->setText(record.value("category").toString());
    ui->ingredientsTextEdit->setPlainText(record.value("ingredients").toString());
    ui->instructionsTextEdit->setPlainText(record.value("instructions").toString());
    QByteArray imageData = record.value("image").toByteArray();
    QImage image;
    image.loadFromData(imageData);
    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
}
