#include "database.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
void init() {
    // Set the SQLite database name
    QString dbName = "passwords.db";

    // Initialize the database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);

    // Check if the database file already exists
    if (!QFile(dbName).exists()) {
        // If the database file doesn't exist, create it

        // Open the database
        if (db.open()) {
            qDebug() << "Connected to the database.";

            // Create a QSqlQuery object to execute SQL commands
            QSqlQuery query;

            // Execute the SQL command to create the "passwords" table
            if (query.exec("CREATE TABLE IF NOT EXISTS passwords ("
                           "id INT PRIMARY KEY,"
                           "title VARCHAR(255),"
                           "username VARCHAR(255),"
                           "password VARCHAR(255),"
                           "login_url VARCHAR(255)"
                           ")")) {
                qDebug() << "Table created successfully.";
            } else {
                qDebug() << "Error creating table: " << query.lastError().text();
            }

            // Close the database
            db.close();
            qDebug() << "Disconnected from the database.";
        } else {
            qDebug() << "Error opening database: " << db.lastError().text();
        }
    } else {
        qDebug() << "Database already exists.";
    }

    // Reopen the database
    if (db.open()) {
        qDebug() << "Connected to the database again.";

        // You can perform database operations here...

        // Close the database
        db.close();
        qDebug() << "Disconnected from the database.";
    } else {
        qDebug() << "Error opening database: " << db.lastError().text();
    }

    // Remove the database connection
    QSqlDatabase::removeDatabase(dbName);
}
