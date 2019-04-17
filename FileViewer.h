#ifndef FILEVIEWER_H
#define FILEVIEWER_H

#include <QtWidgets>

class FileViewer : public QWidget
{
	Q_OBJECT
	
	public:
		FileViewer(const QModelIndex&, QDirModel *,QWidget *parent=0);
	
	private:
		QDirModel *treeModel;
		QListView *list;
};
#endif