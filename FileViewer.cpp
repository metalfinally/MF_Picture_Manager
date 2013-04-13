#include "FileViewer.h"

FileViewer::FileViewer(const QModelIndex& DirIndex, QDirModel *DirMf, QWidget *parent):QWidget(parent)
{
	treeModel = DirMf;
	list = new QListView;
	list->setModel(treeModel);
    list->setRootIndex(DirIndex);
	
	QVBoxLayout *FileViewerLayout = new QVBoxLayout;
	FileViewerLayout->addWidget(list);
	setLayout(FileViewerLayout);
	
	list->show();
}