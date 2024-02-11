if (!requireNamespace("ggpubr", quietly = TRUE)) {
  install.packages("ggpubr")
}

library(ggpubr)

data <- data.frame(
  elements = c(0, seq(10,  150, by =  10)),
  iterations = c(0, seq(9,  149, by =  9))
)

ggscatter(data, x = "elements", y = "iterations",
          xlab = "Number of Elements", ylab = "Iterations",
          title = "Scatter Plot of Number of Elements vs Iterations")
