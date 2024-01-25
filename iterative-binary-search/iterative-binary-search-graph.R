install.packages("ggplot2")
library(ggplot2)
data <- data.frame(
  NumberOfElements = c(5, 5, 1, 2, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 1250, 1500, 1500, 1750, 2000, 2500, 5000, 7500, 9000, 10000),
  Iterations = c(3, 3, 1, 2, 4, 5, 6, 7, 7, 8, 9, 9, 9, 10, 10, 11, 11, 11, 11, 11, 12, 12, 13, 14, 14)
)

ggplot(data, aes(x = NumberOfElements, y = Iterations)) +
  geom_line() +
  labs(title = "Number of Elements vs. Iterations",
       x = "Number of Elements",
       y = "Iterations")
