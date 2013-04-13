#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H
#include <QWidget>

class QLabel;
class QScrollArea;
class QScrollBar;
class QString;
class QImage;

class ImageViewer : public QWidget
{
	Q_OBJECT
	
	public:
		ImageViewer(const QImage &, QWidget *parent=0);
	
	private:
		QLabel *imageLabel;
		QScrollArea *scrollArea;
		double scaleFactor;
};
#endif