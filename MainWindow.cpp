#include <QtWidgets>

#include "MainWindow.h"
#include "Tabtest.h"
#include "dirView.h"

MainWindow::MainWindow()
{
	innerTab = new Tabtest();
	dirExplorer = new dirView();
	
    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
	createDockWindows();
	
	setCentralWidget(innerTab);
	
	setWindowTitle(tr("Add Image Tab Test"));
	
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> is a test to add tab image."
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}

void MainWindow::createActions()
{
	aboutAct = new QAction(tr("&About"), this);
	aboutAct->setShortcut(tr("Ctrl+A"));
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
	
	exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
	
	openImageAct = new QAction(tr("&Open"), this);
	openImageAct->setShortcut(tr("Ctrl+O"));
	openImageAct->setStatusTip(tr("Open Image in the Tab"));
	connect(openImageAct, SIGNAL(triggered()), innerTab, SLOT(openPictureTab()));
	
}

void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(openImageAct);
	fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
	
	viewMenu = menuBar()->addMenu(tr("&View"));
	
	aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutAct);

}

void MainWindow::createToolBars()
{	
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createDockWindows()
{
	QDockWidget *dock = new QDockWidget(tr("Dir View"));
	dock->setAllowedAreas(Qt::LeftDockWidgetArea);
	addDockWidget(Qt::LeftDockWidgetArea, dirExplorer);
	viewMenu->addAction(dock->toggleViewAction());
	connect(dirExplorer, SIGNAL(fileClicked(const QModelIndex&, QDirModel*)), innerTab, SLOT(openDirViewTab(const QModelIndex&, QDirModel*)));
}