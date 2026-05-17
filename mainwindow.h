#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QVBoxLayout>
#include<QListWidget>
#include<QTextEdit>
#include<QPushButton>
#include<QHBoxLayout>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QListWidget *notesList;
    QTextEdit *notesEditor;
    QPushButton *saveButton;
    QWidget *leftPanel;
    QVBoxLayout *leftLayout;
    QMap<QString, QString> notes;

private slots:
    void saveCurrentNote();

};
#endif // MAINWINDOW_H
