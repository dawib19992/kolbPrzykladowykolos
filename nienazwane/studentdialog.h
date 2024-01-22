// studentdialog.h
#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

class StudentDialog : public QDialog
{
    Q_OBJECT

public:
    StudentDialog(QWidget *parent = nullptr);

    QString getFirstName() const;
    QString getLastName() const;
    int getSubject1Grade() const;
    int getSubject2Grade() const;

private:
    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *subject1GradeLineEdit;
    QLineEdit *subject2GradeLineEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUI();
};

#endif // STUDENTDIALOG_H
