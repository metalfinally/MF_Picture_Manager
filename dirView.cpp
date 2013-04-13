#include <QWidget>
#include <QtGui>

#include "dirView.h"
#include <QCoreApplication>

dirView::dirView(QWidget *parent, Qt::WFlags flags):QDockWidget(parent, flags)
{

	model = new QDirModel;
	tree = new QTreeView;
	tree->setModel(model);

	tree->setAnimated(false);
	tree->setIndentation(20);
	tree->setSortingEnabled(true);
	
	setWidget(tree);
	
	connect(tree, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(treeClicked(const QModelIndex &)));
	
	setWindowTitle(tr("Dir View"));
}

void dirView::treeClicked(const QModelIndex & treeIndex){
	emit fileClicked(treeIndex, model);
}