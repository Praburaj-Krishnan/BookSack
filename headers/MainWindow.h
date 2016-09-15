#ifndef MAINWIDNOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
class TrieHandler;

class MainWindow : public QMainWindow, public Ui::MainWindow {
private:
	Q_OBJECT
	//These are the private member functions that are needed.
	void update_Category();
	void update_Database();
	//There are some of the private data members that are needed.
	int categoryCount;	
	int pathCount;
	QHash <QString , int> categoryHash;
	TrieHandler ** THandlers;
private slots:
	void on_textInput_textChanged();
	//void on_actAddPdf_triggered();
	void on_actAddPath_triggered();
	//void on_actRemovePath_triggered();
public:
	MainWindow();
signals:
	//These are some custom signals for handling exceptions
	void callAddPath();
};

#endif 