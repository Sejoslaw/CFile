#include <stdlib.h>

// CFile header
#include "CFile.h"

int main(int argc, char *argv[])
{
    /// Open File
    /// Create if not exists
    FILE *file = open_file("test.txt", FILE_MODE_READ_WRITE_CREATE);

    if (file != NULL)
    {
        /// Write some text to File
        char buff[255] = "Some random text which should be added to newly created File. :D";
        write_to_file_printf(file, buff);

        /// Save data to File
        /// File is still open
        save_file(file);

        /// Move cursor to beginning of File
        go_to_beginning(file);

        /// Read data from File
        char* readded;
        read_input_stream(readded, 255, file);

        /// Test if data was readded
        printf("%s\n", readded);

        /// Close File
        close_file(file);
    }
    else
    {
        perror("Error");
    }

    return 0;
}
