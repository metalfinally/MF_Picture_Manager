#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Tabtest.h"
#include "dirView.h"

class QAction;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
	
private slots:
    void about();

private:
	void createActions();
    void createMenus();
	void createToolBars();
	void createStatusBar();
	void createDockWindows();
	
	QMenu *fileMenu;
	QMenu *viewMenu;
	QMenu *aboutMenu;
	QAction *exitAct;
	QAction *aboutAct;
	QAction *openImageAct;
	
	Tabtest *innerTab;
	dirView *dirExplorer;

};
#endif