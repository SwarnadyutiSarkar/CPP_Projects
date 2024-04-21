#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <cmath>

class Bike : public QGraphicsEllipseItem {
public:
    Bike(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = nullptr)
        : QGraphicsEllipseItem(x, y, width, height, parent), velocity(0), angle(0) {}

    void move() {
        qreal dx = velocity * std::cos(qDegreesToRadians(angle));
        qreal dy = velocity * std::sin(qDegreesToRadians(angle));
        setPos(x() + dx, y() - dy);
    }

    void accelerate(qreal acceleration) {
        velocity += acceleration;
    }

    void turn(qreal deltaAngle) {
        angle += deltaAngle;
        setRotation(angle);
    }

private:
    qreal velocity;
    qreal angle;
};

class BikeRaceGame : public QGraphicsView {
public:
    BikeRaceGame(QWidget* parent = nullptr) : QGraphicsView(parent), scene(new QGraphicsScene(this)), bike(new Bike(50, 50, 20, 10)) {
        setScene(scene);
        scene->addItem(bike);
        bike->setFlag(QGraphicsItem::ItemIsFocusable);
        bike->setFocus();

        // Create AI bikes
        for (int i = 0; i < 3; ++i) {
            Bike* aiBike = new Bike(50 + i * 50, 200, 20, 10);
            aiBike->setBrush(Qt::red);
            aiBikes.append(aiBike);
            scene->addItem(aiBike);
        }

        QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &BikeRaceGame::update);
        timer->start(1000 / 60);  // Update at 60 FPS
    }

protected:
    void keyPressEvent(QKeyEvent* event) override {
        switch (event->key()) {
            case Qt::Key_Up:
                bike->accelerate(0.1);
                break;
            case Qt::Key_Down:
                bike->accelerate(-0.1);
                break;
            case Qt::Key_Left:
                bike->turn(-5);
                break;
            case Qt::Key_Right:
                bike->turn(5);
                break;
            default:
                break;
        }
    }

private slots:
    void update() {
        bike->move();

        // Update AI bikes
        for (Bike* aiBike : qAsConst(aiBikes)) {
            qreal acceleration = 0.1;
            qreal deltaAngle = 5;
            aiBike->accelerate(acceleration);
            aiBike->turn(deltaAngle);
            aiBike->move();
        }
    }

private:
    QGraphicsScene* scene;
    Bike* bike;
    QList<Bike*> aiBikes;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    BikeRaceGame game;
    game.setFixedSize(800, 600);
    game.show();

    return app.exec();
}
