#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>
#include <QString>
#include <QPixmap>
#include <QFileDialog>
#include <QImage>
#include <QPalette>
#include <QSizePolicy>

#include "ImageViewer.h"

ImageViewer::ImageViewer(const QImage &image, QWidget *parent):QWidget(parent)
{
	imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);    
		
	imageLabel->setPixmap(QPixmap::fromImage(image));
    scaleFactor = 1.0;
	
	QVBoxLayout *imageViewerLayout = new QVBoxLayout;
	imageViewerLayout->addWidget(imageLabel);
	setLayout(imageViewerLayout);
}