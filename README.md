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
- `char separator`: The character that separates the label from its value (in the example, it is `=text2`).
- `bool takeSeparator`: A boolean that determines whether to include the separator with the value:
  - `0` - output will be `text2`
  - `1` - output will be `=text2`

Additionally, if you need to retrieve all values from all labels (keys), you can use:

```cpp
Exlabel::extractLabel(std::string label, char separator, bool takeSeparator);
```
