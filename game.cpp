#include "game.h"
Game::Game()//*
{
  this->resize(Dot_width*field_width,Dot_height*field_height);
    this->setWindowTitle("Snake Game");
    initGame();
}
void Game::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    if(m_inGame)
    {
      check_apple();
        move();
    check_feild();
    }

this->repaint();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if(key == Qt::Key_Left && m_dir != Directions::right)
                     {m_dir = Directions::left;}
    if(key == Qt::Key_Right && m_dir != Directions::left)
                     {m_dir = Directions::right;}
    if(key == Qt::Key_Up && m_dir != Directions::down)
                     {m_dir = Directions::up;}
    if(key == Qt::Key_Down && m_dir != Directions::up)
                     {m_dir = Directions::down;}

}

void Game::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    Draw();
}

void Game::Draw()
{
    QPainter qp(this);

    if(m_inGame)
    {
        qp.setBrush(Qt::red);
        qp.drawEllipse(m_apple.x() * Dot_width,m_apple.y() * Dot_height,Dot_width,Dot_height);

      for(int i=0;i<m_dots.size();i++)
      {
          if(i==0)
          {
              qp.setBrush(Qt::red);
              qp.drawEllipse(m_dots[i].x() * Dot_width,m_dots[i].y() * Dot_height,Dot_width,Dot_height);
          }
          else
          {
              qp.setBrush(Qt::green);
              qp.drawEllipse(m_dots[i].x() * Dot_width,m_dots[i].y() * Dot_height,Dot_width,Dot_height);
          }
      }
    }
    else
    {
        gameOver();
    }
}

void Game::local_Apple()
{
    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());
    m_apple.rx() = qrand()% Dot_width;
    m_apple.ry() = qrand()% Dot_height;

}

void Game::move()
{
    for(int i = m_dots.size()-1;i>0;i--)
    {
        m_dots[i] = m_dots[i-1];
    }
    switch (m_dir)
    {
        case left:
             {m_dots[0].rx() -= 1; break;}
        case right:
             {m_dots[0].rx() += 1; break;}
        case up:
             {m_dots[0].ry() -= 1; break;}
        case down:
             {m_dots[0].ry() += 1; break;}

    }
}

void Game::check_feild()
{
    if(m_dots.size()>4)
    {
        for(int i = 1;i < m_dots.size(); i++)
        {
            if(m_dots[0]==m_dots[i])
            {

                m_inGame=false;
            }
        }
    }
    if(m_dots[0].x()>=field_width)
          {m_inGame=false;}
    if(m_dots[0].x()< 0)
          {m_inGame=false;}
    if(m_dots[0].x()>=field_height)
          {m_inGame=false;}
    if(m_dots[0].x()<0)
          {m_inGame=false;}
    if(!m_inGame)
    {
        killTimer(m_timerId);
    }
}

void Game::gameOver()
{
    QMessageBox msgb1;
    msgb1.setText("Game Over");
    msgb1.exec();
    initGame();
}

void Game::check_apple()
{
    if(m_apple==m_dots[0])
    {
        m_dots.push_back(QPoint(0,0));
        local_Apple();
    }
}

void Game::initGame()//*
{
    m_inGame=true;
    m_dir =right;
    m_dots.resize(2);
    for(int i=0;i<m_dots.size();i++)
    {
        m_dots[i].rx()= m_dots.size()-i-1 ;
        m_dots[i].ry() = 0;

    }
    local_Apple();
    m_timerId =startTimer(DELAY);
}
Game::~Game()
{

}
