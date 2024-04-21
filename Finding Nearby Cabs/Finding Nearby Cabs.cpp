#include <QApplication>
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>

class NearbyCabs : public QWidget {
    Q_OBJECT

public:
    NearbyCabs(QWidget* parent = nullptr) : QWidget(parent) {
        // Create the web view
        webView = new QWebEngineView(this);

        // Load the HTML file with Mapbox GL JS API
        webView->load(QUrl("qrc:/map.html"));

        // Set up the layout
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(webView);
        setLayout(layout);
    }

private:
    QWebEngineView* webView;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    NearbyCabs nearbyCabs;
    nearbyCabs.resize(800, 600);
    nearbyCabs.show();

    return app.exec();
}

#include "main.moc"
