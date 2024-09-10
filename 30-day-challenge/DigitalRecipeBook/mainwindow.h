#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addRecipeButton_clicked();
    void on_searchButton_clicked();

private:
    void setupDatabase();
    void refreshRecipeList();

    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
