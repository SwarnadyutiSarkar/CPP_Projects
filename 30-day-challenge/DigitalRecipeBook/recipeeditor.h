// recipeeditor.h
#ifndef RECIPEEDITOR_H
#define RECIPEEDITOR_H

#include <QDialog>
#include <QSqlRecord>

QT_BEGIN_NAMESPACE
namespace Ui { class RecipeEditor; }
QT_END_NAMESPACE

class RecipeEditor : public QDialog {
    Q_OBJECT

public:
    explicit RecipeEditor(QWidget *parent = nullptr);
    ~RecipeEditor();
    void setRecipe(const QSqlRecord &record);

private:
    Ui::RecipeEditor *ui;
};

#endif // RECIPEEDITOR_H
