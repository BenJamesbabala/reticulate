% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/python.R
\name{import}
\alias{import}
\title{Import a Python module}
\usage{
import(module)
}
\arguments{
\item{module}{Module namex}
}
\value{
A Python module
}
\description{
Import the specified Python module for calling from R. Use \code{"__main__"}
to import the main module.
}
\examples{
\dontrun{
main <- import("__main__")
sys <- import("sys")
}

}
