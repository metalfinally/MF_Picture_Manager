#ifndef FILEVIEWER_H
#define FILEVIEWER_H
#include <QWidget>
#include <QDirModel>
#include <QListView>
#include <QVBoxLayout>

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