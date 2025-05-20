#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
using namespace std;

#define BUFFER_SIZE 1024

void createFile(const string &filename) {
    int fd = open(filename.c_str(), O_CREAT | O_WRONLY, 0644);
    if (fd != -1) {
        cout << "File created successfully." << endl;
        close(fd);
    } else {
        perror("Error creating file");
    }
}

void writeFile(const string &filename, const string &data) {
    int fd = open(filename.c_str(), O_WRONLY | O_TRUNC);
    if (fd != -1) {
        write(fd, data.c_str(), data.length());
        cout << "Data written successfully." << endl;
        close(fd);
    } else {
        perror("Error writing file");
    }
}

void copyFile(const string &source, const string &dest) {
    int srcfd = open(source.c_str(), O_RDONLY);
    int destfd = open(dest.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (srcfd != -1 && destfd != -1) {
        char buffer[BUFFER_SIZE];
        ssize_t bytes;
        while ((bytes = read(srcfd, buffer, sizeof(buffer))) > 0) {
            write(destfd, buffer, bytes);
        }
        cout << "File copied successfully." << endl;
        close(srcfd);
        close(destfd);
    } else {
        perror("Error copying file");
    }
}

void moveFile(const string &source, const string &dest) {
    copyFile(source, dest);
    if (remove(source.c_str()) == 0) {
        cout << "File moved successfully." << endl;
    } else {
        perror("Error moving file");
    }
}

void deleteFile(const string &filename) {
    if (remove(filename.c_str()) == 0) {
        cout << "File deleted successfully." << endl;
    } else {
        perror("Error deleting file");
    }
}

int main() {
    int choice = 1;
    string filename, destfile, data;

    while (choice) {
        cout << "\nChoose an option:\n";
        cout << "1. Create File\n";
        cout << "2. Write File\n";
        cout << "3. Copy File\n";
        cout << "4. Move File\n";
        cout << "5. Delete File\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // clear newline

        switch (choice) {
            case 1:
                cout << "Enter filename: ";
                getline(cin, filename);
                createFile(filename);
                break;
            case 2:
                cout << "Enter filename: ";
                getline(cin, filename);
                cout << "Enter data to write: ";
                getline(cin, data);
                writeFile(filename, data);
                break;
            case 3:
                cout << "Enter source filename: ";
                getline(cin, filename);
                cout << "Enter destination filename: ";
                getline(cin, destfile);
                copyFile(filename, destfile);
                break;
            case 4:
                cout << "Enter source filename: ";
                getline(cin, filename);
                cout << "Enter destination filename: ";
                getline(cin, destfile);
                moveFile(filename, destfile);
                break;
            case 5:
                cout << "Enter filename to delete: ";
                getline(cin, filename);
                deleteFile(filename);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
