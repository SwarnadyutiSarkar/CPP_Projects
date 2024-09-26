#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QToolBar>
#include <QWebEngineView>
#include <QVBoxLayout>

class Browser : public QMainWindow {
    Q_OBJECT

public:
    Browser() {
        view = new QWebEngineView(this);
        setCentralWidget(view);

        QToolBar *toolbar = addToolBar("Navigation");
        QLineEdit *urlEdit = new QLineEdit(this);
        toolbar->addWidget(urlEdit);

        connect(urlEdit, &QLineEdit::returnPressed, [this, urlEdit]() {
            view->setUrl(QUrl(urlEdit->text()));
        });

        // Load a default URL
        view->setUrl(QUrl("http://www.example.com"));
    }

private:
    QWebEngineView *view;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Browser browser;
    browser.resize(800, 600);
    browser.show();
    return app.exec();
}
