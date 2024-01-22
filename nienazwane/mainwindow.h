#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void calculateAverages();
    void addStudent();

private:
    QListWidget *studentsListWidget;
    QLabel *schoolLogoLabel;
    QPushButton *calculateButton;
    QPushButton *addStudentButton;

    void setupUI();
    void sortStudentsList();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
