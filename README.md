R Interface to Python
================

The **rpy** package provides an R interface to Python modules, classes, and functions. For example, this code imports the Python `os` module and calls some functions within it:

``` r
library(rpy)
os <- import("os")
os$chdir("tests")
os$getcwd()
```

When calling into Python R data types are automatically converted to their equivalent Python types. When values are returned from Python to R they are converted back to R types.

| R                      | Python            | Examples                                    |
|------------------------|-------------------|---------------------------------------------|
| Single-element vector  | Scalar            | `1`, `1L`, `TRUE`, `"foo"`                  |
| Multi-element vector   | List              | `c(1.0, 2.0, 3.0)`, `c(1L, 2L, 3L)`         |
| List of multiple types | Tuple             | `list(1L, TRUE, "foo")`                     |
| Named list             | Dict              | `list(a = 1L, b = 2.0)`, `dict(x = x_data)` |
| Matrix/Array           | NumPy ndarray     | `matrix(c(1,2,3,4), nrow = 2, ncol = 2)`    |
| Dunction               | Python function   | `function(x) x + 1`                         |
| NULL, TRUE, FALSE      | None, True, False | `NULL`, `TRUE`, `FALSE`                     |

If a Python object of a custom class is returned then an R reference to that object is returned. You can call methods and access properites of the object just as if it was an instance of an R reference class.

Installation
------------

You can install the **rpy** package from GitHub as follows:

``` r
devtools::install_github("rstudio/rpy")
```

Note that the **rpy** package includes native C/C++ code so it's installation requires [R Tools](https://cran.r-project.org/bin/windows/Rtools/) on Windows and [Command Line Tools](http://osxdaily.com/2014/02/12/install-command-line-tools-mac-os-x/) on OS X. If the package installation fails because of inability to compile then install the appropriate tools for your platform based on the links above and try again.

### Locating Python

When it is loaded the **rpy** package scans the system for a compatible version of Python. If automatic detection doesn't work or if you want to exercise more control over which version of python is used you can specify an explicit `RPY_PYTHON` environment variable, for example:

``` r
Sys.setenv(RPY_PYTHON="/usr/local/bin/python")
library(rpy)
```

The **rpy** package will look in this location first, then look for python on the system `PATH`, then scan additional locations where python is conventionally installed (e.g. `/usr/local/bin`, `/opt/python/bin`, etc.).

You can use the `py_config` function to query for information about the specific version of Python in use as well as a list of other Python versions discovered on the system:

``` r
library(rpy)
py_config()
```

Lists, Tuples, and Dictionaries
-------------------------------

The automatic conversion of R types to Python types works well in most cases, but occationally you will need to be more explicit on the R side to provide Python the type(s) it expects.

For example, if a Python API requires a list and you pass a single element vector it will be converted to a Python scalar. To overcome this simply use the R `list` function explicitly:

``` r
foo$bar(indexes = list(42L))
```

Similarly, a Python API might require a `tuple` rather than a list. In that case you can use the `tuple` function:

``` r
tuple("a", "b", "c")
```

R named lists are converted to Python dictionaries however you can also explicitly create a Python dictionary using the `dict` function:

``` r
dict(foo = "bar", index = 42L)
```

This might be useful if you need to pass a dictionary that uses a more complex object (as opposed to a string) as it's key.

With Contexts
-------------

Iterators
---------

Running Code
------------

Advanced Functions
------------------
