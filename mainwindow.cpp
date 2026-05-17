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

    // Left panel
    leftPanel = new QWidget();
    leftLayout = new QVBoxLayout(leftPanel);
    notesList = new QListWidget();
    leftLayout->addWidget(notesList);
    mainLayout->addWidget(leftPanel,1);

    // Right panel
    QWidget *rightPanel = new QWidget();
    QVBoxLayout *rightLayout = new QVBoxLayout(rightPanel);
    notesEditor = new QTextEdit();
    notesEditor->setPlaceholderText("Write your notes...");
    rightLayout->addWidget(notesEditor);
    mainLayout->addWidget(rightPanel);

    // Save button
    saveButton = new QPushButton("Save");
    saveButton->setStyleSheet("max-width:150px");
    rightLayout->addWidget(saveButton);
    mainLayout->addWidget(rightPanel, 2);

    connect(saveButton, &QPushButton::clicked,this, &MainWindow::saveCurrentNote);

    this->setCentralWidget(centralWidget);
}

void MainWindow::saveCurrentNote() {
    QString noteTitle = notesEditor->toPlainText().left(30).trimmed();

    if(noteTitle.isEmpty()) {
        QMessageBox::warning(this, "Error","Note cannot be empty");
        return;
    }

    notes[noteTitle] = notesEditor->toPlainText();
    notesList->addItem(noteTitle);
    notesEditor->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}
