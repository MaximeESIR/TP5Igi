#include <QApplication>

#include <ihm/MainWindow.h>

int main(int argc, char * argv [])
{
	int res;
	QApplication app(argc,argv);
	
	//affichage main window
	MainWindow mw;
	mw.show();

	//demarrage boucle d'evenements
	res = app.exec();

	return res;
}
