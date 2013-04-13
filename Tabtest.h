#ifndef TABTEST_H
#define TABTEST_H
#include <QWidget>
#include <QDirModel>

class QTabWidget;
class QPushButton;
class QLabel;
class QString;
class QTextStream;

class Tabtest:public QWidget
{
	Q_OBJECT
	
public:
	Tabtest(QWidget *parent=0);
	
public slots:
	void AddingTab();
	void openPictureTab();
	void openDirViewTab(const QModelIndex&, QDirModel *);
	
private:
	QTabWidget *tabWidget;
	QPushButton *Button;
	int TabNum;
};

class Nothing:public QWidget
{
	Q_OBJECT

public:
	Nothing(QWidget *parent=0);
	
};

#endif