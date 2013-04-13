#ifndef DIRVIEW_H
#define DIRVIEW_H
#include <QWidget>
#include <QDockWidget>
#include <QDirModel>
#include <QTreeView>
#include <QtGui>

class dirView : public QDockWidget{
	Q_OBJECT

public:
	dirView(QWidget *parent=0, Qt::WFlags flags = 0);
	
signals:
	void fileClicked(const QModelIndex&, QDirModel*);
	
public slots:
	void treeClicked(const QModelIndex&);

private:
	QDirModel *model;
	QTreeView *tree;
};
#endif