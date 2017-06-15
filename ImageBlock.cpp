#include "ImageBlock.h"
#include <QVBoxLayout>
#include <QPalette>
#include <QDebug>

ImageBlock::ImageBlock(QWidget* parent)
    :QGroupBox(parent)
{
    init();
}

ImageBlock::ImageBlock(const QString& title, QWidget* parent)
    :QGroupBox(title, parent)
{
    init();
}

QLabel *ImageBlock::image()
{
    return image_;
}

ScrollText *ImageBlock::title()
{
    return title_;
}

void ImageBlock::setTitle(const QString& title){
    title_->setText(title);
}

void ImageBlock::setImage(const QString& path){
    image_->setPixmap(QPixmap(path));
}

void ImageBlock::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
    QGroupBox::mouseReleaseEvent(event);
    qDebug() << "clicked.";
}

void ImageBlock::init(){
    title_ = new ScrollText();
    image_ = new QLabel();

    setImage(":/buttons/musical-note.svg");
    setTitle("Title");
//    title_->setAlignment(Qt::AlignCenter);

    QVBoxLayout* grid = new QVBoxLayout();
    grid->addWidget(image_);
    grid->addWidget(title_);
    title_->setFixedWidth(100);
    title_->setStyleSheet("border-color:white; color:blue;");
    grid->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(grid);
}
