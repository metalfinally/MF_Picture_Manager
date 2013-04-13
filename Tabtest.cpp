#include "Tabtest.h"
#include "ImageViewer.h"
#include "FileViewer.h"
#include <QTabWidget>
#include <QPushButton>
#include <QLabel>
#include <QtGui>
#include <QTextStream>
#include <QString>
#include <QFileDialog>
#include <QImage>
#include <QMessageBox>
#include <QDirModel>
#include <QListView>

Tabtest::Tabtest(QWidget *parent):QWidget(parent)
{
	tabWidget=new QTabWidget;
	tabWidget->addTab(new Nothing(), tr("TestTab"));
	
	TabNum=0;
	
	Button=new QPushButton("Add");
	connect(Button, SIGNAL(clicked()), this, SLOT(AddingTab()));
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(Button);
    setLayout(mainLayout);

}

void Tabtest::AddingTab()
{
	TabNum++;
	QString result;
	QTextStream(&result)<<"TabTest_"<<TabNum;
	tabWidget->addTab(new Nothing(), result);
}

void Tabtest::openPictureTab()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Images (*.png  *.jpg)"));
    if (!fileName.isEmpty()) {
        QImage image(fileName);
        if (image.isNull()) {
            QMessageBox::information(this, tr("Image Viewer"), tr("Cannot load %1.").arg(fileName));
            return;
        }
		tabWidget->addTab(new ImageViewer(image), fileName);
    }
}

void Tabtest::openDirViewTab(const QModelIndex& DirIndex, QDirModel* DirM)
{
	tabWidget->addTab(new FileViewer(DirIndex, DirM), tr("file"));
}

Nothing::Nothing(QWidget *parent):QWidget(parent)
{
	static int NtabNum=0;
	QString str;
	str = QString("Tab Test %1").arg(NtabNum, 0, 10);
	QLabel *label=new QLabel(str);
	QVBoxLayout *nothingLayout = new QVBoxLayout;
	nothingLayout->addWidget(label);
	setLayout(nothingLayout);
	
	NtabNum++;
}