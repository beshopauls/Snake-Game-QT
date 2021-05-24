#include <QApplication>
#include<game.h>
using namespace std;

int main(int argc,char* argv[])
{
  QApplication app(argc,argv);

    Game game;
    game.show();
    return app.exec();
}
