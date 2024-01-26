num_elements <- c(0, 1, 0, 2, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100)
iterations <- c(0, 1, 0, 2, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100)

plot(num_elements, iterations, type = "b", pch = 16, col = "blue",
     xlab = "Number of Elements", ylab = "Iterations",
     main = "Number of Elements vs. Iterations ")

