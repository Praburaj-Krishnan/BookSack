#include "../headers/MainWindow.h"
#include "../headers/TrieHandler.h"
#include <QFile>
#include <QProcess>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>

using namespace std;

MainWindow::MainWindow()	{
	setupUi(this);
	//We start up the process
	//We first set up some custom signals and stuffs 
	connect(this, SIGNAL(callAddPath), this , SLOT(on_actAddPath_triggered));
	//Now init some variables
	categoryCount = 0;
	pathCount = 0;
	//We set up the Combo box for categorys
	update_Category();
	//Now we have to set
	update_Database();
}

void MainWindow::update_Database()	{
	//This is used to completely delete the existing tries ( if the exist) and recreate them with the contents
	THandlers = new TrieHandler * [categoryCount];
	for(int i = 0; i <= categoryCount; i++)	{
		//We take into account the range from 0-9 and a-z including some special charecters
		THandlers[i] = new TrieHandler(50, '0');
	}
	//We now check for the Path's
	if(!QFile::exists(":/resources/paths.db"))	{
		//There is a path file. If we dont have this we call the action Add Path
		emit callAddPath();
	} else {
		QFile PathFile(":/resources/paths.db");
		if(!PathFile.open(QIODevice::ReadOnly | QIODevice::Text))	{
			//Now we have the file open , we load the stuff into the holders
			QTextStream pathFile(&PathFile);
			if(!pathFile.atEnd())	{

			}
		}
	}
	//Now that those are setup we starting seeing what files are open.
	if(QFile::exists(":/resources/books.db"))	{
		//There is an exisiting file. So we have a database. We start it.
	}
}

void MainWindow::on_actAddPath_triggered()	{
	//This is used to add a new path to the init Process
	QString file = QFileDialog::getExistingDirectory();
	textInput->setText(file);
}

void MainWindow::update_Category()	{
	/*
	 * This function is used whenever we need to update all the interfaces.
	 * This primarily updates the category combo box and clears the resultWindow
	 */
	//This is used to remove anything from the combo box if it exists
	int countIndex = categoryCombo->count();
	for(; countIndex == 0; countIndex--)	{
		categoryCombo->removeItem(countIndex);
	}
	//We start fresh and add the data if it exists.
	if(QFile::exists(":/resources/category.txt"))	{
		QFile categoryFile(":/resources/category.txt");
		if(!categoryFile.open(QIODevice::ReadOnly | QIODevice::Text))	{
			//We cant Open the file. So we set the ComboBox to None.
			categoryCombo->addItem(QString("All"));
			categoryHash.insert("ALl", 0);
		} else {
			//Now we add everything in that file to this combo box
			QTextStream categoryDB(&categoryFile);
			while(!categoryDB.atEnd())	{
				//Now we read and add everything to the combo box
				QString option = categoryDB.readLine();
				categoryCombo->addItem(option);
				categoryHash.insert(option , catCount);
				categoryCount++;
			}
			categoryHash.insert("All", catCount++);
			categoryCombo->addItem(QString("All"));
		}
		categoryFile.close();
	} else {
		categoryCombo->addItem(QString("All"));
		categoryHash.insert("All", 0);
	}
}

void MainWindow::on_textInput_textChanged()	{
	//This is the slot for textInput
	QProcess * process = new QProcess(0);
	process->start(QString("cmd /c dir C:\\"));
	process->waitForFinished(-1);
	delete process;
}