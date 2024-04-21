#include <QApplication>
#include <QWebEngineView>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QToolBar>
#include <QAction>
#include <QUrl>

class AdvancedBrowser : public QWidget {
    Q_OBJECT

public:
    AdvancedBrowser(QWidget* parent = nullptr) : QWidget(parent) {
        // Create the web view
        webView = new QWebEngineView(this);
        webView->load(QUrl("https://www.google.com"));

        // Create the URL input field
        urlLineEdit = new QLineEdit(this);
        urlLineEdit->setText("https://www.google.com");

        // Create the Go button
        goButton = new QPushButton("Go", this);

        // Create toolbar actions
        backAction = new QAction("Back", this);
        forwardAction = new QAction("Forward", this);
        refreshAction = new QAction("Refresh", this);

        // Create the toolbar
        QToolBar* toolbar = new QToolBar(this);
        toolbar->addAction(backAction);
        toolbar->addAction(forwardAction);
        toolbar->addAction(refreshAction);

        // Connect signals and slots
        connect(goButton, &QPushButton::clicked, this, &AdvancedBrowser::loadUrl);
        connect(urlLineEdit, &QLineEdit::returnPressed, this, &AdvancedBrowser::loadUrl);
        connect(backAction, &QAction::triggered, webView, &QWebEngineView::back);
        connect(forwardAction, &QAction::triggered, webView, &QWebEngineView::forward);
        connect(refreshAction, &QAction::triggered, webView, &QWebEngineView::reload);

        // Set up the layout
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(toolbar);
        layout->addWidget(urlLineEdit);
        layout->addWidget(goButton);
        layout->addWidget(webView);
        setLayout(layout);
    }

private slots:
    void loadUrl() {
        QString url = urlLineEdit->text();
        if (!url.startsWith("http://") && !url.startsWith("https://")) {
            url = "http://" + url;
        }
        webView->load(QUrl(url));
    }

private:
    QWebEngineView* webView;
    QLineEdit* urlLineEdit;
    QPushButton* goButton;
    QAction* backAction;
    QAction* forwardAction;
    QAction* refreshAction;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    AdvancedBrowser browser;
    browser.resize(800, 600);
    browser.show();

    return app.exec();
}

#include "main.moc"
