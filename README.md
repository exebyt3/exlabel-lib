## Overview

With this library, you can easily retrieve values from labels (keys) in a configuration file.

### Example

Suppose you have a configuration file with the following content:

```cfg
LABEL=text
LABEL2=text2
LABEL3=text3
```

To get the value `text2` from `LABEL2`, you would typically need to write the logic to extract this value yourself. However, with this library, it becomes much simpler!

### Usage

To extract `text2` from `LABEL2` in the example above, you can use the function:

```cpp
Exlabel::findAndExtract(std::string label, std::string keyword, char separator, bool takeSeparator);
```

- `std::string label`: The text or configuration from which you want to find and extract the value associated with the label (key).
- `std::string keyword`: The name of the label (key) from which you want to extract the value.
- `char separator`: The character that separates the label from its value (in the example, it is `=`).
- `bool takeSeparator`: A boolean that determines whether to include the separator with the value:
  - `0` - output will be `text2`
  - `1` - output will be `=text2`

Additionally, if you need to retrieve all values from all labels (keys), you can use:

```cpp
Exlabel::extractLabel(std::string label, char separator, bool takeSeparator);
```

Then the output you get is:
```cfg
text
text2
text3
```

### Instalation

To import the library into your Visual Studio project, follow these steps:



0. **Building the library or download**:
   - Build .lib yourself or download [Release](https://github.com/exebyt3/exlabel-lib/releases). 

2. **Open Project Properties**:
   - Go to the Visual Studio project where you want to import the library.

3. **Set Additional Include Directories**:
   - Navigate to **Project Properties** -> **C/C++** -> **General**.
   - In the **Additional Include Directories** field, enter the path to the library's `.h` file without specifying the file itself.  
     [+] **Correct:** `C:\Desktop\exlabel\include\`  
     [-] **Incorrect:** `C:\Desktop\exlabel\include\exlabel.h`

4. **Set Additional Library Directories**:
   - Go to **Linker** -> **General**.
   - In the **Additional Library Directories** field, enter the path to the library's `.lib` file without specifying the file itself.

5. **Set Additional Dependencies**:
   - Navigate to **Linker** -> **Input**.
   - In the **Additional Dependencies** field, enter `exlabel.lib`.

6. **Include the Library in Your Project**:
   - Finally, include the `.h` file of the library in your project with the following directive:
     ```cpp
     #include "exlabel.h"
     ```

### Community

If you have any ideas for this project, feel free to post them in [Issues](https://github.com/exebyt3/exlabel-lib/issues)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
