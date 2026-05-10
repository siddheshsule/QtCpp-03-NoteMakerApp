#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Notes Maker");
    this->resize(800,600);

    centralWidget = new QWidget();
    mainLayout = new QVBoxLayout(centralWidget);

    this->setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
