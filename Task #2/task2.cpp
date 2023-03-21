#include <iostream>
#include <string>

using namespace std;

class Directory {
public:
    string name;
    Directory *parent;
    Directory *nextSibling;
    Directory *firstChild;
    bool isFile;
    int dirCount;
    int countFiles;

    Directory(string name, bool isFile) {
        this->name = name;
        this->isFile = isFile;
        this->parent = NULL;
        this->nextSibling = NULL;
        this->firstChild = NULL;
        this ->dirCount = 0;
        this ->countFiles = 0;
    }
};

Directory *createDirectory(string name, bool isFile) {
    Directory *directory = new Directory(name, isFile);
    return directory;
}

void addDirectory(Directory *parent, Directory *child) {
    if (parent == NULL || child == NULL) {
        return;
    }

    child->parent = parent;

    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    }
    else {
        Directory *current = parent->firstChild;
        while (current->nextSibling != NULL) {
            current = current->nextSibling;
        }
        current->nextSibling = child;
    }

    if (child->isFile) {
        parent -> countFiles++;
    }
    else {
        parent -> dirCount++;
    }
}

void printDirectory(Directory *directory, int level) {
    for (int i = 0; i < level; i++) {
        cout << "\t";
    }

    if (directory->isFile) {
        cout << "(f)" << directory->name << endl;
    }
    else {
        cout << "(D)" << directory->name << " (Number of directories: " << directory -> dirCount << ", number of files: " << directory -> countFiles << ")" << endl;

        Directory *current = directory->firstChild;
        while (current != NULL) {
            printDirectory(current, level + 1);
            current = current->nextSibling;
        }
    }
}

int main() {
    Directory *root = createDirectory("root", false);
    Directory *dir1 = createDirectory("dir1", false);
    Directory *dir2 = createDirectory("dir2", false);
    Directory *file1 = createDirectory("file1", true);
    Directory *file2 = createDirectory("file2", true);
    Directory *file3 = createDirectory("file3", true);
    Directory *file4 = createDirectory("file4", true);

    addDirectory(root, dir1);
    addDirectory(root, dir2);
    addDirectory(root, file1);

    addDirectory(dir1, file2);
    addDirectory(dir2, file3);

    addDirectory(dir2, file4);

    printDirectory(root, 0);

    return 0;
}
