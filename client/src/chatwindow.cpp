//
// Created by ccx on 22-6-15.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChatWindow.h" resolved

#include "chatwindow.h"


ChatWindow::ChatWindow(QWidget *parent) :
        QWidget(parent) {
    qvBoxLayout.addWidget(&qLineEdit);
    qvBoxLayout.addLayout(&qhBoxLayout);
    qhBoxLayout.addWidget(&qPushButton);
    this->setLayout(&qvBoxLayout);
//    ui->setLayout(&qvBoxLayout);

}
