#include <QApplication>
#include "headers/MainWindow.h"

using namespace std;

int main(int argc, char * argv[])	{
	QApplication app(argc, argv);
	MainWindow main;
	main.show();
	return app.exec();
}