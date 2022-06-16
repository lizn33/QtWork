//
// Created by ccx on 22-6-15.
//

#ifndef QTWORK_CHATWINDOW_H
#define QTWORK_CHATWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>


class ChatWindow : public QWidget {
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);

private:

    QLineEdit qLineEdit;

    QVBoxLayout qvBoxLayout;
    QHBoxLayout qhBoxLayout;
    QPushButton qPushButton;

};


#endif //QTWORK_CHATWINDOW_H
