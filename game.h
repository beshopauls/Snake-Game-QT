#ifndef GAME_H
#define GAME_H

#include<QWidget>
#include<QVector>
#include<QPoint>
#include<QKeyEvent>
#include<QPainter>
#include<QTime>
#include<QTimerEvent>
#include<QMessageBox>

class Game : public QWidget
{

public:
    Game();
    ~Game();
protected:
      void timerEvent(QTimerEvent* event) override;
     void keyPressEvent(QKeyEvent* event) override;
     void paintEvent(QPaintEvent* event) override;
private:
    static const int Dot_width=20;
    static const int Dot_height=20;
    static const int field_width=30;
    static const int field_height=30;
    static const int DELAY = 150;
    void initGame();
    void Draw();
    void local_Apple();
    void move();
    void check_feild();
    void gameOver();
    void check_apple();
    enum Directions{left,right,up,down};
    int m_timerId;
    int m_score=0;
    QPoint m_apple;
    QVector<QPoint>m_dots;
    Directions m_dir ;
    bool m_inGame;
};

#endif // GAME_H
