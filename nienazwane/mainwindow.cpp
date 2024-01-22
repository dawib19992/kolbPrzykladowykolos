#include "mainwindow.h"
#include "studentdialog.h" // Klasa do drugiego okna

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
}

void MainWindow::setupUI()
{
    studentsListWidget = new QListWidget(this);
    schoolLogoLabel = new QLabel(this);
    calculateButton = new QPushButton("Calculate Averages", this);
    addStudentButton = new QPushButton("Add Student", this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(studentsListWidget);
    mainLayout->addWidget(schoolLogoLabel);
    mainLayout->addWidget(calculateButton);
    mainLayout->addWidget(addStudentButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(calculateButton, SIGNAL(clicked()), this, SLOT(calculateAverages()));
    connect(addStudentButton, SIGNAL(clicked()), this, SLOT(addStudent()));
}

void MainWindow::calculateAverages()
{
    if (studentsListWidget->count() == 0) {
        // Brak uczniów w liście
        qDebug() << "Brak uczniów w liście.";
        return;
    }

    double sumSubject1 = 0.0;
    double sumSubject2 = 0.0;

    for (int i = 0; i < studentsListWidget->count(); ++i) {
        QListWidgetItem *item = studentsListWidget->item(i);
        QStringList studentData = item->text().split(" ");
        if (studentData.size() == 4) {
            sumSubject1 += studentData[2].toDouble();
            sumSubject2 += studentData[3].toDouble();
        }
    }

    double averageSubject1 = sumSubject1 / studentsListWidget->count();
    double averageSubject2 = sumSubject2 / studentsListWidget->count();

    // Wyświetlanie wyników
    qDebug() << "Średnia dla Subject 1: " << averageSubject1;
    qDebug() << "Średnia dla Subject 2: " << averageSubject2;
}

void MainWindow::addStudent()
{
    StudentDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // Pobieranie danych od użytkownika
        QString firstName = dialog.getFirstName();
        QString lastName = dialog.getLastName();
        int subject1Grade = dialog.getSubject1Grade();
        int subject2Grade = dialog.getSubject2Grade();

        // Sprawdzanie poprawności ocen
        if (subject1Grade < 1 || subject1Grade > 6 || subject2Grade < 1 || subject2Grade > 6) {
            // Wyświetl komunikat o błędnych ocenach
            // Możesz użyć QMessageBox lub innego mechanizmu
            qDebug() << "Błąd: Błędne oceny.";
            return;
        }

        // Dodawanie nowego ucznia do listy
        QString studentData = QString("%1 %2 %3 %4").arg(firstName, lastName, QString::number(subject1Grade), QString::number(subject2Grade));
        QListWidgetItem *newItem = new QListWidgetItem(studentData);
        studentsListWidget->addItem(newItem);

        // Automatyczne sortowanie
        sortStudentsList();
    }
}

void MainWindow::sortStudentsList()
{
    // Sortowanie listy uczniów względem nazwiska
    studentsListWidget->sortItems(Qt::AscendingOrder);
}
