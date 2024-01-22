#include "studentdialog.h"

StudentDialog::StudentDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
}

void StudentDialog::setupUI()
{
    firstNameLineEdit = new QLineEdit(this);
    lastNameLineEdit = new QLineEdit(this);
    subject1GradeLineEdit = new QLineEdit(this);
    subject2GradeLineEdit = new QLineEdit(this);
    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("Cancel", this);

    QFormLayout *layout = new QFormLayout(this);
    layout->addRow("First Name:", firstNameLineEdit);
    layout->addRow("Last Name:", lastNameLineEdit);
    layout->addRow("Subject 1 Grade:", subject1GradeLineEdit);
    layout->addRow("Subject 2 Grade:", subject2GradeLineEdit);
    layout->addRow(okButton, cancelButton);

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    setLayout(layout);
}

QString StudentDialog::getFirstName() const
{
    return firstNameLineEdit->text();
}

QString StudentDialog::getLastName() const
{
    return lastNameLineEdit->text();
}

int StudentDialog::getSubject1Grade() const
{
    return subject1GradeLineEdit->text().toInt();
}

int StudentDialog::getSubject2Grade() const
{
    return subject2GradeLineEdit->text().toInt();
}
